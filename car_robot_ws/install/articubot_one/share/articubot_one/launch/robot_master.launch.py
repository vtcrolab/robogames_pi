from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    package_name='articubot_one'

    return LaunchDescription([
        # Launch your robot
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([os.path.join(
                get_package_share_directory(package_name),'launch','launch_robot.launch.py'
            )]), 
        ),

        # Launch your BT node
        Node(
            package='articubot_one',
            executable='main_bt_node',
            name='behavior_tree',
            output='screen',
            parameters=[
                # {'bt_xml_file': '/home/vt-cro/robogames_pi/car_robot_ws/robot_bt/bt_trees/top_level_tree.xml'}
                {'bt_xml_file': '/home/robogames/vt-cro/robogames_pi/car_robot_ws/src/articubot_one/config/navigate_w_replanning_and_recovery.xml'}

            ]
        )
    ])
