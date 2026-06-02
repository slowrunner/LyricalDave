// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dave_interfaces:msg/BatteryState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dave_interfaces/msg/battery_state.h"


#ifndef DAVE_INTERFACES__MSG__DETAIL__BATTERY_STATE__STRUCT_H_
#define DAVE_INTERFACES__MSG__DETAIL__BATTERY_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/BatteryState in the package dave_interfaces.
typedef struct dave_interfaces__msg__BatteryState
{
  std_msgs__msg__Header header;
  float volts;
  float milliamps;
  float watts;
  float watthours;
  bool charging;
  int16_t capacity;
  int16_t percent;
  float last_charge;
  float last_discharge;
} dave_interfaces__msg__BatteryState;

// Struct for a sequence of dave_interfaces__msg__BatteryState.
typedef struct dave_interfaces__msg__BatteryState__Sequence
{
  dave_interfaces__msg__BatteryState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dave_interfaces__msg__BatteryState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DAVE_INTERFACES__MSG__DETAIL__BATTERY_STATE__STRUCT_H_
