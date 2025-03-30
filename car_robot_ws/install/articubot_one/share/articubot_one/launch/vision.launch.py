# import os

# from launch import LaunchDescription
# from launch_ros.actions import Node

# def generate_launch_description():


import os

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # RealSense Camera Node
    depth_cam = Node(
        package='realsense2_camera',
        executable='realsense2_camera_node',
        name='realsense_camera',
        # remappings=[
        #     ('/camera/realsense_camera/color/image_raw', '/camera/color/image_raw'),
        #     ('/camera/realsense_camera/depth/image_rect_raw', '/camera/depth/image_rect_raw'),
        #     ('/camera/realsense_camera/infra1/image_rect_raw', '/camera/infra1/image_rect_raw'),
        #     ('/camera/realsense_camera/infra2/image_rect_raw', '/camera/infra2/image_rect_raw'),
        #     ('/camera/realsense_camera/depth/camera_info', '/camera/depth/camera_info'),
        # ],
        parameters=[{
            'enable_depth': True,
            'enable_color': True,
            'enable_infra1': True,
            'enable_infra2': True,
            'depth_module.profile': '640x480x15',  # resolutionxFPS
            'rgb_camera.profile': '640x480x15',  # resolutionxFPS
            'pointcloud.enable': True,
            'unite_imu_method': 'none',
            'use_sim_time': False,
            'use_system_time': True,
            'camera_frame_id': 'camera_link',
        }],
        output='screen'
    )

    # # delayed_depth_cam = TimerAction(period=3.0, actions=[depth_cam])

    # depth_to_scan_and_pointcloud = Node(
    #     package="articubot_one",
    #     executable="depth_to_laserscan",
    # )

    # delayed_depth_to_scan_and_pointcloud = RegisterEventHandler(
    #     event_handler=OnProcessStart(
    #         target_action=depth_cam,
    #         on_start=[depth_to_scan_and_pointcloud],
    #     )
    # )

    color_detection_node = Node(
        package='articubot_one',  # Replace with your actual package name
        executable='color_detection_node',  # Name of the executable
        output='screen',
        namespace='color_detection',
    )


    object_detection_node = Node(
        package='articubot_one',  # Replace with your actual package name
        executable='object_detection_node',  # Name of the object detection executable
        output='screen',
        namespace='object_detection',
        parameters=[{
            'confidence_threshold': 0.5,  # Adjust as needed
            'visualization': True,  # Enable RViz visualization
        }]
    )

    return LaunchDescription([
        depth_cam,
        color_detection_node
        object_detection_node,

    ])
