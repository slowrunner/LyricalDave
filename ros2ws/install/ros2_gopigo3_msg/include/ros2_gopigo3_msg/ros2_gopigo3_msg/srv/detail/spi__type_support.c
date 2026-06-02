// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ros2_gopigo3_msg:srv/SPI.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ros2_gopigo3_msg/srv/detail/spi__rosidl_typesupport_introspection_c.h"
#include "ros2_gopigo3_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ros2_gopigo3_msg/srv/detail/spi__functions.h"
#include "ros2_gopigo3_msg/srv/detail/spi__struct.h"
#include "rosidl_buffer/c_helpers.h"


// Include directives for member types
// Member `data_out`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros2_gopigo3_msg__srv__SPI_Request__init(message_memory);
}

void ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_fini_function(void * message_memory)
{
  ros2_gopigo3_msg__srv__SPI_Request__fini(message_memory);
}

size_t ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__size_function__SPI_Request__data_out(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  return member->size;
}

const void * ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__get_const_function__SPI_Request__data_out(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  return &member->data[index];
}

void * ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__get_function__SPI_Request__data_out(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  return &member->data[index];
}

void ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__fetch_function__SPI_Request__data_out(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__get_const_function__SPI_Request__data_out(untyped_member, index));
  uint8_t * value = (uint8_t *)(untyped_value);
  *value = *item;
}

void ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__assign_function__SPI_Request__data_out(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__get_function__SPI_Request__data_out(untyped_member, index));
  const uint8_t * value = (const uint8_t *)(untyped_value);
  *item = *value;
}

bool ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__resize_function__SPI_Request__data_out(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_member_array[1] = {
  {
    "data_out",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_gopigo3_msg__srv__SPI_Request, data_out),  // bytes offset in struct
    NULL,  // default value
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__size_function__SPI_Request__data_out,  // size() function pointer
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__get_const_function__SPI_Request__data_out,  // get_const(index) function pointer
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__get_function__SPI_Request__data_out,  // get(index) function pointer
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__fetch_function__SPI_Request__data_out,  // fetch(index, &value) function pointer
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__assign_function__SPI_Request__data_out,  // assign(index, value) function pointer
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__resize_function__SPI_Request__data_out,  // resize(index) function pointer
    true  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_members = {
  "ros2_gopigo3_msg__srv",  // message namespace
  "SPI_Request",  // message name
  1,  // number of fields
  sizeof(ros2_gopigo3_msg__srv__SPI_Request),
  false,  // has_any_key_member_
  ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_member_array,  // message members
  ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_type_support_handle = {
  0,
  &ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_members,
  get_message_typesupport_handle_function,
  &ros2_gopigo3_msg__srv__SPI_Request__get_type_hash,
  &ros2_gopigo3_msg__srv__SPI_Request__get_type_description,
  &ros2_gopigo3_msg__srv__SPI_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_gopigo3_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Request)() {
  if (!ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_type_support_handle.typesupport_identifier) {
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ros2_gopigo3_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__functions.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__struct.h"
// already included above
// #include "rosidl_buffer/c_helpers.h"


// Include directives for member types
// Member `data_in`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros2_gopigo3_msg__srv__SPI_Response__init(message_memory);
}

void ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_fini_function(void * message_memory)
{
  ros2_gopigo3_msg__srv__SPI_Response__fini(message_memory);
}

size_t ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__size_function__SPI_Response__data_in(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  return member->size;
}

const void * ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__get_const_function__SPI_Response__data_in(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  return &member->data[index];
}

void * ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__get_function__SPI_Response__data_in(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  return &member->data[index];
}

void ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__fetch_function__SPI_Response__data_in(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__get_const_function__SPI_Response__data_in(untyped_member, index));
  uint8_t * value = (uint8_t *)(untyped_value);
  *value = *item;
}

void ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__assign_function__SPI_Response__data_in(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__get_function__SPI_Response__data_in(untyped_member, index));
  const uint8_t * value = (const uint8_t *)(untyped_value);
  *item = *value;
}

bool ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__resize_function__SPI_Response__data_in(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  if (member->is_rosidl_buffer) {
    rosidl_buffer_uint8_throw_if_not_cpu((const void *)member->data);
  }
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_member_array[1] = {
  {
    "data_in",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_gopigo3_msg__srv__SPI_Response, data_in),  // bytes offset in struct
    NULL,  // default value
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__size_function__SPI_Response__data_in,  // size() function pointer
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__get_const_function__SPI_Response__data_in,  // get_const(index) function pointer
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__get_function__SPI_Response__data_in,  // get(index) function pointer
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__fetch_function__SPI_Response__data_in,  // fetch(index, &value) function pointer
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__assign_function__SPI_Response__data_in,  // assign(index, value) function pointer
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__resize_function__SPI_Response__data_in,  // resize(index) function pointer
    true  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_members = {
  "ros2_gopigo3_msg__srv",  // message namespace
  "SPI_Response",  // message name
  1,  // number of fields
  sizeof(ros2_gopigo3_msg__srv__SPI_Response),
  false,  // has_any_key_member_
  ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_member_array,  // message members
  ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_type_support_handle = {
  0,
  &ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_members,
  get_message_typesupport_handle_function,
  &ros2_gopigo3_msg__srv__SPI_Response__get_type_hash,
  &ros2_gopigo3_msg__srv__SPI_Response__get_type_description,
  &ros2_gopigo3_msg__srv__SPI_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_gopigo3_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Response)() {
  if (!ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_type_support_handle.typesupport_identifier) {
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ros2_gopigo3_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__functions.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "ros2_gopigo3_msg/srv/spi.h"
// Member `request`
// Member `response`
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros2_gopigo3_msg__srv__SPI_Event__init(message_memory);
}

void ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_fini_function(void * message_memory)
{
  ros2_gopigo3_msg__srv__SPI_Event__fini(message_memory);
}

size_t ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__size_function__SPI_Event__request(
  const void * untyped_member)
{
  const ros2_gopigo3_msg__srv__SPI_Request__Sequence * member =
    (const ros2_gopigo3_msg__srv__SPI_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__get_const_function__SPI_Event__request(
  const void * untyped_member, size_t index)
{
  const ros2_gopigo3_msg__srv__SPI_Request__Sequence * member =
    (const ros2_gopigo3_msg__srv__SPI_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__get_function__SPI_Event__request(
  void * untyped_member, size_t index)
{
  ros2_gopigo3_msg__srv__SPI_Request__Sequence * member =
    (ros2_gopigo3_msg__srv__SPI_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__fetch_function__SPI_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const ros2_gopigo3_msg__srv__SPI_Request * item =
    ((const ros2_gopigo3_msg__srv__SPI_Request *)
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__get_const_function__SPI_Event__request(untyped_member, index));
  ros2_gopigo3_msg__srv__SPI_Request * value =
    (ros2_gopigo3_msg__srv__SPI_Request *)(untyped_value);
  *value = *item;
}

void ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__assign_function__SPI_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  ros2_gopigo3_msg__srv__SPI_Request * item =
    ((ros2_gopigo3_msg__srv__SPI_Request *)
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__get_function__SPI_Event__request(untyped_member, index));
  const ros2_gopigo3_msg__srv__SPI_Request * value =
    (const ros2_gopigo3_msg__srv__SPI_Request *)(untyped_value);
  *item = *value;
}

bool ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__resize_function__SPI_Event__request(
  void * untyped_member, size_t size)
{
  ros2_gopigo3_msg__srv__SPI_Request__Sequence * member =
    (ros2_gopigo3_msg__srv__SPI_Request__Sequence *)(untyped_member);
  ros2_gopigo3_msg__srv__SPI_Request__Sequence__fini(member);
  return ros2_gopigo3_msg__srv__SPI_Request__Sequence__init(member, size);
}

size_t ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__size_function__SPI_Event__response(
  const void * untyped_member)
{
  const ros2_gopigo3_msg__srv__SPI_Response__Sequence * member =
    (const ros2_gopigo3_msg__srv__SPI_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__get_const_function__SPI_Event__response(
  const void * untyped_member, size_t index)
{
  const ros2_gopigo3_msg__srv__SPI_Response__Sequence * member =
    (const ros2_gopigo3_msg__srv__SPI_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__get_function__SPI_Event__response(
  void * untyped_member, size_t index)
{
  ros2_gopigo3_msg__srv__SPI_Response__Sequence * member =
    (ros2_gopigo3_msg__srv__SPI_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__fetch_function__SPI_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const ros2_gopigo3_msg__srv__SPI_Response * item =
    ((const ros2_gopigo3_msg__srv__SPI_Response *)
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__get_const_function__SPI_Event__response(untyped_member, index));
  ros2_gopigo3_msg__srv__SPI_Response * value =
    (ros2_gopigo3_msg__srv__SPI_Response *)(untyped_value);
  *value = *item;
}

void ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__assign_function__SPI_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  ros2_gopigo3_msg__srv__SPI_Response * item =
    ((ros2_gopigo3_msg__srv__SPI_Response *)
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__get_function__SPI_Event__response(untyped_member, index));
  const ros2_gopigo3_msg__srv__SPI_Response * value =
    (const ros2_gopigo3_msg__srv__SPI_Response *)(untyped_value);
  *item = *value;
}

bool ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__resize_function__SPI_Event__response(
  void * untyped_member, size_t size)
{
  ros2_gopigo3_msg__srv__SPI_Response__Sequence * member =
    (ros2_gopigo3_msg__srv__SPI_Response__Sequence *)(untyped_member);
  ros2_gopigo3_msg__srv__SPI_Response__Sequence__fini(member);
  return ros2_gopigo3_msg__srv__SPI_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_gopigo3_msg__srv__SPI_Event, info),  // bytes offset in struct
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
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(ros2_gopigo3_msg__srv__SPI_Event, request),  // bytes offset in struct
    NULL,  // default value
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__size_function__SPI_Event__request,  // size() function pointer
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__get_const_function__SPI_Event__request,  // get_const(index) function pointer
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__get_function__SPI_Event__request,  // get(index) function pointer
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__fetch_function__SPI_Event__request,  // fetch(index, &value) function pointer
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__assign_function__SPI_Event__request,  // assign(index, value) function pointer
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__resize_function__SPI_Event__request,  // resize(index) function pointer
    false  // is_rosidl_buffer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(ros2_gopigo3_msg__srv__SPI_Event, response),  // bytes offset in struct
    NULL,  // default value
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__size_function__SPI_Event__response,  // size() function pointer
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__get_const_function__SPI_Event__response,  // get_const(index) function pointer
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__get_function__SPI_Event__response,  // get(index) function pointer
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__fetch_function__SPI_Event__response,  // fetch(index, &value) function pointer
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__assign_function__SPI_Event__response,  // assign(index, value) function pointer
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__resize_function__SPI_Event__response,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_message_members = {
  "ros2_gopigo3_msg__srv",  // message namespace
  "SPI_Event",  // message name
  3,  // number of fields
  sizeof(ros2_gopigo3_msg__srv__SPI_Event),
  false,  // has_any_key_member_
  ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_message_member_array,  // message members
  ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_message_type_support_handle = {
  0,
  &ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_message_members,
  get_message_typesupport_handle_function,
  &ros2_gopigo3_msg__srv__SPI_Event__get_type_hash,
  &ros2_gopigo3_msg__srv__SPI_Event__get_type_description,
  &ros2_gopigo3_msg__srv__SPI_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_gopigo3_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Event)() {
  ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Request)();
  ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Response)();
  if (!ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_message_type_support_handle.typesupport_identifier) {
    ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ros2_gopigo3_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_members = {
  "ros2_gopigo3_msg__srv",  // service namespace
  "SPI",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_Request_message_type_support_handle,
  NULL,  // response message
  // ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_Response_message_type_support_handle
  NULL  // event_message
  // ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_Response_message_type_support_handle
};


static rosidl_service_type_support_t ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_type_support_handle = {
  0,
  &ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_members,
  get_service_typesupport_handle_function,
  &ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_type_support_handle,
  &ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_type_support_handle,
  &ros2_gopigo3_msg__srv__SPI_Event__rosidl_typesupport_introspection_c__SPI_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    ros2_gopigo3_msg,
    srv,
    SPI
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    ros2_gopigo3_msg,
    srv,
    SPI
  ),
  &ros2_gopigo3_msg__srv__SPI__get_type_hash,
  &ros2_gopigo3_msg__srv__SPI__get_type_description,
  &ros2_gopigo3_msg__srv__SPI__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_gopigo3_msg
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI)(void) {
  if (!ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_type_support_handle.typesupport_identifier) {
    ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Event)()->data;
  }

  return &ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_type_support_handle;
}
