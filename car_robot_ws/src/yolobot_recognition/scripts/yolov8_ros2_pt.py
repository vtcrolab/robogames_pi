#!/usr/bin/env python3

from ultralytics import YOLO
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from geometry_msgs.msg import Polygon, Point32

from yolov8_msgs.msg import InferenceResult
from yolov8_msgs.msg import Yolov8Inference
from geometry_msgs.msg import Twist


from message_filters import ApproximateTimeSynchronizer, Subscriber

bridge = CvBridge()

class Camera_subscriber(Node):

    def __init__(self):
        super().__init__('camera_subscriber')

        self.model = YOLO('~/vt-cro/robogames_pi/car_robot_ws/src/yolobot_recognition/scripts/yolov8n.pt')
        # self.model = YOLO('/home/robogames/vt-cro/robogames_pi/car_robot_ws/src/colors_best_yolov8n.pt')
        # self.model = YOLO('/home/robogames/vt-cro/robogames_pi/car_robot_ws/src/buckets_best_yolov8n.pt')
        self.yolov8_inference = Yolov8Inference()

        # self.rgb_sub = self.create_subscription(
        #     Image,
        #     'camera/realsense_camera/color/image_raw',
        #     self.synced_callback,
        #     10)
        # #self.rgb_sub 

        # self.depth_sub = self.create_subscription(
        #     Image,
        #     '/camera/realsense_camera/depth/image_rect_raw',
        #     self.synced_callback,
        #     10
        # )
        # #self.depth_sub

        # Use message_filters.Subscriber instead of self.create_subscription
        self.rgb_sub = Subscriber(self, Image, "/camera/realsense_camera/color/image_raw")
        self.depth_sub = Subscriber(self, Image, "/camera/realsense_camera/depth/image_rect_raw")
        self.cmd_pub = self.create_publisher(Twist, "/cmd_vel", 1)

        self.ts = ApproximateTimeSynchronizer([self.rgb_sub, self.depth_sub], queue_size=10, slop=0.1)
        self.ts.registerCallback(self.synced_callback)

        self.yolov8_pub = self.create_publisher(Yolov8Inference, "/Yolov8_Inference", 1)
        self.img_pub = self.create_publisher(Image, "/inference_result", 1)
        self.bounding_box_pub = self.create_publisher(Polygon, "/bounding_boxes", 1)


    def synced_callback(self, rgb_msg, depth_msg):
        rgb_image = bridge.imgmsg_to_cv2(rgb_msg, "bgr8")
        depth_image = bridge.imgmsg_to_cv2(depth_msg, desired_encoding="passthrough")

        results = self.model(rgb_image)

        print("MODEL CLASSES:", self.model.names)

        self.yolov8_inference.header.frame_id = "inference"
        self.yolov8_inference.header.stamp = self.get_clock().now().to_msg()

        msg = Yolov8Inference()
        msg.header = rgb_msg.header

        # Initialize Twist message for movement commands
        twist = Twist()

        for r in results:
            boxes = r.boxes
            for box in boxes:
                self.inference_result = InferenceResult()
                b = box.xyxy[0].to('cpu').detach().numpy().copy()  # get box coordinates in (top, left, bottom, right) format
                c = box.cls

                # Get the class name
                class_name = self.model.names[int(c)]
                
                # if class_name == "person":
                if class_name == "backpack":
                    self.inference_result.class_name = self.model.names[int(c)]
                    self.inference_result.top = int(b[0])
                    self.inference_result.left = int(b[1])
                    self.inference_result.bottom = int(b[2])
                    self.inference_result.right = int(b[3])
                    
                    self.yolov8_inference.yolov8_inference.append(self.inference_result)
                    
                    x1, y1, x2, y2 = map(int, b) #same thing as above but shorter vars
                    mid_x, mid_y = int((x1 + x2) / 2), int((y1 + y2) / 2) #middle of box

                    # Get depth at center of bounding box (ensure it's in bounds)
                    if 0 <= mid_y < depth_image.shape[0] and 0 <= mid_x < depth_image.shape[1]:
                        depth_value = float(depth_image[mid_y, mid_x])  # May be in mm or meters depending on Realsense config
                    else:
                        depth_value = -1.0  # Fallback or invalid value

                    self.inference_result.depth = depth_value

                    # Turning logic: Compare mid_x (center of object) with image width
                    image_center_x = rgb_image.shape[1] // 2  # Image width divided by 2

                    # Turn the robot towards the detected object if it's off-center
                    if mid_x < image_center_x - 50:  # Object is to the left of the center
                        twist.angular.z = 0.3  # Turn clockwise (right)
                    elif mid_x > image_center_x + 50:  # Object is to the right of the center
                        twist.angular.z = -0.3  # Turn counterclockwise (left)
                    else:  # Object is centered
                        twist.angular.z = 0.0  # Stop rotating

                    # Publish movement command (turning)
                    self.cmd_pub.publish(twist)
                    
        
        annotated_frame = results[0].plot()
        img_msg = bridge.cv2_to_imgmsg(annotated_frame)  

        self.img_pub.publish(img_msg)
        self.yolov8_pub.publish(self.yolov8_inference)
        self.yolov8_inference.yolov8_inference.clear()


if __name__ == '__main__':
    rclpy.init(args=None)
    camera_subscriber = Camera_subscriber()
    rclpy.spin(camera_subscriber)
    rclpy.shutdown()


#YOLOV5 torch

# import rclpy
# from rclpy.node import Node
# from sensor_msgs.msg import Image
# from cv_bridge import CvBridge
# import torch
# import numpy as np
# import cv2
# import os
# import sys

# from yolov8_msgs.msg import InferenceResult, Yolov8Inference
# # Add path to YOLOv5 repo
# sys.path.append(os.path.join(os.path.expanduser("~"), 'yolov5'))

# bridge = CvBridge()

# class CameraSubscriber(Node):
#     def __init__(self):
#         super().__init__('camera_subscriber')

#         # Load YOLOv5 model (custom model path)
#         #         self.model = YOLO('~/vt-cro/robogames_pi/car_robot_ws/src/colors_best.pt')

#         self.model = torch.hub.load('yolov5', 'custom', path='~/vt-cro/robogames_pi/car_robot_ws/src/colors_best.pt', source='local')  # or your custom.pt path
#         self.model.conf = 0.5  # Confidence threshold

#         self.subscription = self.create_subscription(
#             Image,
#             'camera/realsense_camera/color/image_raw',
#             self.camera_callback,
#             10
#         )

#         self.img_pub = self.create_publisher(Image, "/inference_result", 1)
#         self.yolov8_pub = self.create_publisher(Yolov8Inference, "/Yolov8_Inference", 1)

#         self.yolov8_inference = Yolov8Inference()

#     def camera_callback(self, data):
#         img = bridge.imgmsg_to_cv2(data, "bgr8")
#         results = self.model(img)

#         self.yolov8_inference.header.stamp = self.get_clock().now().to_msg()
#         self.yolov8_inference.header.frame_id = "inference"

#         for *box, conf, cls in results.xyxy[0]:  # bounding box format: (x1, y1, x2, y2)
#             inf = InferenceResult()
#             inf.left = int(box[0].item())
#             inf.top = int(box[1].item())
#             inf.right = int(box[2].item())
#             inf.bottom = int(box[3].item())
#             inf.class_name = self.model.names[int(cls.item())]
#             self.yolov8_inference.yolov8_inference.append(inf)

#         # Draw annotated frame
#         annotated = np.squeeze(results.render())  # results.render() returns [ndarray]
#         img_msg = bridge.cv2_to_imgmsg(annotated, encoding="bgr8")

#         self.img_pub.publish(img_msg)
#         self.yolov8_pub.publish(self.yolov8_inference)
#         self.yolov8_inference.yolov8_inference.clear()

# def main(args=None):
#     rclpy.init(args=args)
#     node = CameraSubscriber()
#     rclpy.spin(node)
#     node.destroy_node()
#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()


