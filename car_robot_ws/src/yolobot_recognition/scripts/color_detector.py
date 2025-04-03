#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist, Polygon, Point32
from yolov8_msgs.msg import ColorDetection, Yolov8Inference, InferenceResult
import cv2
import cv_bridge
import numpy as np

class ColorDetectionNode(Node):
    def __init__(self):
        super().__init__('color_detection')

        # Define the bounding boxes list that will be updated by the topic
        self.bounding_boxes = []  # Start with an empty list

        # Subscriber to the color image topic
        self.image_sub = self.create_subscription(
            Image,
            '/camera/realsense_camera/color/image_raw',
            self.image_callback,
            10
        )

        # Publisher to cmd_vel for movement commands
        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # Publisher for color detection results
        self.color_pub = self.create_publisher(ColorDetection, '/color_detection', 10)

         # Subscribe to the YOLOv8 inference topic for bounding box data
        self.yolov8_sub = self.create_subscription(
            Yolov8Inference,
            '/Yolov8_Inference',  # Topic where YOLOv8 inference bounding boxes are being published
            self.yolov8_inference_callback,
            10
        )


    def image_callback(self, msg):
        bridge = cv_bridge.CvBridge()

        try:
            # Convert the ROS image message to OpenCV format (BGR8)
            cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except cv_bridge.CvBridgeError as e:
            self.get_logger().error(f"CV Bridge conversion error: {e}")
            return

        # Convert the image from BGR to HSV
        hsv = cv2.cvtColor(cv_image, cv2.COLOR_BGR2HSV)

        # Define color ranges in HSV space
        yellow_lower = np.array([20, 100, 100])
        yellow_upper = np.array([30, 255, 255])
        blue_lower = np.array([100, 150, 50])
        blue_upper = np.array([140, 255, 255])
        red_lower1 = np.array([0, 120, 70])
        red_upper1 = np.array([10, 255, 255])
        red_lower2 = np.array([170, 120, 70])
        red_upper2 = np.array([180, 255, 255])

        # Create masks for each color
        mask_yellow = cv2.inRange(hsv, yellow_lower, yellow_upper)
        mask_blue = cv2.inRange(hsv, blue_lower, blue_upper)
        mask_red1 = cv2.inRange(hsv, red_lower1, red_upper1)
        mask_red2 = cv2.inRange(hsv, red_lower2, red_upper2)
        mask_red = mask_red1 + mask_red2

        # Initialize Twist message for robot movement
        twist = Twist()

        # Create a ColorDetection message
        color_msg = ColorDetection()

        # Process each bounding box
        for box in self.bounding_boxes:
            # Each bounding box is a Polygon with 4 points
            if len(box.points) != 4:
                self.get_logger().warn("Bounding box does not have 4 points.")
                continue

            # Extract bounding box coordinates from the Polygon message
            x, y = int(box.points[0].x), int(box.points[0].y)
            w = int(box.points[2].x - box.points[0].x)  # Width of the box
            h = int(box.points[2].y - box.points[0].y)  # Height of the box

            # Define Region of Interest (ROI) based on bounding box coordinates
            roi_mask_yellow = mask_yellow[y:y+h, x:x+w]
            roi_mask_blue = mask_blue[y:y+h, x:x+w]
            roi_mask_red = mask_red[y:y+h, x:x+w]

            # Find contours for the color masks inside the bounding box
            yellow_contours, _ = cv2.findContours(roi_mask_yellow, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
            blue_contours, _ = cv2.findContours(roi_mask_blue, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
            red_contours, _ = cv2.findContours(roi_mask_red, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

            # Logic to decide movement based on color detection within the bounding box
            if len(yellow_contours) > 0:
                color_msg.color_detected = "yellow"
                color_msg.detected = True
                twist.angular.z = -0.5  # Rotate counterclockwise
            elif len(blue_contours) > 0:
                color_msg.color_detected = "blue"
                color_msg.detected = True
                twist.angular.z = 0.5  # Rotate clockwise
            elif len(red_contours) >= 2:
                color_msg.color_detected = "red"
                color_msg.detected = True
                twist.linear.x = 0.2  # Move forward
            else:
                color_msg.color_detected = "none"
                color_msg.detected = False

            # Publish the color detection message to /color_detection topic
            self.color_pub.publish(color_msg)

        # Publish the Twist message to control the robot
        self.cmd_pub.publish(twist)

    def yolov8_inference_callback(self, msg):
        # Update bounding boxes from the received Yolov8Inference message
        self.bounding_boxes = []
        for inference in msg.yolov8_inference:
            # Create Polygon (bounding box) from the received inference
            polygon = Polygon()
            p1 = Point32(x=inference.left, y=inference.top)
            p2 = Point32(x=inference.right, y=inference.top)
            p3 = Point32(x=inference.right, y=inference.bottom)
            p4 = Point32(x=inference.left, y=inference.bottom)
            polygon.points = [p1, p2, p3, p4]
            self.bounding_boxes.append(polygon)
            self.get_logger().info(f"Updated bounding boxes: {self.bounding_boxes}")

def main(args=None):
    rclpy.init(args=args)
    node = ColorDetectionNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
