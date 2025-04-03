// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from yolov8_msgs:msg/InferenceResult.idl
// generated code does not contain a copyright notice
#include "yolov8_msgs/msg/detail/inference_result__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "yolov8_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "yolov8_msgs/msg/detail/inference_result__struct.h"
#include "yolov8_msgs/msg/detail/inference_result__functions.h"
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

#include "rosidl_runtime_c/string.h"  // class_name
#include "rosidl_runtime_c/string_functions.h"  // class_name

// forward declare type support functions


using _InferenceResult__ros_msg_type = yolov8_msgs__msg__InferenceResult;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
bool cdr_serialize_yolov8_msgs__msg__InferenceResult(
  const yolov8_msgs__msg__InferenceResult * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: class_name
  {
    const rosidl_runtime_c__String * str = &ros_message->class_name;
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

  // Field name: top
  {
    cdr << ros_message->top;
  }

  // Field name: left
  {
    cdr << ros_message->left;
  }

  // Field name: bottom
  {
    cdr << ros_message->bottom;
  }

  // Field name: right
  {
    cdr << ros_message->right;
  }

  // Field name: depth
  {
    cdr << ros_message->depth;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
bool cdr_deserialize_yolov8_msgs__msg__InferenceResult(
  eprosima::fastcdr::Cdr & cdr,
  yolov8_msgs__msg__InferenceResult * ros_message)
{
  // Field name: class_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->class_name.data) {
      rosidl_runtime_c__String__init(&ros_message->class_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->class_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'class_name'\n");
      return false;
    }
  }

  // Field name: top
  {
    cdr >> ros_message->top;
  }

  // Field name: left
  {
    cdr >> ros_message->left;
  }

  // Field name: bottom
  {
    cdr >> ros_message->bottom;
  }

  // Field name: right
  {
    cdr >> ros_message->right;
  }

  // Field name: depth
  {
    cdr >> ros_message->depth;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
size_t get_serialized_size_yolov8_msgs__msg__InferenceResult(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _InferenceResult__ros_msg_type * ros_message = static_cast<const _InferenceResult__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: class_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->class_name.size + 1);

  // Field name: top
  {
    size_t item_size = sizeof(ros_message->top);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: left
  {
    size_t item_size = sizeof(ros_message->left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bottom
  {
    size_t item_size = sizeof(ros_message->bottom);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: right
  {
    size_t item_size = sizeof(ros_message->right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: depth
  {
    size_t item_size = sizeof(ros_message->depth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
size_t max_serialized_size_yolov8_msgs__msg__InferenceResult(
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

  // Field name: class_name
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

  // Field name: top
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: left
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: bottom
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: right
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: depth
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = yolov8_msgs__msg__InferenceResult;
    is_plain =
      (
      offsetof(DataType, depth) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
bool cdr_serialize_key_yolov8_msgs__msg__InferenceResult(
  const yolov8_msgs__msg__InferenceResult * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: class_name
  {
    const rosidl_runtime_c__String * str = &ros_message->class_name;
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

  // Field name: top
  {
    cdr << ros_message->top;
  }

  // Field name: left
  {
    cdr << ros_message->left;
  }

  // Field name: bottom
  {
    cdr << ros_message->bottom;
  }

  // Field name: right
  {
    cdr << ros_message->right;
  }

  // Field name: depth
  {
    cdr << ros_message->depth;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
size_t get_serialized_size_key_yolov8_msgs__msg__InferenceResult(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _InferenceResult__ros_msg_type * ros_message = static_cast<const _InferenceResult__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: class_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->class_name.size + 1);

  // Field name: top
  {
    size_t item_size = sizeof(ros_message->top);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: left
  {
    size_t item_size = sizeof(ros_message->left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bottom
  {
    size_t item_size = sizeof(ros_message->bottom);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: right
  {
    size_t item_size = sizeof(ros_message->right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: depth
  {
    size_t item_size = sizeof(ros_message->depth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_yolov8_msgs
size_t max_serialized_size_key_yolov8_msgs__msg__InferenceResult(
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
  // Field name: class_name
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

  // Field name: top
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: left
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: bottom
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: right
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: depth
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = yolov8_msgs__msg__InferenceResult;
    is_plain =
      (
      offsetof(DataType, depth) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _InferenceResult__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const yolov8_msgs__msg__InferenceResult * ros_message = static_cast<const yolov8_msgs__msg__InferenceResult *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_yolov8_msgs__msg__InferenceResult(ros_message, cdr);
}

static bool _InferenceResult__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  yolov8_msgs__msg__InferenceResult * ros_message = static_cast<yolov8_msgs__msg__InferenceResult *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_yolov8_msgs__msg__InferenceResult(cdr, ros_message);
}

static uint32_t _InferenceResult__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_yolov8_msgs__msg__InferenceResult(
      untyped_ros_message, 0));
}

static size_t _InferenceResult__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_yolov8_msgs__msg__InferenceResult(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_InferenceResult = {
  "yolov8_msgs::msg",
  "InferenceResult",
  _InferenceResult__cdr_serialize,
  _InferenceResult__cdr_deserialize,
  _InferenceResult__get_serialized_size,
  _InferenceResult__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _InferenceResult__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_InferenceResult,
  get_message_typesupport_handle_function,
  &yolov8_msgs__msg__InferenceResult__get_type_hash,
  &yolov8_msgs__msg__InferenceResult__get_type_description,
  &yolov8_msgs__msg__InferenceResult__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, yolov8_msgs, msg, InferenceResult)() {
  return &_InferenceResult__type_support;
}

#if defined(__cplusplus)
}
#endif
