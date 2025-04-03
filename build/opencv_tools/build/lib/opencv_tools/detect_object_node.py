import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2
import tflite_runtime.interpreter as tflite

class ObjectDetector(Node):
    def __init__(self):
        super().__init__('object_detector')

        self.get_logger().info('Loading TFLite model...')
        self.interpreter = tflite.Interpreter(
            model_path='src/object_detector/models/detect.tflite'
        )
        self.interpreter.allocate_tensors()
        self.input_details = self.interpreter.get_input_details()
        self.output_details = self.interpreter.get_output_details()

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
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f"CV Bridge error: {e}")
            return

        # Preprocess image for TFLite
        input_tensor = cv2.resize(cv_image, (300, 300))
        input_tensor = np.expand_dims(input_tensor, axis=0)
        input_tensor = input_tensor.astype(np.uint8)

        self.interpreter.set_tensor(self.input_details[0]['index'], input_tensor)
        self.interpreter.invoke()

        boxes = self.interpreter.get_tensor(self.output_details[0]['index'])[0]
        classes = self.interpreter.get_tensor(self.output_details[1]['index'])[0]
        scores = self.interpreter.get_tensor(self.output_details[2]['index'])[0]

        for i in range(len(scores)):
            if scores[i] > 0.5:
                self.get_logger().info(
                    f"Detected class {int(classes[i])} with confidence {scores[i]:.2f}"
                )

def main(args=None):
    rclpy.init(args=args)
    node = ObjectDetector()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
