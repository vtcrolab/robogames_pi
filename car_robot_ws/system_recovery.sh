#!/bin/bash

# Recovery Script: Kill all ROS 2 processes and relaunch articubot

echo "[Recovery] Stopping existing ROS 2 processes..."

# Kill all ROS 2 processes safely
#pkill -f ros2
#pkill -f rviz2
#pkill -f python3
#pkill -f launch.py
#sleep 2

echo "[Recovery] All ROS 2 processes killed."

# Optional: Clear log files or leftover temp data
# rm -rf ~/.ros/log

echo "[Recovery] Relaunching articubot robot controllers..."
ros2 launch articubot_one controllers.launch.py

# Launch your robot
# ros2 launch articubot_one launch_robot.launch.py

# NOTE: This will block the terminal unless you background it like this:
# ros2 launch articubot_one launch_robot.launch.py &

# Add a short delay
sleep 2

echo "[Recovery] Recovery launch complete."
