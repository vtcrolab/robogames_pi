// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from yolov8_msgs:msg/ColorDetection.idl
// generated code does not contain a copyright notice
#include "yolov8_msgs/msg/detail/color_detection__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "yolov8_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "yolov8_msgs/msg/detail/color_detection__struct.h"
#include "yolov8_msgs/msg/detail/color_detection__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // color_detected
#include "rosidl_runtime_c/string_functions.h"  // color_detected

// forward declare type support functions


using _ColorDetection__ros_msg_type = yolov8_msgs__msg__ColorDetection;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
bool cdr_serialize_yolov8_msgs__msg__ColorDetection(
  const yolov8_msgs__msg__ColorDetection * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: color_detected
  {
    const rosidl_runtime_c__String * str = &ros_message->color_detected;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: detected
  {
    cdr << (ros_message->detected ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
bool cdr_deserialize_yolov8_msgs__msg__ColorDetection(
  eprosima::fastcdr::Cdr & cdr,
  yolov8_msgs__msg__ColorDetection * ros_message)
{
  // Field name: color_detected
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->color_detected.data) {
      rosidl_runtime_c__String__init(&ros_message->color_detected);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->color_detected,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'color_detected'\n");
      return false;
    }
  }

  // Field name: detected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->detected = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
size_t get_serialized_size_yolov8_msgs__msg__ColorDetection(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ColorDetection__ros_msg_type * ros_message = static_cast<const _ColorDetection__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: color_detected
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->color_detected.size + 1);

  // Field name: detected
  {
    size_t item_size = sizeof(ros_message->detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
size_t max_serialized_size_yolov8_msgs__msg__ColorDetection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: color_detected
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: detected
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = yolov8_msgs__msg__ColorDetection;
    is_plain =
      (
      offsetof(DataType, detected) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
bool cdr_serialize_key_yolov8_msgs__msg__ColorDetection(
  const yolov8_msgs__msg__ColorDetection * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: color_detected
  {
    const rosidl_runtime_c__String * str = &ros_message->color_detected;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: detected
  {
    cdr << (ros_message->detected ? true : false);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
size_t get_serialized_size_key_yolov8_msgs__msg__ColorDetection(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ColorDetection__ros_msg_type * ros_message = static_cast<const _ColorDetection__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: color_detected
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->color_detected.size + 1);

  // Field name: detected
  {
    size_t item_size = sizeof(ros_message->detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
size_t max_serialized_size_key_yolov8_msgs__msg__ColorDetection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: color_detected
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: detected
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = yolov8_msgs__msg__ColorDetection;
    is_plain =
      (
      offsetof(DataType, detected) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _ColorDetection__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const yolov8_msgs__msg__ColorDetection * ros_message = static_cast<const yolov8_msgs__msg__ColorDetection *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_yolov8_msgs__msg__ColorDetection(ros_message, cdr);
}

static bool _ColorDetection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  yolov8_msgs__msg__ColorDetection * ros_message = static_cast<yolov8_msgs__msg__ColorDetection *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_yolov8_msgs__msg__ColorDetection(cdr, ros_message);
}

static uint32_t _ColorDetection__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_yolov8_msgs__msg__ColorDetection(
      untyped_ros_message, 0));
}

static size_t _ColorDetection__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_yolov8_msgs__msg__ColorDetection(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ColorDetection = {
  "yolov8_msgs::msg",
  "ColorDetection",
  _ColorDetection__cdr_serialize,
  _ColorDetection__cdr_deserialize,
  _ColorDetection__get_serialized_size,
  _ColorDetection__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ColorDetection__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ColorDetection,
  get_message_typesupport_handle_function,
  &yolov8_msgs__msg__ColorDetection__get_type_hash,
  &yolov8_msgs__msg__ColorDetection__get_type_description,
  &yolov8_msgs__msg__ColorDetection__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yolov8_msgs, msg, ColorDetection)() {
  return &_ColorDetection__type_support;
}

#if defined(__cplusplus)
}
#endif
