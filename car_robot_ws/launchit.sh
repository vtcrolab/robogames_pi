#! /bin/bash
#
source /opt/ros/jazzy/setup.bash
source /home/robogames/vt-cro/robogames_pi/car_robot_ws/install/setup.bash
ros2 launch articubot_one launch_robot.launch.py
#sudo ipcs -m
#sudo ipcrm -m <segment_id>
