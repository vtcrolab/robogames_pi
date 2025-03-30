import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command
from launch.actions import RegisterEventHandler
from launch.event_handlers import OnProcessStart

from launch_ros.actions import Node

def generate_launch_description():
    # Include the robot_state_publisher launch file, provided by our own package. Force sim time to be enabled
    package_name='articubot_one' 

    rsp = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory(package_name),'launch','rsp.launch.py'
                )]), launch_arguments={'use_sim_time': 'false', 'use_ros2_control': 'true'}.items()
    )

    # bt_runner =  Node(
    #         package='articubot_one',
    #         executable='bt_runner',
    #         name='bt_runner',
    #         output='screen',
    #         parameters=[{
    #             'bt_xml_file': '/home/robogames/vt-cro/robogames_pi/car_robot_ws/src/articubot_one/config/navigate_w_replanning_and_recovery.xml'
    #         }]
    #     )

    joystick = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory(package_name),'launch','joystick.launch.py'
                )])
    )

    #Multiplexer node for velocity commands
    twist_mux_params = os.path.join(get_package_share_directory(package_name),'config','twist_mux.yaml')
    twist_mux = Node(
            package="twist_mux",
            executable="twist_mux",
            parameters=[twist_mux_params],
            remappings=[('/cmd_vel_out','/diff_cont/cmd_vel_unstamped')]
        )

    #Depth Camera and Color Detection node
    vision = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory(package_name),'launch','vision.launch.py'
        )])
    )

    #Lidar Node
    rplidar = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory(package_name),'launch','rplidar.launch.py'
        )])
    )

    controllers = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory(package_name), 'launch', 'controllers.launch.py'
        )])
    )
   

    # Launch them all!
    return LaunchDescription([
        rsp,
        joystick,
        twist_mux,
        #vision,
        rplidar,
        controllers
    ])
