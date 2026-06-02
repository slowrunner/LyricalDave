#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "ros2_gopigo3_msg__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2_gopigo3_msg__msg__MotorStatus() -> *const std::ffi::c_void;
}

#[link(name = "ros2_gopigo3_msg__rosidl_generator_c")]
extern "C" {
    fn ros2_gopigo3_msg__msg__MotorStatus__init(msg: *mut MotorStatus) -> bool;
    fn ros2_gopigo3_msg__msg__MotorStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MotorStatus>, size: usize) -> bool;
    fn ros2_gopigo3_msg__msg__MotorStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MotorStatus>);
    fn ros2_gopigo3_msg__msg__MotorStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MotorStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<MotorStatus>) -> bool;
}

// Corresponds to ros2_gopigo3_msg__msg__MotorStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MotorStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub low_voltage: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub overloaded: bool,

    /// PWM duty cycle -100 ... 100
    pub power: i8,

    /// degree
    pub encoder: f32,

    /// degree per second
    pub speed: f32,

}



impl Default for MotorStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2_gopigo3_msg__msg__MotorStatus__init(&mut msg as *mut _) {
        panic!("Call to ros2_gopigo3_msg__msg__MotorStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MotorStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_gopigo3_msg__msg__MotorStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_gopigo3_msg__msg__MotorStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_gopigo3_msg__msg__MotorStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MotorStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MotorStatus where Self: Sized {
  const TYPE_NAME: &'static str = "ros2_gopigo3_msg/msg/MotorStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2_gopigo3_msg__msg__MotorStatus() }
  }
}


#[link(name = "ros2_gopigo3_msg__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2_gopigo3_msg__msg__MotorStatusLR() -> *const std::ffi::c_void;
}

#[link(name = "ros2_gopigo3_msg__rosidl_generator_c")]
extern "C" {
    fn ros2_gopigo3_msg__msg__MotorStatusLR__init(msg: *mut MotorStatusLR) -> bool;
    fn ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MotorStatusLR>, size: usize) -> bool;
    fn ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MotorStatusLR>);
    fn ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MotorStatusLR>, out_seq: *mut rosidl_runtime_rs::Sequence<MotorStatusLR>) -> bool;
}

// Corresponds to ros2_gopigo3_msg__msg__MotorStatusLR
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MotorStatusLR {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub left: super::super::msg::rmw::MotorStatus,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right: super::super::msg::rmw::MotorStatus,

}



impl Default for MotorStatusLR {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2_gopigo3_msg__msg__MotorStatusLR__init(&mut msg as *mut _) {
        panic!("Call to ros2_gopigo3_msg__msg__MotorStatusLR__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MotorStatusLR {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MotorStatusLR {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MotorStatusLR where Self: Sized {
  const TYPE_NAME: &'static str = "ros2_gopigo3_msg/msg/MotorStatusLR";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2_gopigo3_msg__msg__MotorStatusLR() }
  }
}


