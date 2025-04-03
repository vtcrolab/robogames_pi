// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yolov8_msgs:msg/ColorDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yolov8_msgs/msg/color_detection.hpp"


#ifndef YOLOV8_MSGS__MSG__DETAIL__COLOR_DETECTION__TRAITS_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__COLOR_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "yolov8_msgs/msg/detail/color_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace yolov8_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ColorDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: color_detected
  {
    out << "color_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.color_detected, out);
    out << ", ";
  }

  // member: detected
  {
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ColorDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: color_detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.color_detected, out);
    out << "\n";
  }

  // member: detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ColorDetection & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace yolov8_msgs

namespace rosidl_generator_traits
{

[[deprecated("use yolov8_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const yolov8_msgs::msg::ColorDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  yolov8_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yolov8_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const yolov8_msgs::msg::ColorDetection & msg)
{
  return yolov8_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<yolov8_msgs::msg::ColorDetection>()
{
  return "yolov8_msgs::msg::ColorDetection";
}

template<>
inline const char * name<yolov8_msgs::msg::ColorDetection>()
{
  return "yolov8_msgs/msg/ColorDetection";
}

template<>
struct has_fixed_size<yolov8_msgs::msg::ColorDetection>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<yolov8_msgs::msg::ColorDetection>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<yolov8_msgs::msg::ColorDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // YOLOV8_MSGS__MSG__DETAIL__COLOR_DETECTION__TRAITS_HPP_
