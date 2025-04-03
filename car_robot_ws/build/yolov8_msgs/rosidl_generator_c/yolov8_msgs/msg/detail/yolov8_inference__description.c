// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from yolov8_msgs:msg/Yolov8Inference.idl
// generated code does not contain a copyright notice

#include "yolov8_msgs/msg/detail/yolov8_inference__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_yolov8_msgs
const rosidl_type_hash_t *
yolov8_msgs__msg__Yolov8Inference__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1f, 0x3d, 0xfc, 0x62, 0xc1, 0x9c, 0x6d, 0x84,
      0x69, 0x7c, 0x66, 0xbc, 0x59, 0xf8, 0xd9, 0xed,
      0xfe, 0x13, 0x9f, 0x1c, 0xc8, 0xeb, 0xe1, 0x7f,
      0xde, 0x04, 0xae, 0x4d, 0xcf, 0xb6, 0x4e, 0x7e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/header__functions.h"
#include "yolov8_msgs/msg/detail/inference_result__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
static const rosidl_type_hash_t yolov8_msgs__msg__InferenceResult__EXPECTED_HASH = {1, {
    0x76, 0x37, 0xb3, 0x6a, 0xf8, 0xf1, 0x3f, 0xa9,
    0x7c, 0x6c, 0xed, 0x12, 0x93, 0x9d, 0xd5, 0x41,
    0x2d, 0x01, 0x29, 0xa1, 0xbf, 0xb7, 0x52, 0xa3,
    0x2d, 0x89, 0xd6, 0xa5, 0xe0, 0x6a, 0x2e, 0x97,
  }};
#endif

static char yolov8_msgs__msg__Yolov8Inference__TYPE_NAME[] = "yolov8_msgs/msg/Yolov8Inference";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";
static char yolov8_msgs__msg__InferenceResult__TYPE_NAME[] = "yolov8_msgs/msg/InferenceResult";

// Define type names, field names, and default values
static char yolov8_msgs__msg__Yolov8Inference__FIELD_NAME__header[] = "header";
static char yolov8_msgs__msg__Yolov8Inference__FIELD_NAME__yolov8_inference[] = "yolov8_inference";

static rosidl_runtime_c__type_description__Field yolov8_msgs__msg__Yolov8Inference__FIELDS[] = {
  {
    {yolov8_msgs__msg__Yolov8Inference__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {yolov8_msgs__msg__Yolov8Inference__FIELD_NAME__yolov8_inference, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {yolov8_msgs__msg__InferenceResult__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription yolov8_msgs__msg__Yolov8Inference__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
  {
    {yolov8_msgs__msg__InferenceResult__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
yolov8_msgs__msg__Yolov8Inference__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {yolov8_msgs__msg__Yolov8Inference__TYPE_NAME, 31, 31},
      {yolov8_msgs__msg__Yolov8Inference__FIELDS, 2, 2},
    },
    {yolov8_msgs__msg__Yolov8Inference__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&yolov8_msgs__msg__InferenceResult__EXPECTED_HASH, yolov8_msgs__msg__InferenceResult__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = yolov8_msgs__msg__InferenceResult__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header\n"
  "InferenceResult[] yolov8_inference";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
yolov8_msgs__msg__Yolov8Inference__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {yolov8_msgs__msg__Yolov8Inference__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 58, 58},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
yolov8_msgs__msg__Yolov8Inference__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *yolov8_msgs__msg__Yolov8Inference__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    sources[3] = *yolov8_msgs__msg__InferenceResult__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
