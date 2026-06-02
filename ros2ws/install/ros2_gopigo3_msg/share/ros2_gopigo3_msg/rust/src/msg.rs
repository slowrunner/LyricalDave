#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to ros2_gopigo3_msg__msg__MotorStatus

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MotorStatus::default())
  }
}

impl rosidl_runtime_rs::Message for MotorStatus {
  type RmwMsg = super::msg::rmw::MotorStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        low_voltage: msg.low_voltage,
        overloaded: msg.overloaded,
        power: msg.power,
        encoder: msg.encoder,
        speed: msg.speed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      low_voltage: msg.low_voltage,
      overloaded: msg.overloaded,
      power: msg.power,
      encoder: msg.encoder,
      speed: msg.speed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      low_voltage: msg.low_voltage,
      overloaded: msg.overloaded,
      power: msg.power,
      encoder: msg.encoder,
      speed: msg.speed,
    }
  }
}


// Corresponds to ros2_gopigo3_msg__msg__MotorStatusLR

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MotorStatusLR {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub left: super::msg::MotorStatus,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right: super::msg::MotorStatus,

}



impl Default for MotorStatusLR {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MotorStatusLR::default())
  }
}

impl rosidl_runtime_rs::Message for MotorStatusLR {
  type RmwMsg = super::msg::rmw::MotorStatusLR;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        left: super::msg::MotorStatus::into_rmw_message(std::borrow::Cow::Owned(msg.left)).into_owned(),
        right: super::msg::MotorStatus::into_rmw_message(std::borrow::Cow::Owned(msg.right)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        left: super::msg::MotorStatus::into_rmw_message(std::borrow::Cow::Borrowed(&msg.left)).into_owned(),
        right: super::msg::MotorStatus::into_rmw_message(std::borrow::Cow::Borrowed(&msg.right)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      left: super::msg::MotorStatus::from_rmw_message(msg.left),
      right: super::msg::MotorStatus::from_rmw_message(msg.right),
    }
  }
}


