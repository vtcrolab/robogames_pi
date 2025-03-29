from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    package_name = 'articubot_one'

    launch_robot = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory(package_name), 'launch', 'launch_robot.launch.py')
        )
    )

    behavior_tree_node = Node(
        package='articubot_one',
        executable='main_bt_node',
        name='behavior_tree',
        output='screen',
        parameters=[
            {'bt_xml_file': '/home/robogames/vt-cro/robogames_pi/car_robot_ws/src/articubot_one/config/navigate_w_replanning_and_recovery.xml'}
        ]
    )

    # Delay the BT node by 5 seconds
    delayed_bt_node = TimerAction(
        period=15.0,
        actions=[behavior_tree_node]
    )

    return LaunchDescription([
        launch_robot,
        delayed_bt_node
    ])
