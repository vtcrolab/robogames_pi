#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from yolov8_msgs.msg import Yolov8Inference, InferenceResult
from sensor_msgs.msg import Image, Joy
from cv_bridge import CvBridge
from ultralytics import YOLO
import numpy as np
import cv2

bridge = CvBridge()

class ObjectTracker(Node):
    def __init__(self):
        super().__init__('object_tracker')

        # Load the YOLOv8 model for object detection
        self.model = YOLO('~/vt-cro/robogames_pi/car_robot_ws/src/yolobot_recognition/scripts/yolov8n.pt')
        self.yolov8_inference = Yolov8Inference()

        # Subscribe to the image and depth topics
        self.rgb_sub = self.create_subscription(Image, "/camera/realsense_camera/color/image_raw", self.synced_callback, 10)
        self.depth_sub = self.create_subscription(Image, "/camera/realsense_camera/depth/image_rect_raw", self.synced_callback, 10)

        # Publisher for sending movement commands
        self.joy_pub = self.create_publisher(Twist, "/joy", 10)
        self.cmd_pub = self.create_publisher(Twist, "/cmd_vel", 10)
        self.img_pub = self.create_publisher(Image, "/inference_result", 1)

        self.bounding_box = None

    def synced_callback(self, rgb_msg, depth_msg):
        rgb_image = bridge.imgmsg_to_cv2(rgb_msg, "bgr8")

        # depth_image = bridge.imgmsg_to_cv2(depth_msg, desired_encoding="passthrough")

        self.get_logger().info(f"Received depth message type: {type(depth_msg)}")
        try:
            depth_image = bridge.imgmsg_to_cv2(depth_msg, desired_encoding="passthrough")
        except Exception as e:
            self.get_logger().error(f"Error converting depth message: {e}")
            return

        results = self.model(rgb_image)
        twist = Twist()
        joy_msg = Joy()
        joy_msg.buttons = [0.0] * 15
        joy_msg.axes = [0.0] * 8  # Initialize axes array (8 elements for axes[0] to axes[9])

        # Process inference results
        self.yolov8_inference.header.frame_id = "inference"
        self.yolov8_inference.header.stamp = self.get_clock().now().to_msg()

        # Look for the 'backpack' class
        for r in results:
            boxes = r.boxes
            for box in boxes:
                b = box.xyxy[0].to('cpu').detach().numpy().copy()  # Bounding box coordinates
                c = box.cls
                class_name = self.model.names[int(c)]
            
                x1, y1, x2, y2 = map(int, b)
                mid_x, mid_y = (x1 + x2) // 2, (y1 + y2) // 2
                self.bounding_box = (x1, y1, x2, y2, mid_x, mid_y)

                # Get the depth at the center of the bounding box
                depth = self.get_depth_at_center(depth_image, mid_x, mid_y)

                # Align the robot if the object is not in the center
                self.align_to_object(mid_x, rgb_image.shape[1])

                # Check distance and perform actions based on depth
                if depth < 1.0:
                    # Initiate turn (1 meter)
                    if class_name == "backpack":
                        self.initiate_turn(direction="left")
                    elif class_name == "book":
                        self.initiate_turn(direction="right")  # Hardcoded turn direction
                elif depth < 2.0:
                    # Slow down (2 meters)
                    twist.linear.x = 0.05
                    # joy_msg.buttons[7] = 0 # RT increases speed
                    for i in range(6):  #random
                        joy_msg.buttons[6] = 1 # LT decreases speed
                else:
                    joy_msg.buttons[4] # Y for Forward
                    twist.linear.x = 0.2  # Move forward normally

                break  # Stop after finding the object

        # Publish movement command
        self.cmd_pub.publish(twist)
        self.joy_pub.publish(joy_msg)

        # Annotate the image with bounding box and class name
        if self.bounding_box:
            self.annotate_image(rgb_image)
            img_msg = bridge.cv2_to_imgmsg(rgb_image)
            self.publish_annotated_image(img_msg)

    def get_depth_at_center(self, depth_image, mid_x, mid_y):
        # Ensure the center of the bounding box is within the depth image
        if 0 <= mid_y < depth_image.shape[0] and 0 <= mid_x < depth_image.shape[1]:
            return float(depth_image[mid_y, mid_x])  # Depth in meters
        else:
            return -1.0  # Invalid depth

    def align_to_object(self, mid_x, image_width):
        joy_msg = Joy()
        joy_msg.buttons = [0.0] * 15
        joy_msg.axes = [0.0] * 8  # Initialize axes array (8 elements for axes[0] to axes[9])

        image_center_x = image_width // 2
        if mid_x < image_center_x - 50:
            # Object is left of center, rotate right (clockwise)
            twist = Twist()
            twist.angular.z = 0.5
            self.cmd_pub.publish(twist)
            joy_msg.axes[0] = -0.6  #Left (+1) to Right (-1)
        elif mid_x > image_center_x + 50:
            # Object is right of center, rotate left (counterclockwise)
            twist = Twist()
            twist.angular.z = -0.5
            self.cmd_pub.publish(twist)
            joy_msg.axes[0] = 0.6  #Left (+1) to Right (-1)
        else:
            # Object is centered
            twist = Twist()
            twist.angular.z = 0.0
            self.cmd_pub.publish(twist)
            joy_msg.axes[0] = 0  #Left (+1) to Right (-1)
        
        self.joy_pub.publish(joy_msg)

    def initiate_turn(self, direction):
        # Hardcoded turn function to turn around the object
        twist = Twist()
        joy_msg = Joy()
        joy_msg.buttons = [0.0] * 15
        joy_msg.axes = [0.0] * 8  # Initialize axes array (8 elements for axes[0] to axes[9])

        if direction == "right":
            # Perform 270-degree turn to the right
            twist.angular.z = -0.5  # Right turn
            joy_msg.axes[4] = -1.0  # R2 pressed fully (drift right)
            joy_msg.axes[5] = 0.0   # L2 is not pressed (no drift left)
            self.get_logger().info("Performing 270-degree turn to the right")
        elif direction == "left":
            # Perform 270-degree turn to the left
            twist.angular.z = 0.5  # Left turn
            joy_msg.axes[5] = -1.0  # L2 pressed fully (drift left)
            joy_msg.axes[4] = 0.0   # R2 is not pressed (no drift right)
            self.get_logger().info("Performing 270-degree turn to the left")
        
        self.joy_pub.publish()
        self.cmd_pub.publish(twist)

    def annotate_image(self, image):
        # Annotate the image with bounding box and class name
        if self.bounding_box:
            x1, y1, x2, y2, _, _ = self.bounding_box
            cv2.rectangle(image, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.putText(image, "Backpack", (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 255, 0), 2)

    def publish_annotated_image(self, img_msg):
        # Publish the annotated image
        self.img_pub.publish(img_msg)
        

def main(args=None):
    rclpy.init(args=args)
    node = ObjectTracker()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
