// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros2_gopigo3_msg:msg/MotorStatus.idl
// generated code does not contain a copyright notice

#include "ros2_gopigo3_msg/msg/detail/motor_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros2_gopigo3_msg
const rosidl_type_hash_t *
ros2_gopigo3_msg__msg__MotorStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xdb, 0x22, 0x24, 0x00, 0x02, 0x4f, 0xa7, 0xf6,
      0x1d, 0x4a, 0xfb, 0x25, 0xca, 0x22, 0xbe, 0xd2,
      0x28, 0xbd, 0x4b, 0xdc, 0xd4, 0x4e, 0xc9, 0x20,
      0x9d, 0x95, 0xb3, 0x6a, 0x92, 0x5d, 0xed, 0xc9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ros2_gopigo3_msg__msg__MotorStatus__TYPE_NAME[] = "ros2_gopigo3_msg/msg/MotorStatus";

// Define type names, field names, and default values
static char ros2_gopigo3_msg__msg__MotorStatus__FIELD_NAME__low_voltage[] = "low_voltage";
static char ros2_gopigo3_msg__msg__MotorStatus__FIELD_NAME__overloaded[] = "overloaded";
static char ros2_gopigo3_msg__msg__MotorStatus__FIELD_NAME__power[] = "power";
static char ros2_gopigo3_msg__msg__MotorStatus__FIELD_NAME__encoder[] = "encoder";
static char ros2_gopigo3_msg__msg__MotorStatus__FIELD_NAME__speed[] = "speed";

static rosidl_runtime_c__type_description__Field ros2_gopigo3_msg__msg__MotorStatus__FIELDS[] = {
  {
    {ros2_gopigo3_msg__msg__MotorStatus__FIELD_NAME__low_voltage, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_gopigo3_msg__msg__MotorStatus__FIELD_NAME__overloaded, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_gopigo3_msg__msg__MotorStatus__FIELD_NAME__power, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_gopigo3_msg__msg__MotorStatus__FIELD_NAME__encoder, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_gopigo3_msg__msg__MotorStatus__FIELD_NAME__speed, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros2_gopigo3_msg__msg__MotorStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros2_gopigo3_msg__msg__MotorStatus__TYPE_NAME, 32, 32},
      {ros2_gopigo3_msg__msg__MotorStatus__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool low_voltage\n"
  "bool overloaded\n"
  "int8 power      # PWM duty cycle -100 ... 100\n"
  "float32 encoder # degree\n"
  "float32 speed   # degree per second";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros2_gopigo3_msg__msg__MotorStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros2_gopigo3_msg__msg__MotorStatus__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 140, 140},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros2_gopigo3_msg__msg__MotorStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros2_gopigo3_msg__msg__MotorStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
