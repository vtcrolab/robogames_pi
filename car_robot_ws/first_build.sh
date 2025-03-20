#! /bin/bash

cd ~/vt-cro/robogames_pi/car_robot_ws
rm -rf build/ log/ install/
colcon build --packages-select serial
source install/setup.bash
colcon build
# ros2 run realsense2_camera realsense2_camera_node
# ros2 run articubot_one depth_to_laserscan
