// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yolov8_msgs:msg/ColorDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yolov8_msgs/msg/color_detection.hpp"


#ifndef YOLOV8_MSGS__MSG__DETAIL__COLOR_DETECTION__BUILDER_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__COLOR_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yolov8_msgs/msg/detail/color_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yolov8_msgs
{

namespace msg
{

namespace builder
{

class Init_ColorDetection_detected
{
public:
  explicit Init_ColorDetection_detected(::yolov8_msgs::msg::ColorDetection & msg)
  : msg_(msg)
  {}
  ::yolov8_msgs::msg::ColorDetection detected(::yolov8_msgs::msg::ColorDetection::_detected_type arg)
  {
    msg_.detected = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolov8_msgs::msg::ColorDetection msg_;
};

class Init_ColorDetection_color_detected
{
public:
  Init_ColorDetection_color_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ColorDetection_detected color_detected(::yolov8_msgs::msg::ColorDetection::_color_detected_type arg)
  {
    msg_.color_detected = std::move(arg);
    return Init_ColorDetection_detected(msg_);
  }

private:
  ::yolov8_msgs::msg::ColorDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolov8_msgs::msg::ColorDetection>()
{
  return yolov8_msgs::msg::builder::Init_ColorDetection_color_detected();
}

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__COLOR_DETECTION__BUILDER_HPP_
