// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from dave_interfaces:srv/Dock.idl
// generated code does not contain a copyright notice

#include "dave_interfaces/srv/detail/dock__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_dave_interfaces
const rosidl_type_hash_t *
dave_interfaces__srv__Dock__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc0, 0x07, 0x65, 0x15, 0x72, 0xcd, 0x64, 0x71,
      0x3e, 0x9e, 0xa2, 0x73, 0x44, 0x4d, 0xcf, 0xaa,
      0x15, 0xef, 0xbe, 0xe8, 0x80, 0xe1, 0x78, 0xbf,
      0x6d, 0x90, 0x33, 0x33, 0xab, 0xb6, 0x3e, 0xe5,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_dave_interfaces
const rosidl_type_hash_t *
dave_interfaces__srv__Dock_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x60, 0xe5, 0x41, 0x53, 0x5a, 0xa7, 0x79, 0x15,
      0x59, 0xa6, 0x2e, 0x4a, 0x73, 0x57, 0x01, 0xf9,
      0x0a, 0xce, 0xa6, 0x50, 0x37, 0xbc, 0xef, 0xed,
      0x38, 0x1a, 0x97, 0xa7, 0xf9, 0xfd, 0x23, 0x2a,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_dave_interfaces
const rosidl_type_hash_t *
dave_interfaces__srv__Dock_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x73, 0xf2, 0x2f, 0x0d, 0x41, 0xdf, 0x90, 0xae,
      0x8d, 0x83, 0x30, 0x04, 0xa2, 0x5c, 0x65, 0xb3,
      0x40, 0x70, 0x51, 0x0c, 0xf3, 0xd6, 0x5a, 0x3f,
      0xcf, 0x87, 0x82, 0xb2, 0x4e, 0x1a, 0x57, 0xbe,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_dave_interfaces
const rosidl_type_hash_t *
dave_interfaces__srv__Dock_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xaf, 0x26, 0xf9, 0xe6, 0x01, 0xa3, 0x01, 0xd8,
      0xf7, 0x9d, 0xf1, 0xe2, 0x9f, 0x8e, 0x19, 0xb0,
      0xd4, 0x58, 0x1a, 0xd8, 0x82, 0x00, 0x5c, 0x98,
      0x44, 0xb9, 0x98, 0x4d, 0xac, 0x53, 0xba, 0xa8,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char dave_interfaces__srv__Dock__TYPE_NAME[] = "dave_interfaces/srv/Dock";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char dave_interfaces__srv__Dock_Event__TYPE_NAME[] = "dave_interfaces/srv/Dock_Event";
static char dave_interfaces__srv__Dock_Request__TYPE_NAME[] = "dave_interfaces/srv/Dock_Request";
static char dave_interfaces__srv__Dock_Response__TYPE_NAME[] = "dave_interfaces/srv/Dock_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char dave_interfaces__srv__Dock__FIELD_NAME__request_message[] = "request_message";
static char dave_interfaces__srv__Dock__FIELD_NAME__response_message[] = "response_message";
static char dave_interfaces__srv__Dock__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field dave_interfaces__srv__Dock__FIELDS[] = {
  {
    {dave_interfaces__srv__Dock__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {dave_interfaces__srv__Dock_Request__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {dave_interfaces__srv__Dock__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {dave_interfaces__srv__Dock_Response__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {dave_interfaces__srv__Dock__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {dave_interfaces__srv__Dock_Event__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription dave_interfaces__srv__Dock__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {dave_interfaces__srv__Dock_Event__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {dave_interfaces__srv__Dock_Request__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {dave_interfaces__srv__Dock_Response__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
dave_interfaces__srv__Dock__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dave_interfaces__srv__Dock__TYPE_NAME, 24, 24},
      {dave_interfaces__srv__Dock__FIELDS, 3, 3},
    },
    {dave_interfaces__srv__Dock__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = dave_interfaces__srv__Dock_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = dave_interfaces__srv__Dock_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = dave_interfaces__srv__Dock_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char dave_interfaces__srv__Dock_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field dave_interfaces__srv__Dock_Request__FIELDS[] = {
  {
    {dave_interfaces__srv__Dock_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
dave_interfaces__srv__Dock_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dave_interfaces__srv__Dock_Request__TYPE_NAME, 32, 32},
      {dave_interfaces__srv__Dock_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char dave_interfaces__srv__Dock_Response__FIELD_NAME__is_docked[] = "is_docked";
static char dave_interfaces__srv__Dock_Response__FIELD_NAME__is_charging[] = "is_charging";
static char dave_interfaces__srv__Dock_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field dave_interfaces__srv__Dock_Response__FIELDS[] = {
  {
    {dave_interfaces__srv__Dock_Response__FIELD_NAME__is_docked, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dave_interfaces__srv__Dock_Response__FIELD_NAME__is_charging, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dave_interfaces__srv__Dock_Response__FIELD_NAME__success, 7, 7},
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
dave_interfaces__srv__Dock_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dave_interfaces__srv__Dock_Response__TYPE_NAME, 33, 33},
      {dave_interfaces__srv__Dock_Response__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char dave_interfaces__srv__Dock_Event__FIELD_NAME__info[] = "info";
static char dave_interfaces__srv__Dock_Event__FIELD_NAME__request[] = "request";
static char dave_interfaces__srv__Dock_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field dave_interfaces__srv__Dock_Event__FIELDS[] = {
  {
    {dave_interfaces__srv__Dock_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {dave_interfaces__srv__Dock_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {dave_interfaces__srv__Dock_Request__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {dave_interfaces__srv__Dock_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {dave_interfaces__srv__Dock_Response__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription dave_interfaces__srv__Dock_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {dave_interfaces__srv__Dock_Request__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {dave_interfaces__srv__Dock_Response__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
dave_interfaces__srv__Dock_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dave_interfaces__srv__Dock_Event__TYPE_NAME, 30, 30},
      {dave_interfaces__srv__Dock_Event__FIELDS, 3, 3},
    },
    {dave_interfaces__srv__Dock_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = dave_interfaces__srv__Dock_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = dave_interfaces__srv__Dock_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# dave_interfaces.srv.Dock.srv \n"
  "# Request\n"
  "---\n"
  "# Result\n"
  "bool is_docked\n"
  "bool is_charging\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
dave_interfaces__srv__Dock__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dave_interfaces__srv__Dock__TYPE_NAME, 24, 24},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 100, 100},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
dave_interfaces__srv__Dock_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dave_interfaces__srv__Dock_Request__TYPE_NAME, 32, 32},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
dave_interfaces__srv__Dock_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dave_interfaces__srv__Dock_Response__TYPE_NAME, 33, 33},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
dave_interfaces__srv__Dock_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dave_interfaces__srv__Dock_Event__TYPE_NAME, 30, 30},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dave_interfaces__srv__Dock__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dave_interfaces__srv__Dock__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *dave_interfaces__srv__Dock_Event__get_individual_type_description_source(NULL);
    sources[3] = *dave_interfaces__srv__Dock_Request__get_individual_type_description_source(NULL);
    sources[4] = *dave_interfaces__srv__Dock_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dave_interfaces__srv__Dock_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dave_interfaces__srv__Dock_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dave_interfaces__srv__Dock_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dave_interfaces__srv__Dock_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dave_interfaces__srv__Dock_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dave_interfaces__srv__Dock_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *dave_interfaces__srv__Dock_Request__get_individual_type_description_source(NULL);
    sources[3] = *dave_interfaces__srv__Dock_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
