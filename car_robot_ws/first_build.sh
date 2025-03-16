#! /bin/bash

cd ~/vt-cro/car_robot_ws
rm -rf build/ log/ install/
colcon build --packages-select serial
source install/setup.bash
colcon build

