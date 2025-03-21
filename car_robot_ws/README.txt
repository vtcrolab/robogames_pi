first run ./first_build.sh
then source install/setup.bash
ros2 launch articubot_one camera.launch.py (just by running this launch file should as well run the node of detecting color. I included both of them in the launcher so I don't have to be running them all the time. You can separate them if you want. 

to check that color detector is running you should see that it says "detecting yellow, blue, etc" or you can run
ros2 topic echo /camera/color/image_raw  (you should see a bunch of number in a column, if you ctrl-c and scroll through
you will see that it tells you what color was detected
LIKE THIS
- 149
- 158
- '...'
---
header:
  stamp:
    sec: 1742525022
    nanosec: 255080322
  frame_id: camera_color_optical_frame
height: 480
width: 640
encoding: rgb8
is_bigendian: 0
step: 1920
data:
- 169
- 180
- 194
- 167
- 179
- 193
- 164
- 180

if you want to check if the motors are turning when detecting a color do 
ros2 topic echo /cmd_vel

that should be it. The rest should be available when you launch rviz2
