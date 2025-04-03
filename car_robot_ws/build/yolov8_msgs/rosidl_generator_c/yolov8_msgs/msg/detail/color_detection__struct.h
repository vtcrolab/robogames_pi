// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yolov8_msgs:msg/ColorDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "yolov8_msgs/msg/color_detection.h"


#ifndef YOLOV8_MSGS__MSG__DETAIL__COLOR_DETECTION__STRUCT_H_
#define YOLOV8_MSGS__MSG__DETAIL__COLOR_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'color_detected'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ColorDetection in the package yolov8_msgs.
/**
  * ColorDetection.msg
 */
typedef struct yolov8_msgs__msg__ColorDetection
{
  /// Detected color
  rosidl_runtime_c__String color_detected;
  /// Whether the object is detected or not
  bool detected;
} yolov8_msgs__msg__ColorDetection;

// Struct for a sequence of yolov8_msgs__msg__ColorDetection.
typedef struct yolov8_msgs__msg__ColorDetection__Sequence
{
  yolov8_msgs__msg__ColorDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yolov8_msgs__msg__ColorDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YOLOV8_MSGS__MSG__DETAIL__COLOR_DETECTION__STRUCT_H_
