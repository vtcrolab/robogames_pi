// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from yolov8_msgs:msg/ColorDetection.idl
// generated code does not contain a copyright notice

#include "yolov8_msgs/msg/detail/color_detection__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
const rosidl_type_hash_t *
yolov8_msgs__msg__ColorDetection__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd2, 0x7d, 0xe2, 0xa0, 0x2b, 0x46, 0x10, 0x7b,
      0x81, 0x94, 0xab, 0xfd, 0x8e, 0xbd, 0xd5, 0x31,
      0x59, 0x51, 0xd7, 0xa8, 0xf7, 0xe3, 0x82, 0x19,
      0xf3, 0x93, 0xc1, 0x35, 0xd0, 0x71, 0xa2, 0x28,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char yolov8_msgs__msg__ColorDetection__TYPE_NAME[] = "yolov8_msgs/msg/ColorDetection";

// Define type names, field names, and default values
static char yolov8_msgs__msg__ColorDetection__FIELD_NAME__color_detected[] = "color_detected";
static char yolov8_msgs__msg__ColorDetection__FIELD_NAME__detected[] = "detected";

static rosidl_runtime_c__type_description__Field yolov8_msgs__msg__ColorDetection__FIELDS[] = {
  {
    {yolov8_msgs__msg__ColorDetection__FIELD_NAME__color_detected, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {yolov8_msgs__msg__ColorDetection__FIELD_NAME__detected, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
yolov8_msgs__msg__ColorDetection__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {yolov8_msgs__msg__ColorDetection__TYPE_NAME, 30, 30},
      {yolov8_msgs__msg__ColorDetection__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# ColorDetection.msg\n"
  "string color_detected  # Detected color\n"
  "bool detected          # Whether the object is detected or not";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
yolov8_msgs__msg__ColorDetection__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {yolov8_msgs__msg__ColorDetection__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 124, 124},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
yolov8_msgs__msg__ColorDetection__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *yolov8_msgs__msg__ColorDetection__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
