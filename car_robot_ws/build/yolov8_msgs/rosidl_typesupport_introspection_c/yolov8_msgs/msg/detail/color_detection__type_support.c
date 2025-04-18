// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yolov8_msgs:msg/ColorDetection.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yolov8_msgs/msg/detail/color_detection__rosidl_typesupport_introspection_c.h"
#include "yolov8_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yolov8_msgs/msg/detail/color_detection__functions.h"
#include "yolov8_msgs/msg/detail/color_detection__struct.h"


// Include directives for member types
// Member `color_detected`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void yolov8_msgs__msg__ColorDetection__rosidl_typesupport_introspection_c__ColorDetection_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yolov8_msgs__msg__ColorDetection__init(message_memory);
}

void yolov8_msgs__msg__ColorDetection__rosidl_typesupport_introspection_c__ColorDetection_fini_function(void * message_memory)
{
  yolov8_msgs__msg__ColorDetection__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember yolov8_msgs__msg__ColorDetection__rosidl_typesupport_introspection_c__ColorDetection_message_member_array[2] = {
  {
    "color_detected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs__msg__ColorDetection, color_detected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "detected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs__msg__ColorDetection, detected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers yolov8_msgs__msg__ColorDetection__rosidl_typesupport_introspection_c__ColorDetection_message_members = {
  "yolov8_msgs__msg",  // message namespace
  "ColorDetection",  // message name
  2,  // number of fields
  sizeof(yolov8_msgs__msg__ColorDetection),
  false,  // has_any_key_member_
  yolov8_msgs__msg__ColorDetection__rosidl_typesupport_introspection_c__ColorDetection_message_member_array,  // message members
  yolov8_msgs__msg__ColorDetection__rosidl_typesupport_introspection_c__ColorDetection_init_function,  // function to initialize message memory (memory has to be allocated)
  yolov8_msgs__msg__ColorDetection__rosidl_typesupport_introspection_c__ColorDetection_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t yolov8_msgs__msg__ColorDetection__rosidl_typesupport_introspection_c__ColorDetection_message_type_support_handle = {
  0,
  &yolov8_msgs__msg__ColorDetection__rosidl_typesupport_introspection_c__ColorDetection_message_members,
  get_message_typesupport_handle_function,
  &yolov8_msgs__msg__ColorDetection__get_type_hash,
  &yolov8_msgs__msg__ColorDetection__get_type_description,
  &yolov8_msgs__msg__ColorDetection__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yolov8_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yolov8_msgs, msg, ColorDetection)() {
  if (!yolov8_msgs__msg__ColorDetection__rosidl_typesupport_introspection_c__ColorDetection_message_type_support_handle.typesupport_identifier) {
    yolov8_msgs__msg__ColorDetection__rosidl_typesupport_introspection_c__ColorDetection_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &yolov8_msgs__msg__ColorDetection__rosidl_typesupport_introspection_c__ColorDetection_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
