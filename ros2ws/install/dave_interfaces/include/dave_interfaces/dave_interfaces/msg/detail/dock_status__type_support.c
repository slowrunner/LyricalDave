// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dave_interfaces:msg/DockStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dave_interfaces/msg/detail/dock_status__rosidl_typesupport_introspection_c.h"
#include "dave_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dave_interfaces/msg/detail/dock_status__functions.h"
#include "dave_interfaces/msg/detail/dock_status__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void dave_interfaces__msg__DockStatus__rosidl_typesupport_introspection_c__DockStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dave_interfaces__msg__DockStatus__init(message_memory);
}

void dave_interfaces__msg__DockStatus__rosidl_typesupport_introspection_c__DockStatus_fini_function(void * message_memory)
{
  dave_interfaces__msg__DockStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember dave_interfaces__msg__DockStatus__rosidl_typesupport_introspection_c__DockStatus_message_member_array[2] = {
  {
    "is_docked",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dave_interfaces__msg__DockStatus, is_docked),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "is_charging",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dave_interfaces__msg__DockStatus, is_charging),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dave_interfaces__msg__DockStatus__rosidl_typesupport_introspection_c__DockStatus_message_members = {
  "dave_interfaces__msg",  // message namespace
  "DockStatus",  // message name
  2,  // number of fields
  sizeof(dave_interfaces__msg__DockStatus),
  false,  // has_any_key_member_
  dave_interfaces__msg__DockStatus__rosidl_typesupport_introspection_c__DockStatus_message_member_array,  // message members
  dave_interfaces__msg__DockStatus__rosidl_typesupport_introspection_c__DockStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  dave_interfaces__msg__DockStatus__rosidl_typesupport_introspection_c__DockStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dave_interfaces__msg__DockStatus__rosidl_typesupport_introspection_c__DockStatus_message_type_support_handle = {
  0,
  &dave_interfaces__msg__DockStatus__rosidl_typesupport_introspection_c__DockStatus_message_members,
  get_message_typesupport_handle_function,
  &dave_interfaces__msg__DockStatus__get_type_hash,
  &dave_interfaces__msg__DockStatus__get_type_description,
  &dave_interfaces__msg__DockStatus__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dave_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dave_interfaces, msg, DockStatus)() {
  if (!dave_interfaces__msg__DockStatus__rosidl_typesupport_introspection_c__DockStatus_message_type_support_handle.typesupport_identifier) {
    dave_interfaces__msg__DockStatus__rosidl_typesupport_introspection_c__DockStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dave_interfaces__msg__DockStatus__rosidl_typesupport_introspection_c__DockStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
