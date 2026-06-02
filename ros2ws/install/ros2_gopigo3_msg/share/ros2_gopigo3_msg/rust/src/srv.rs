#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to ros2_gopigo3_msg__srv__SPI_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SPI_Request {
    /// sent byte array
    pub data_out: Vec<u8>,

}



impl Default for SPI_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SPI_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SPI_Request {
  type RmwMsg = super::srv::rmw::SPI_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        data_out: msg.data_out.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        data_out: msg.data_out.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      data_out: msg.data_out
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to ros2_gopigo3_msg__srv__SPI_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SPI_Response {
    /// received byte array
    pub data_in: Vec<u8>,

}



impl Default for SPI_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SPI_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SPI_Response {
  type RmwMsg = super::srv::rmw::SPI_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        data_in: msg.data_in.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        data_in: msg.data_in.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      data_in: msg.data_in
          .into_iter()
          .collect(),
    }
  }
}






#[link(name = "ros2_gopigo3_msg__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ros2_gopigo3_msg__srv__SPI() -> *const std::ffi::c_void;
}

// Corresponds to ros2_gopigo3_msg__srv__SPI
#[allow(missing_docs, non_camel_case_types)]
pub struct SPI;

impl rosidl_runtime_rs::Service for SPI {
    type Request = SPI_Request;
    type Response = SPI_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ros2_gopigo3_msg__srv__SPI() }
    }
}


