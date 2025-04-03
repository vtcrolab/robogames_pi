#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, Twist
from yolov8_msgs.msg import Yolov8Inference, InferenceResult
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from ultralytics import YOLO
import numpy as np
from message_filters import ApproximateTimeSynchronizer, Subscriber

# Initialize CvBridge and YOLO model
bridge = CvBridge()

class BucketTracker(Node):
    def __init__(self):
        super().__init__('bucket_tracker')

        # Load the YOLOv8 model (trained on buckets)
        self.model = YOLO('path_to_your_yolov8_model.pt')
        self.yolov8_inference = Yolov8Inference()

        # Subscribe to the image and depth topics
        self.rgb_sub = Subscriber(self, Image, "/camera/realsense_camera/color/image_raw")
        self.depth_sub = Subscriber(self, Image, "/camera/realsense_camera/depth/image_rect_raw")

        # Create publishers for sending movement commands and visualizations
        self.cmd_pub = self.create_publisher(Twist, "/cmd_vel", 10)
        self.yolov8_pub = self.create_publisher(Yolov8Inference, "/Yolov8_Inference", 1)
        self.img_pub = self.create_publisher(Image, "/inference_result", 1)

        # Synchronize RGB and depth images
        self.ts = ApproximateTimeSynchronizer([self.rgb_sub, self.depth_sub], queue_size=10, slop=0.1)
        self.ts.registerCallback(self.synced_callback)

    def synced_callback(self, rgb_msg, depth_msg):
        # Convert the ROS image message to OpenCV format
        rgb_image = bridge.imgmsg_to_cv2(rgb_msg, "bgr8")
        depth_image = bridge.imgmsg_to_cv2(depth_msg, desired_encoding="passthrough")

        results = self.model(rgb_image)

        # Process the inference results
        self.yolov8_inference.header.frame_id = "inference"
        self.yolov8_inference.header.stamp = self.get_clock().now().to_msg()

        twist = Twist()

        bucket_positions = []  # List to store bucket positions

        for r in results:
            boxes = r.boxes
            for box in boxes:
                b = box.xyxy[0].to('cpu').detach().numpy().copy()  # Get bounding box coordinates (x1, y1, x2, y2)
                c = box.cls  # Class index

                # Only process "bucket" class (replace with actual class index for bucket in your model)
                if self.model.names[int(c)] == "bucket":
                    # Store the bounding box data for buckets
                    x1, y1, x2, y2 = map(int, b)
                    mid_x, mid_y = (x1 + x2) // 2, (y1 + y2) // 2  # Calculate the center of the bounding box

                    bucket_positions.append((mid_x, mid_y))

                    # Create InferenceResult to publish
                    inference_result = InferenceResult()
                    inference_result.class_name = self.model.names[int(c)]
                    inference_result.top = y1
                    inference_result.left = x1
                    inference_result.bottom = y2
                    inference_result.right = x2

                    self.yolov8_inference.yolov8_inference.append(inference_result)

                    # Draw box around detected bucket
                    cv2.rectangle(rgb_image, (x1, y1), (x2, y2), (0, 255, 0), 2)

        # If we detect two buckets, calculate movement between them
        if len(bucket_positions) == 2:
            # First bucket's center position
            bucket_left = bucket_positions[0]
            bucket_right = bucket_positions[1]

            # Turn to face the first bucket (left)
            if bucket_left[0] < rgb_image.shape[1] // 2 - 50:
                twist.angular.z = 0.5  # Turn towards the left bucket
            elif bucket_left[0] > rgb_image.shape[1] // 2 + 50:
                twist.angular.z = -0.5  # Turn towards the right bucket
            else:
                twist.angular.z = 0.0  # Stop turning, move forward

            # Move towards the first bucket
            twist.linear.x = 0.1  # Move forward

            # After reaching the left bucket, stop and turn to face the right bucket
            self.cmd_pub.publish(twist)
            self.get_logger().info(f"Moving to left bucket at position: {bucket_left}")

            # Now, let's move towards the right bucket (you can add a similar movement logic here)
            if bucket_right[0] < rgb_image.shape[1] // 2 - 50:
                twist.angular.z = 0.5  # Turn towards the right bucket
            elif bucket_right[0] > rgb_image.shape[1] // 2 + 50:
                twist.angular.z = -0.5
            else:
                twist.angular.z = 0.0

            self.cmd_pub.publish(twist)
            self.get_logger().info(f"Moving to right bucket at position: {bucket_right}")

        # Publish the image with annotations and the yolov8_inference message
        img_msg = bridge.cv2_to_imgmsg(rgb_image)
        self.img_pub.publish(img_msg)
        self.yolov8_pub.publish(self.yolov8_inference)
        self.yolov8_inference.yolov8_inference.clear()

def main(args=None):
    rclpy.init(args=args)
    node = BucketTracker()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
