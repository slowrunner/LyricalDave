// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros2_gopigo3_msg:msg/MotorStatusLR.idl
// generated code does not contain a copyright notice

#include "ros2_gopigo3_msg/msg/detail/motor_status_lr__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros2_gopigo3_msg
const rosidl_type_hash_t *
ros2_gopigo3_msg__msg__MotorStatusLR__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x36, 0xd5, 0x37, 0xad, 0x7e, 0x18, 0xea, 0xd0,
      0xe0, 0x18, 0x89, 0xc7, 0x37, 0x1c, 0x80, 0x79,
      0x72, 0x8b, 0x5d, 0x36, 0xd8, 0x99, 0x53, 0x36,
      0x4b, 0x1f, 0x64, 0x70, 0x43, 0x4b, 0xc4, 0x5e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "ros2_gopigo3_msg/msg/detail/motor_status__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t ros2_gopigo3_msg__msg__MotorStatus__EXPECTED_HASH = {1, {
    0xdb, 0x22, 0x24, 0x00, 0x02, 0x4f, 0xa7, 0xf6,
    0x1d, 0x4a, 0xfb, 0x25, 0xca, 0x22, 0xbe, 0xd2,
    0x28, 0xbd, 0x4b, 0xdc, 0xd4, 0x4e, 0xc9, 0x20,
    0x9d, 0x95, 0xb3, 0x6a, 0x92, 0x5d, 0xed, 0xc9,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char ros2_gopigo3_msg__msg__MotorStatusLR__TYPE_NAME[] = "ros2_gopigo3_msg/msg/MotorStatusLR";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char ros2_gopigo3_msg__msg__MotorStatus__TYPE_NAME[] = "ros2_gopigo3_msg/msg/MotorStatus";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char ros2_gopigo3_msg__msg__MotorStatusLR__FIELD_NAME__header[] = "header";
static char ros2_gopigo3_msg__msg__MotorStatusLR__FIELD_NAME__left[] = "left";
static char ros2_gopigo3_msg__msg__MotorStatusLR__FIELD_NAME__right[] = "right";

static rosidl_runtime_c__type_description__Field ros2_gopigo3_msg__msg__MotorStatusLR__FIELDS[] = {
  {
    {ros2_gopigo3_msg__msg__MotorStatusLR__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_gopigo3_msg__msg__MotorStatusLR__FIELD_NAME__left, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros2_gopigo3_msg__msg__MotorStatus__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_gopigo3_msg__msg__MotorStatusLR__FIELD_NAME__right, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {ros2_gopigo3_msg__msg__MotorStatus__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription ros2_gopigo3_msg__msg__MotorStatusLR__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {ros2_gopigo3_msg__msg__MotorStatus__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros2_gopigo3_msg__msg__MotorStatusLR__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros2_gopigo3_msg__msg__MotorStatusLR__TYPE_NAME, 34, 34},
      {ros2_gopigo3_msg__msg__MotorStatusLR__FIELDS, 3, 3},
    },
    {ros2_gopigo3_msg__msg__MotorStatusLR__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&ros2_gopigo3_msg__msg__MotorStatus__EXPECTED_HASH, ros2_gopigo3_msg__msg__MotorStatus__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = ros2_gopigo3_msg__msg__MotorStatus__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header\n"
  "MotorStatus left\n"
  "MotorStatus right";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros2_gopigo3_msg__msg__MotorStatusLR__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros2_gopigo3_msg__msg__MotorStatusLR__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 58, 58},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros2_gopigo3_msg__msg__MotorStatusLR__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros2_gopigo3_msg__msg__MotorStatusLR__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *ros2_gopigo3_msg__msg__MotorStatus__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
