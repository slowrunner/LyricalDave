#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__msg__BatteryState() -> *const std::ffi::c_void;
}

#[link(name = "dave_interfaces__rosidl_generator_c")]
extern "C" {
    fn dave_interfaces__msg__BatteryState__init(msg: *mut BatteryState) -> bool;
    fn dave_interfaces__msg__BatteryState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<BatteryState>, size: usize) -> bool;
    fn dave_interfaces__msg__BatteryState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<BatteryState>);
    fn dave_interfaces__msg__BatteryState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<BatteryState>, out_seq: *mut rosidl_runtime_rs::Sequence<BatteryState>) -> bool;
}

// Corresponds to dave_interfaces__msg__BatteryState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BatteryState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub volts: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub milliamps: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub watts: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub watthours: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub charging: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub capacity: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub percent: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub last_charge: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub last_discharge: f32,

}



impl Default for BatteryState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dave_interfaces__msg__BatteryState__init(&mut msg as *mut _) {
        panic!("Call to dave_interfaces__msg__BatteryState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for BatteryState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__msg__BatteryState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__msg__BatteryState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__msg__BatteryState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for BatteryState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for BatteryState where Self: Sized {
  const TYPE_NAME: &'static str = "dave_interfaces/msg/BatteryState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__msg__BatteryState() }
  }
}


#[link(name = "dave_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__msg__DockStatus() -> *const std::ffi::c_void;
}

#[link(name = "dave_interfaces__rosidl_generator_c")]
extern "C" {
    fn dave_interfaces__msg__DockStatus__init(msg: *mut DockStatus) -> bool;
    fn dave_interfaces__msg__DockStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DockStatus>, size: usize) -> bool;
    fn dave_interfaces__msg__DockStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DockStatus>);
    fn dave_interfaces__msg__DockStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DockStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<DockStatus>) -> bool;
}

// Corresponds to dave_interfaces__msg__DockStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// dave_interfaces.msg.DockState.msg

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DockStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub is_docked: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_charging: bool,

}



impl Default for DockStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !dave_interfaces__msg__DockStatus__init(&mut msg as *mut _) {
        panic!("Call to dave_interfaces__msg__DockStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DockStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__msg__DockStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__msg__DockStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { dave_interfaces__msg__DockStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DockStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DockStatus where Self: Sized {
  const TYPE_NAME: &'static str = "dave_interfaces/msg/DockStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__dave_interfaces__msg__DockStatus() }
  }
}


