// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yolov8_msgs:msg/ColorDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yolov8_msgs/msg/color_detection.hpp"


#ifndef YOLOV8_MSGS__MSG__DETAIL__COLOR_DETECTION__STRUCT_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__COLOR_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__yolov8_msgs__msg__ColorDetection __attribute__((deprecated))
#else
# define DEPRECATED__yolov8_msgs__msg__ColorDetection __declspec(deprecated)
#endif

namespace yolov8_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ColorDetection_
{
  using Type = ColorDetection_<ContainerAllocator>;

  explicit ColorDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->color_detected = "";
      this->detected = false;
    }
  }

  explicit ColorDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : color_detected(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->color_detected = "";
      this->detected = false;
    }
  }

  // field types and members
  using _color_detected_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _color_detected_type color_detected;
  using _detected_type =
    bool;
  _detected_type detected;

  // setters for named parameter idiom
  Type & set__color_detected(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->color_detected = _arg;
    return *this;
  }
  Type & set__detected(
    const bool & _arg)
  {
    this->detected = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yolov8_msgs::msg::ColorDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const yolov8_msgs::msg::ColorDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yolov8_msgs::msg::ColorDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yolov8_msgs::msg::ColorDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::ColorDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::ColorDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::ColorDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::ColorDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yolov8_msgs::msg::ColorDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yolov8_msgs::msg::ColorDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yolov8_msgs__msg__ColorDetection
    std::shared_ptr<yolov8_msgs::msg::ColorDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yolov8_msgs__msg__ColorDetection
    std::shared_ptr<yolov8_msgs::msg::ColorDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ColorDetection_ & other) const
  {
    if (this->color_detected != other.color_detected) {
      return false;
    }
    if (this->detected != other.detected) {
      return false;
    }
    return true;
  }
  bool operator!=(const ColorDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ColorDetection_

// alias to use template instance with default allocator
using ColorDetection =
  yolov8_msgs::msg::ColorDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__COLOR_DETECTION__STRUCT_HPP_
