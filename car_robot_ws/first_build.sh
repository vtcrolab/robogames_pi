#! /bin/bash

cd ~/vt-cro/robogames_pi/car_robot_ws
rm -rf build/ log/ install/
#source ~/torch_py_env/bin/activate
#colcon build --packages-select opencv_tools --cmake-args -DPYTHON_EXECUTABLE=$(which python)
#deactivate
colcon build --packages-select serial
source install/setup.bash
#colcon build --packages-ignore opencv_tools serial
# ros2 run realsense2_camera realsense2_camera_node
# ros2 run articubot_one depth_to_laserscan
chmod +x src/yolobot_recognition/scripts/yolov8_ros2_pt.py
colcon build --symlink-install 
#colcon build --packages-select yolobot_recognition
source install/setup.bash
