#!/bin/bash
source ~/torch_py_env/bin/activate
source ~/vt-cro/robogames_pi/car_robot_ws/install/setup.bash
ros2 run opencv_tools detect_node
