#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to dave_interfaces__msg__BatteryState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BatteryState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::BatteryState::default())
  }
}

impl rosidl_runtime_rs::Message for BatteryState {
  type RmwMsg = super::msg::rmw::BatteryState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        volts: msg.volts,
        milliamps: msg.milliamps,
        watts: msg.watts,
        watthours: msg.watthours,
        charging: msg.charging,
        capacity: msg.capacity,
        percent: msg.percent,
        last_charge: msg.last_charge,
        last_discharge: msg.last_discharge,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      volts: msg.volts,
      milliamps: msg.milliamps,
      watts: msg.watts,
      watthours: msg.watthours,
      charging: msg.charging,
      capacity: msg.capacity,
      percent: msg.percent,
      last_charge: msg.last_charge,
      last_discharge: msg.last_discharge,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      volts: msg.volts,
      milliamps: msg.milliamps,
      watts: msg.watts,
      watthours: msg.watthours,
      charging: msg.charging,
      capacity: msg.capacity,
      percent: msg.percent,
      last_charge: msg.last_charge,
      last_discharge: msg.last_discharge,
    }
  }
}


// Corresponds to dave_interfaces__msg__DockStatus
/// dave_interfaces.msg.DockState.msg

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::DockStatus::default())
  }
}

impl rosidl_runtime_rs::Message for DockStatus {
  type RmwMsg = super::msg::rmw::DockStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        is_docked: msg.is_docked,
        is_charging: msg.is_charging,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      is_docked: msg.is_docked,
      is_charging: msg.is_charging,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      is_docked: msg.is_docked,
      is_charging: msg.is_charging,
    }
  }
}


