#!/bin/bash

ros2 launch articubot_one rtabmap.launch.py \
    rtabmap_args:="--delete_db_on_start" \
    params_file:=/home/robogames/vt-cro/robogames_pi/car_robot_ws/src/articubot_one/config/rtabmap_params.yaml \
    rgb_topic:=/camera/camera/color/image_raw \
    depth_topic:=/camera/camera/depth/image_rect_raw \
    camera_info_topic:=/camera/camera/depth/camera_info \
    frame_id:=camera_link \
    RGBD/OptimizeMaxError:=8.0 \
    #approx_sync:=false \ #means RTAB-Map and RGBD Odometry expect **all topics to have the exact same timestamp:
    approx_sync:=true \
    #sync_queue_size:=30 \
    rgb_image_transport:=raw \
    #wait_imu_to_init:=true \
    #imu_topic:=/camera/realsense_camera/gyro/sample \
    rviz:=true
