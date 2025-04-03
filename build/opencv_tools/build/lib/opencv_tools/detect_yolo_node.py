import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2
import sys
print("Python executable used:", sys.executable)

from ultralytics import YOLO

class ObjectDetector(Node):
    def __init__(self):
        super().__init__('object_detector')

        self.get_logger().info('Loading YOLOv8 model...')
        self.model = YOLO('yolov8n.pt')  # smallest model, fast for Pi

        self.bridge = CvBridge()

        self.subscription = self.create_subscription(
            Image,
            '/camera/realsense_camera/color/image_raw',
            self.image_callback,
            10
        )
        self.subscription  # prevent unused var warning

    def image_callback(self, msg):
        try:
            frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f"CV Bridge error: {e}")
            return

        results = self.model(frame, verbose=False)[0]

        for box in results.boxes:
            cls = int(box.cls[0])
            conf = float(box.conf[0])
            label = self.model.names[cls]

            self.get_logger().info(
                f"Detected: {label} (confidence: {conf:.2f})"
            )

def main(args=None):
    rclpy.init(args=args)
    node = ObjectDetector()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
