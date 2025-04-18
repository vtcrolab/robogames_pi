from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node

def generate_launch_description():

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use simulation (Gazebo) clock if true'),
        
        Node(package='yolobot_recognition', executable='yolov8_ros2_pt.py', output='screen'),

        # Node(package='yolobot_recognition', executable='object_tracker.py', output='screen'),

        Node(package='yolobot_recognition', executable='color_detector.py', output='screen'),

        
    ])