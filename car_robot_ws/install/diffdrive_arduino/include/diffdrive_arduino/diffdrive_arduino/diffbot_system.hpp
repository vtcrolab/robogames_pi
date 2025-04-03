// Copyright 2021 ros2_control Development Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DIFFDRIVE_ARDUINO__DIFFBOT_SYSTEM_HPP_
#define DIFFDRIVE_ARDUINO__DIFFBOT_SYSTEM_HPP_

#include <memory>
#include <string>
#include <vector>

#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "rclcpp/clock.hpp"
#include "rclcpp/duration.hpp"
#include "rclcpp/macros.hpp"
#include "rclcpp/time.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"
#include "diffdrive_arduino/visibility_control.h"

#include "sensor_msgs/msg/joy.hpp"

#include "geometry_msgs/msg/twist.hpp"

#include "diffdrive_arduino/arduino_comms.hpp"
#include "diffdrive_arduino/wheel.hpp"

#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2/LinearMath/Quaternion.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "tf2_ros/transform_broadcaster.h"

namespace diffdrive_arduino
{
class DiffDriveArduinoHardware : public hardware_interface::SystemInterface
{

struct Config
{
  std::string left_wheel_name = "";
  std::string right_wheel_name = "";
  float loop_rate = 0.0;
  std::string device = "";
  int baud_rate = 0;
  int timeout_ms = 0;
  double wheel_radius = 0;      //(meters) 
  double base_width = 0;  //distance between wheels (meters)
  int enc_counts_per_rev = 0;
  // int pid_p = 0;
  // int pid_d = 0;
  // int pid_i = 0;
  // int pid_o = 0;
};


public:
  DiffDriveArduinoHardware() {
    // Create an internal ROS 2 node for joystick handling
    node_ = std::make_shared<rclcpp::Node>("diffdrive_arduino_hardware");

    // Create the joystick subscription
    joy_sub_ = node_->create_subscription<sensor_msgs::msg::Joy>(
        "/joy", 10, std::bind(&DiffDriveArduinoHardware::joy_callback, this, std::placeholders::_1));

    cmd_vel_pub_ = node_->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel_custom_joy", 10);

    // tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(node_);

    // Inside on_init or on_activate:
    odom_pub_ = node_->create_publisher<nav_msgs::msg::Odometry>("/odom", 10);
    tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(node_);


    // Start a separate thread to spin the node
    spin_thread_ = std::thread([this]() {
        rclcpp::executors::SingleThreadedExecutor executor;
        executor.add_node(node_);
        RCLCPP_INFO(node_->get_logger(), "Spinning joystick subscription node...");
        executor.spin();
    });
  }

  ~DiffDriveArduinoHardware() {
  if (spin_thread_.joinable()) {
      RCLCPP_INFO(node_->get_logger(), "Shutting down executor thread...");
      rclcpp::shutdown();  // Shutdown the ROS node
      spin_thread_.join();
  }
  }

  RCLCPP_SHARED_PTR_DEFINITIONS(DiffDriveArduinoHardware);

  DIFFDRIVE_ARDUINO_PUBLIC
  hardware_interface::CallbackReturn on_init(
    const hardware_interface::HardwareInfo & info) override;

  DIFFDRIVE_ARDUINO_PUBLIC
  std::vector<hardware_interface::StateInterface> export_state_interfaces() override;

  DIFFDRIVE_ARDUINO_PUBLIC
  std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

  DIFFDRIVE_ARDUINO_PUBLIC
  hardware_interface::CallbackReturn on_configure(
    const rclcpp_lifecycle::State & previous_state) override;

  DIFFDRIVE_ARDUINO_PUBLIC
  hardware_interface::CallbackReturn on_cleanup(
    const rclcpp_lifecycle::State & previous_state) override;


  DIFFDRIVE_ARDUINO_PUBLIC
  hardware_interface::CallbackReturn on_activate(
    const rclcpp_lifecycle::State & previous_state) override;

  DIFFDRIVE_ARDUINO_PUBLIC
  hardware_interface::CallbackReturn on_deactivate(
    const rclcpp_lifecycle::State & previous_state) override;

  DIFFDRIVE_ARDUINO_PUBLIC
  hardware_interface::return_type read(
    const rclcpp::Time & time, const rclcpp::Duration & period) override;

  DIFFDRIVE_ARDUINO_PUBLIC
  hardware_interface::return_type write(
    const rclcpp::Time & time, const rclcpp::Duration & period) override;

private:

  ArduinoComms comms_;
  Config cfg_;
  Wheel wheel_l_;
  Wheel wheel_r_;

  void joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg);

  rclcpp::Node::SharedPtr node_;
  std::thread spin_thread_;

  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_sub_;

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;

  // Member variables you must add in header:
  double x_ , y_, theta_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
  std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
  // std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

  int speed_min, speed_max, current_speed;
};

}  // namespace diffdrive_arduino

#endif  // DIFFDRIVE_ARDUINO__DIFFBOT_SYSTEM_HPP_
