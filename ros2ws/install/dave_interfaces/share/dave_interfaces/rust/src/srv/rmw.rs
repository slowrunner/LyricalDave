#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__Say_Request() -> *const std::ffi::c_void;
}

#[link(name = "dave_interfaces__rosidl_generator_c")]
extern "C" {
    fn dave_interfaces__srv__Say_Request__init(msg: *mut Say_Request) -> bool;
    fn dave_interfaces__srv__Say_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Say_Request>, size: usize) -> bool;
    fn dave_interfaces__srv__Say_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Say_Request>);
    fn dave_interfaces__srv__Say_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Say_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Say_Request>) -> bool;
}

// Corresponds to dave_interfaces__srv__Say_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Say_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub saystring: rosidl_runtime_rs::String,

}



impl Default for Say_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dave_interfaces__srv__Say_Request__init(&mut msg as *mut _) {
        panic!("Call to dave_interfaces__srv__Say_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Say_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Say_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Say_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Say_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Say_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Say_Request where Self: Sized {
  const TYPE_NAME: &'static str = "dave_interfaces/srv/Say_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__Say_Request() }
  }
}


#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__Say_Response() -> *const std::ffi::c_void;
}

#[link(name = "dave_interfaces__rosidl_generator_c")]
extern "C" {
    fn dave_interfaces__srv__Say_Response__init(msg: *mut Say_Response) -> bool;
    fn dave_interfaces__srv__Say_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Say_Response>, size: usize) -> bool;
    fn dave_interfaces__srv__Say_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Say_Response>);
    fn dave_interfaces__srv__Say_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Say_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Say_Response>) -> bool;
}

// Corresponds to dave_interfaces__srv__Say_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Say_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub spoken: bool,

}



impl Default for Say_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dave_interfaces__srv__Say_Response__init(&mut msg as *mut _) {
        panic!("Call to dave_interfaces__srv__Say_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Say_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Say_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Say_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Say_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Say_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Say_Response where Self: Sized {
  const TYPE_NAME: &'static str = "dave_interfaces/srv/Say_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__Say_Response() }
  }
}


#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__Dock_Request() -> *const std::ffi::c_void;
}

#[link(name = "dave_interfaces__rosidl_generator_c")]
extern "C" {
    fn dave_interfaces__srv__Dock_Request__init(msg: *mut Dock_Request) -> bool;
    fn dave_interfaces__srv__Dock_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Dock_Request>, size: usize) -> bool;
    fn dave_interfaces__srv__Dock_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Dock_Request>);
    fn dave_interfaces__srv__Dock_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Dock_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Dock_Request>) -> bool;
}

// Corresponds to dave_interfaces__srv__Dock_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Dock_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Dock_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dave_interfaces__srv__Dock_Request__init(&mut msg as *mut _) {
        panic!("Call to dave_interfaces__srv__Dock_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Dock_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Dock_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Dock_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Dock_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Dock_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Dock_Request where Self: Sized {
  const TYPE_NAME: &'static str = "dave_interfaces/srv/Dock_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__Dock_Request() }
  }
}


#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__Dock_Response() -> *const std::ffi::c_void;
}

#[link(name = "dave_interfaces__rosidl_generator_c")]
extern "C" {
    fn dave_interfaces__srv__Dock_Response__init(msg: *mut Dock_Response) -> bool;
    fn dave_interfaces__srv__Dock_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Dock_Response>, size: usize) -> bool;
    fn dave_interfaces__srv__Dock_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Dock_Response>);
    fn dave_interfaces__srv__Dock_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Dock_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Dock_Response>) -> bool;
}

// Corresponds to dave_interfaces__srv__Dock_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Dock_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub is_docked: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_charging: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Dock_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dave_interfaces__srv__Dock_Response__init(&mut msg as *mut _) {
        panic!("Call to dave_interfaces__srv__Dock_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Dock_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Dock_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Dock_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Dock_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Dock_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Dock_Response where Self: Sized {
  const TYPE_NAME: &'static str = "dave_interfaces/srv/Dock_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__Dock_Response() }
  }
}


#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__Undock_Request() -> *const std::ffi::c_void;
}

#[link(name = "dave_interfaces__rosidl_generator_c")]
extern "C" {
    fn dave_interfaces__srv__Undock_Request__init(msg: *mut Undock_Request) -> bool;
    fn dave_interfaces__srv__Undock_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Undock_Request>, size: usize) -> bool;
    fn dave_interfaces__srv__Undock_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Undock_Request>);
    fn dave_interfaces__srv__Undock_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Undock_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Undock_Request>) -> bool;
}

// Corresponds to dave_interfaces__srv__Undock_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Undock_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Undock_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dave_interfaces__srv__Undock_Request__init(&mut msg as *mut _) {
        panic!("Call to dave_interfaces__srv__Undock_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Undock_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Undock_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Undock_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Undock_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Undock_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Undock_Request where Self: Sized {
  const TYPE_NAME: &'static str = "dave_interfaces/srv/Undock_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__Undock_Request() }
  }
}


#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__Undock_Response() -> *const std::ffi::c_void;
}

#[link(name = "dave_interfaces__rosidl_generator_c")]
extern "C" {
    fn dave_interfaces__srv__Undock_Response__init(msg: *mut Undock_Response) -> bool;
    fn dave_interfaces__srv__Undock_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Undock_Response>, size: usize) -> bool;
    fn dave_interfaces__srv__Undock_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Undock_Response>);
    fn dave_interfaces__srv__Undock_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Undock_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Undock_Response>) -> bool;
}

// Corresponds to dave_interfaces__srv__Undock_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Undock_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub is_docked: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Undock_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dave_interfaces__srv__Undock_Response__init(&mut msg as *mut _) {
        panic!("Call to dave_interfaces__srv__Undock_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Undock_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Undock_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Undock_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__Undock_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Undock_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Undock_Response where Self: Sized {
  const TYPE_NAME: &'static str = "dave_interfaces/srv/Undock_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__Undock_Response() }
  }
}


#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__DriveDistance_Request() -> *const std::ffi::c_void;
}

#[link(name = "dave_interfaces__rosidl_generator_c")]
extern "C" {
    fn dave_interfaces__srv__DriveDistance_Request__init(msg: *mut DriveDistance_Request) -> bool;
    fn dave_interfaces__srv__DriveDistance_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DriveDistance_Request>, size: usize) -> bool;
    fn dave_interfaces__srv__DriveDistance_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DriveDistance_Request>);
    fn dave_interfaces__srv__DriveDistance_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DriveDistance_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<DriveDistance_Request>) -> bool;
}

// Corresponds to dave_interfaces__srv__DriveDistance_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DriveDistance_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub distance: f32,

    /// positive speed m/s
    pub speed: f32,

}



impl Default for DriveDistance_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dave_interfaces__srv__DriveDistance_Request__init(&mut msg as *mut _) {
        panic!("Call to dave_interfaces__srv__DriveDistance_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DriveDistance_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__DriveDistance_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__DriveDistance_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__DriveDistance_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DriveDistance_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DriveDistance_Request where Self: Sized {
  const TYPE_NAME: &'static str = "dave_interfaces/srv/DriveDistance_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__DriveDistance_Request() }
  }
}


#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__DriveDistance_Response() -> *const std::ffi::c_void;
}

#[link(name = "dave_interfaces__rosidl_generator_c")]
extern "C" {
    fn dave_interfaces__srv__DriveDistance_Response__init(msg: *mut DriveDistance_Response) -> bool;
    fn dave_interfaces__srv__DriveDistance_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DriveDistance_Response>, size: usize) -> bool;
    fn dave_interfaces__srv__DriveDistance_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DriveDistance_Response>);
    fn dave_interfaces__srv__DriveDistance_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DriveDistance_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<DriveDistance_Response>) -> bool;
}

// Corresponds to dave_interfaces__srv__DriveDistance_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DriveDistance_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,

}



impl Default for DriveDistance_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dave_interfaces__srv__DriveDistance_Response__init(&mut msg as *mut _) {
        panic!("Call to dave_interfaces__srv__DriveDistance_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DriveDistance_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__DriveDistance_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__DriveDistance_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__srv__DriveDistance_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DriveDistance_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DriveDistance_Response where Self: Sized {
  const TYPE_NAME: &'static str = "dave_interfaces/srv/DriveDistance_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__srv__DriveDistance_Response() }
  }
}






#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__dave_interfaces__srv__Say() -> *const std::ffi::c_void;
}

// Corresponds to dave_interfaces__srv__Say
#[allow(missing_docs, non_camel_case_types)]
pub struct Say;

impl rosidl_runtime_rs::Service for Say {
    type Request = Say_Request;
    type Response = Say_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__dave_interfaces__srv__Say() }
    }
}




#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__dave_interfaces__srv__Dock() -> *const std::ffi::c_void;
}

// Corresponds to dave_interfaces__srv__Dock
#[allow(missing_docs, non_camel_case_types)]
pub struct Dock;

impl rosidl_runtime_rs::Service for Dock {
    type Request = Dock_Request;
    type Response = Dock_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__dave_interfaces__srv__Dock() }
    }
}




#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__dave_interfaces__srv__Undock() -> *const std::ffi::c_void;
}

// Corresponds to dave_interfaces__srv__Undock
#[allow(missing_docs, non_camel_case_types)]
pub struct Undock;

impl rosidl_runtime_rs::Service for Undock {
    type Request = Undock_Request;
    type Response = Undock_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__dave_interfaces__srv__Undock() }
    }
}




#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__dave_interfaces__srv__DriveDistance() -> *const std::ffi::c_void;
}

// Corresponds to dave_interfaces__srv__DriveDistance
#[allow(missing_docs, non_camel_case_types)]
pub struct DriveDistance;

impl rosidl_runtime_rs::Service for DriveDistance {
    type Request = DriveDistance_Request;
    type Response = DriveDistance_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__dave_interfaces__srv__DriveDistance() }
    }
}


