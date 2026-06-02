// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dave_interfaces:msg/BatteryState.idl
// generated code does not contain a copyright notice
#include "dave_interfaces/msg/detail/battery_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
dave_interfaces__msg__BatteryState__init(dave_interfaces__msg__BatteryState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    dave_interfaces__msg__BatteryState__fini(msg);
    return false;
  }
  // volts
  // milliamps
  // watts
  // watthours
  // charging
  // capacity
  // percent
  // last_charge
  // last_discharge
  return true;
}

void
dave_interfaces__msg__BatteryState__fini(dave_interfaces__msg__BatteryState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // volts
  // milliamps
  // watts
  // watthours
  // charging
  // capacity
  // percent
  // last_charge
  // last_discharge
}

bool
dave_interfaces__msg__BatteryState__are_equal(const dave_interfaces__msg__BatteryState * lhs, const dave_interfaces__msg__BatteryState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // volts
  if (lhs->volts != rhs->volts) {
    return false;
  }
  // milliamps
  if (lhs->milliamps != rhs->milliamps) {
    return false;
  }
  // watts
  if (lhs->watts != rhs->watts) {
    return false;
  }
  // watthours
  if (lhs->watthours != rhs->watthours) {
    return false;
  }
  // charging
  if (lhs->charging != rhs->charging) {
    return false;
  }
  // capacity
  if (lhs->capacity != rhs->capacity) {
    return false;
  }
  // percent
  if (lhs->percent != rhs->percent) {
    return false;
  }
  // last_charge
  if (lhs->last_charge != rhs->last_charge) {
    return false;
  }
  // last_discharge
  if (lhs->last_discharge != rhs->last_discharge) {
    return false;
  }
  return true;
}

bool
dave_interfaces__msg__BatteryState__copy(
  const dave_interfaces__msg__BatteryState * input,
  dave_interfaces__msg__BatteryState * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // volts
  output->volts = input->volts;
  // milliamps
  output->milliamps = input->milliamps;
  // watts
  output->watts = input->watts;
  // watthours
  output->watthours = input->watthours;
  // charging
  output->charging = input->charging;
  // capacity
  output->capacity = input->capacity;
  // percent
  output->percent = input->percent;
  // last_charge
  output->last_charge = input->last_charge;
  // last_discharge
  output->last_discharge = input->last_discharge;
  return true;
}

dave_interfaces__msg__BatteryState *
dave_interfaces__msg__BatteryState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dave_interfaces__msg__BatteryState * msg = (dave_interfaces__msg__BatteryState *)allocator.allocate(sizeof(dave_interfaces__msg__BatteryState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dave_interfaces__msg__BatteryState));
  bool success = dave_interfaces__msg__BatteryState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dave_interfaces__msg__BatteryState__destroy(dave_interfaces__msg__BatteryState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dave_interfaces__msg__BatteryState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dave_interfaces__msg__BatteryState__Sequence__init(dave_interfaces__msg__BatteryState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dave_interfaces__msg__BatteryState * data = NULL;

  if (size) {
    data = (dave_interfaces__msg__BatteryState *)allocator.zero_allocate(size, sizeof(dave_interfaces__msg__BatteryState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dave_interfaces__msg__BatteryState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dave_interfaces__msg__BatteryState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
dave_interfaces__msg__BatteryState__Sequence__fini(dave_interfaces__msg__BatteryState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      dave_interfaces__msg__BatteryState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

dave_interfaces__msg__BatteryState__Sequence *
dave_interfaces__msg__BatteryState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dave_interfaces__msg__BatteryState__Sequence * array = (dave_interfaces__msg__BatteryState__Sequence *)allocator.allocate(sizeof(dave_interfaces__msg__BatteryState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dave_interfaces__msg__BatteryState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dave_interfaces__msg__BatteryState__Sequence__destroy(dave_interfaces__msg__BatteryState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dave_interfaces__msg__BatteryState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dave_interfaces__msg__BatteryState__Sequence__are_equal(const dave_interfaces__msg__BatteryState__Sequence * lhs, const dave_interfaces__msg__BatteryState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dave_interfaces__msg__BatteryState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dave_interfaces__msg__BatteryState__Sequence__copy(
  const dave_interfaces__msg__BatteryState__Sequence * input,
  dave_interfaces__msg__BatteryState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dave_interfaces__msg__BatteryState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dave_interfaces__msg__BatteryState * data =
      (dave_interfaces__msg__BatteryState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dave_interfaces__msg__BatteryState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dave_interfaces__msg__BatteryState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dave_interfaces__msg__BatteryState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
