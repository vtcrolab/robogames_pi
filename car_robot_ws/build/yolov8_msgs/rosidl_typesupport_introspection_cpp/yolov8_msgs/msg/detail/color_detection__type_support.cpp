// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from yolov8_msgs:msg/ColorDetection.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "yolov8_msgs/msg/detail/color_detection__functions.h"
#include "yolov8_msgs/msg/detail/color_detection__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace yolov8_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ColorDetection_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) yolov8_msgs::msg::ColorDetection(_init);
}

void ColorDetection_fini_function(void * message_memory)
{
  auto typed_message = static_cast<yolov8_msgs::msg::ColorDetection *>(message_memory);
  typed_message->~ColorDetection();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ColorDetection_message_member_array[2] = {
  {
    "color_detected",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs::msg::ColorDetection, color_detected),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "detected",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs::msg::ColorDetection, detected),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ColorDetection_message_members = {
  "yolov8_msgs::msg",  // message namespace
  "ColorDetection",  // message name
  2,  // number of fields
  sizeof(yolov8_msgs::msg::ColorDetection),
  false,  // has_any_key_member_
  ColorDetection_message_member_array,  // message members
  ColorDetection_init_function,  // function to initialize message memory (memory has to be allocated)
  ColorDetection_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ColorDetection_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ColorDetection_message_members,
  get_message_typesupport_handle_function,
  &yolov8_msgs__msg__ColorDetection__get_type_hash,
  &yolov8_msgs__msg__ColorDetection__get_type_description,
  &yolov8_msgs__msg__ColorDetection__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace yolov8_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<yolov8_msgs::msg::ColorDetection>()
{
  return &::yolov8_msgs::msg::rosidl_typesupport_introspection_cpp::ColorDetection_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, yolov8_msgs, msg, ColorDetection)() {
  return &::yolov8_msgs::msg::rosidl_typesupport_introspection_cpp::ColorDetection_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
