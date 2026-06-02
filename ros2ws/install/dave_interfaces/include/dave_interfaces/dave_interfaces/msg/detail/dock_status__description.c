// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from dave_interfaces:msg/DockStatus.idl
// generated code does not contain a copyright notice

#include "dave_interfaces/msg/detail/dock_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_dave_interfaces
const rosidl_type_hash_t *
dave_interfaces__msg__DockStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa8, 0x1f, 0x1d, 0x60, 0xf2, 0xb0, 0xae, 0x8d,
      0xe3, 0xc3, 0xdb, 0xba, 0x07, 0x3f, 0x3d, 0x87,
      0x04, 0x8b, 0xdd, 0x00, 0x71, 0xb2, 0xec, 0x61,
      0x32, 0x6c, 0x0d, 0x53, 0x24, 0x91, 0x8c, 0xbd,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char dave_interfaces__msg__DockStatus__TYPE_NAME[] = "dave_interfaces/msg/DockStatus";

// Define type names, field names, and default values
static char dave_interfaces__msg__DockStatus__FIELD_NAME__is_docked[] = "is_docked";
static char dave_interfaces__msg__DockStatus__FIELD_NAME__is_charging[] = "is_charging";

static rosidl_runtime_c__type_description__Field dave_interfaces__msg__DockStatus__FIELDS[] = {
  {
    {dave_interfaces__msg__DockStatus__FIELD_NAME__is_docked, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dave_interfaces__msg__DockStatus__FIELD_NAME__is_charging, 11, 11},
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
dave_interfaces__msg__DockStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dave_interfaces__msg__DockStatus__TYPE_NAME, 30, 30},
      {dave_interfaces__msg__DockStatus__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# dave_interfaces.msg.DockState.msg\n"
  " \n"
  "bool is_docked\n"
  "bool is_charging";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
dave_interfaces__msg__DockStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dave_interfaces__msg__DockStatus__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 70, 70},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dave_interfaces__msg__DockStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dave_interfaces__msg__DockStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
