#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to dave_interfaces__srv__Say_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Say_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub saystring: std::string::String,

}



impl Default for Say_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Say_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Say_Request {
  type RmwMsg = super::srv::rmw::Say_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        saystring: msg.saystring.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        saystring: msg.saystring.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      saystring: msg.saystring.to_string(),
    }
  }
}


// Corresponds to dave_interfaces__srv__Say_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Say_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub spoken: bool,

}



impl Default for Say_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Say_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Say_Response {
  type RmwMsg = super::srv::rmw::Say_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        spoken: msg.spoken,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      spoken: msg.spoken,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      spoken: msg.spoken,
    }
  }
}


// Corresponds to dave_interfaces__srv__Dock_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Dock_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Dock_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Dock_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Dock_Request {
  type RmwMsg = super::srv::rmw::Dock_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to dave_interfaces__srv__Dock_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Dock_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Dock_Response {
  type RmwMsg = super::srv::rmw::Dock_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        is_docked: msg.is_docked,
        is_charging: msg.is_charging,
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      is_docked: msg.is_docked,
      is_charging: msg.is_charging,
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      is_docked: msg.is_docked,
      is_charging: msg.is_charging,
      success: msg.success,
    }
  }
}


// Corresponds to dave_interfaces__srv__Undock_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Undock_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for Undock_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Undock_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Undock_Request {
  type RmwMsg = super::srv::rmw::Undock_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to dave_interfaces__srv__Undock_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Undock_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Undock_Response {
  type RmwMsg = super::srv::rmw::Undock_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        is_docked: msg.is_docked,
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      is_docked: msg.is_docked,
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      is_docked: msg.is_docked,
      success: msg.success,
    }
  }
}


// Corresponds to dave_interfaces__srv__DriveDistance_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::DriveDistance_Request::default())
  }
}

impl rosidl_runtime_rs::Message for DriveDistance_Request {
  type RmwMsg = super::srv::rmw::DriveDistance_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        distance: msg.distance,
        speed: msg.speed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      distance: msg.distance,
      speed: msg.speed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      distance: msg.distance,
      speed: msg.speed,
    }
  }
}


// Corresponds to dave_interfaces__srv__DriveDistance_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DriveDistance_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,

}



impl Default for DriveDistance_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::DriveDistance_Response::default())
  }
}

impl rosidl_runtime_rs::Message for DriveDistance_Response {
  type RmwMsg = super::srv::rmw::DriveDistance_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
    }
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


