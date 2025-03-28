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
    # !!! MAKE SURE YOU SET THE PACKAGE NAME CORRECTLY !!!

    package_name='articubot_one' #<--- CHANGE ME

    rsp = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory(package_name),'launch','rsp.launch.py'
                )]), launch_arguments={'use_sim_time': 'false', 'use_ros2_control': 'true'}.items()
    )

    bt_runner =  Node(
            package='articubot_one',
            executable='bt_runner',
            name='bt_runner',
            output='screen',
            parameters=[{
                'bt_xml_file': '/home/robogames/vt-cro/robogames_pi/car_robot_ws/src/articubot_one/config/navigate_w_replanning_and_recovery.xml'
            }]
        )

    joystick = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory(package_name),'launch','joystick.launch.py'
                )])
    )


    twist_mux_params = os.path.join(get_package_share_directory(package_name),'config','twist_mux.yaml')
    twist_mux = Node(
            package="twist_mux",
            executable="twist_mux",
            parameters=[twist_mux_params],
            remappings=[('/cmd_vel_out','/diff_cont/cmd_vel_unstamped')]
        )

    depth_cam = Node(
            package='realsense2_camera',
            executable='realsense2_camera_node',
            name='realsense_camera',
            # namespace='camerayuyg',
            remappings=[
                ('/camera/realsense_camera/color/image_raw', '/camera/camera/color/image_raw'),
                ('/camera/realsense_camera/depth/image_rect_raw', '/camera/camera/depth/image_rect_raw'),
                ('/camera/realsense_camera/infra1/image_rect_raw', '/camera/camera/infra1/image_rect_raw'),
                ('/camera/realsense_camera/infra2/image_rect_raw', '/camera/camera/infra2/image_rect_raw'),
                ('/camera/realsense_camera/depth/camera_info', '/camera/camera/depth/camera_info'),
            ],
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
                'use_system_time': True
            }],
            output='screen'
        ) 

    color_detection_node = Node(
            package='articubot_one',  # Replace with your actual package name
            executable='color_detection_node',  # Name of the executable
            output='screen',
            namespace='color_detection',
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

    rplidar = Node(
            package='rplidar_ros',
            executable='rplidar_composition',
            output='screen',
            parameters=[{
                'serial_port': '/dev/ttyUSB0',
                'frame_id': 'laser_frame',
                'angle_compensate': True,
                'scan_mode': 'Standard'
            }]
        )

    robot_description = Command(['ros2 param get --hide-type /robot_state_publisher robot_description'])

    controller_params_file = os.path.join(get_package_share_directory(package_name),'config','my_controllers.yaml')

    controller_manager = Node(
        package="controller_manager",
        executable="ros2_control_node",
        output = 'screen',
        parameters=[{'robot_description': robot_description},
                    controller_params_file]
    )

    delayed_controller_manager = TimerAction(period=3.0, actions=[controller_manager])

    diff_drive_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["diff_cont"],
    )

    delayed_diff_drive_spawner = RegisterEventHandler(
        event_handler=OnProcessStart(
            target_action=controller_manager,
            on_start=[diff_drive_spawner],
        )
    )

    joint_broad_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_broad"],
    )

    delayed_joint_broad_spawner = RegisterEventHandler(
        event_handler=OnProcessStart(
            target_action=controller_manager,
            on_start=[joint_broad_spawner],
        )
    )


    # Code for delaying a node (I haven't tested how effective it is)
    # 
    # First add the below lines to imports
    # from launch.actions import RegisterEventHandler
    # from launch.event_handlers import OnProcessExit
    #
    # Then add the following below the current diff_drive_spawner
    #
    # delayed_diff_drive_spawner = RegisterEventHandler(
    #     event_handler=OnProcessExit(
    #         target_action=spawn_entity,
    #         on_exit=[diff_drive_spawner],
    #     )
    # )
    #
    # Replace the diff_drive_spawner in the final return with delayed_diff_drive_spawner



    # Launch them all!
    return LaunchDescription([
        rsp,
        joystick,
        twist_mux,
        #depth_cam,
        rplidar,
        # color_detection_node
        #depth_to_scan_and_pointcloud,
        delayed_controller_manager,
        delayed_diff_drive_spawner,
        delayed_joint_broad_spawner
    ])
