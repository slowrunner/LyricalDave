// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dave_interfaces:srv/Undock.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dave_interfaces/srv/undock.h"


#ifndef DAVE_INTERFACES__SRV__DETAIL__UNDOCK__STRUCT_H_
#define DAVE_INTERFACES__SRV__DETAIL__UNDOCK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Undock in the package dave_interfaces.
typedef struct dave_interfaces__srv__Undock_Request
{
  uint8_t structure_needs_at_least_one_member;
} dave_interfaces__srv__Undock_Request;

// Struct for a sequence of dave_interfaces__srv__Undock_Request.
typedef struct dave_interfaces__srv__Undock_Request__Sequence
{
  dave_interfaces__srv__Undock_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dave_interfaces__srv__Undock_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/Undock in the package dave_interfaces.
typedef struct dave_interfaces__srv__Undock_Response
{
  bool is_docked;
  bool success;
} dave_interfaces__srv__Undock_Response;

// Struct for a sequence of dave_interfaces__srv__Undock_Response.
typedef struct dave_interfaces__srv__Undock_Response__Sequence
{
  dave_interfaces__srv__Undock_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dave_interfaces__srv__Undock_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  dave_interfaces__srv__Undock_Event__request__MAX_SIZE = 1
};
// response
enum
{
  dave_interfaces__srv__Undock_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Undock in the package dave_interfaces.
typedef struct dave_interfaces__srv__Undock_Event
{
  service_msgs__msg__ServiceEventInfo info;
  dave_interfaces__srv__Undock_Request__Sequence request;
  dave_interfaces__srv__Undock_Response__Sequence response;
} dave_interfaces__srv__Undock_Event;

// Struct for a sequence of dave_interfaces__srv__Undock_Event.
typedef struct dave_interfaces__srv__Undock_Event__Sequence
{
  dave_interfaces__srv__Undock_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dave_interfaces__srv__Undock_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DAVE_INTERFACES__SRV__DETAIL__UNDOCK__STRUCT_H_
