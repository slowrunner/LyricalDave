// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dave_interfaces:msg/DockStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dave_interfaces/msg/dock_status.h"


#ifndef DAVE_INTERFACES__MSG__DETAIL__DOCK_STATUS__STRUCT_H_
#define DAVE_INTERFACES__MSG__DETAIL__DOCK_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/DockStatus in the package dave_interfaces.
/**
  * dave_interfaces.msg.DockState.msg
 */
typedef struct dave_interfaces__msg__DockStatus
{
  bool is_docked;
  bool is_charging;
} dave_interfaces__msg__DockStatus;

// Struct for a sequence of dave_interfaces__msg__DockStatus.
typedef struct dave_interfaces__msg__DockStatus__Sequence
{
  dave_interfaces__msg__DockStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dave_interfaces__msg__DockStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DAVE_INTERFACES__MSG__DETAIL__DOCK_STATUS__STRUCT_H_
