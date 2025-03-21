// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from manipulator_interfaces:srv/MoveToPose.idl
// generated code does not contain a copyright notice

#ifndef MANIPULATOR_INTERFACES__SRV__DETAIL__MOVE_TO_POSE__TRAITS_HPP_
#define MANIPULATOR_INTERFACES__SRV__DETAIL__MOVE_TO_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "manipulator_interfaces/srv/detail/move_to_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'target_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace manipulator_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveToPose_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_pose
  {
    out << "target_pose: ";
    to_flow_style_yaml(msg.target_pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveToPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_pose:\n";
    to_block_style_yaml(msg.target_pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveToPose_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace manipulator_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use manipulator_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const manipulator_interfaces::srv::MoveToPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  manipulator_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use manipulator_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const manipulator_interfaces::srv::MoveToPose_Request & msg)
{
  return manipulator_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<manipulator_interfaces::srv::MoveToPose_Request>()
{
  return "manipulator_interfaces::srv::MoveToPose_Request";
}

template<>
inline const char * name<manipulator_interfaces::srv::MoveToPose_Request>()
{
  return "manipulator_interfaces/srv/MoveToPose_Request";
}

template<>
struct has_fixed_size<manipulator_interfaces::srv::MoveToPose_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<manipulator_interfaces::srv::MoveToPose_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<manipulator_interfaces::srv::MoveToPose_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace manipulator_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveToPose_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveToPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveToPose_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace manipulator_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use manipulator_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const manipulator_interfaces::srv::MoveToPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  manipulator_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use manipulator_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const manipulator_interfaces::srv::MoveToPose_Response & msg)
{
  return manipulator_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<manipulator_interfaces::srv::MoveToPose_Response>()
{
  return "manipulator_interfaces::srv::MoveToPose_Response";
}

template<>
inline const char * name<manipulator_interfaces::srv::MoveToPose_Response>()
{
  return "manipulator_interfaces/srv/MoveToPose_Response";
}

template<>
struct has_fixed_size<manipulator_interfaces::srv::MoveToPose_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<manipulator_interfaces::srv::MoveToPose_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<manipulator_interfaces::srv::MoveToPose_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<manipulator_interfaces::srv::MoveToPose>()
{
  return "manipulator_interfaces::srv::MoveToPose";
}

template<>
inline const char * name<manipulator_interfaces::srv::MoveToPose>()
{
  return "manipulator_interfaces/srv/MoveToPose";
}

template<>
struct has_fixed_size<manipulator_interfaces::srv::MoveToPose>
  : std::integral_constant<
    bool,
    has_fixed_size<manipulator_interfaces::srv::MoveToPose_Request>::value &&
    has_fixed_size<manipulator_interfaces::srv::MoveToPose_Response>::value
  >
{
};

template<>
struct has_bounded_size<manipulator_interfaces::srv::MoveToPose>
  : std::integral_constant<
    bool,
    has_bounded_size<manipulator_interfaces::srv::MoveToPose_Request>::value &&
    has_bounded_size<manipulator_interfaces::srv::MoveToPose_Response>::value
  >
{
};

template<>
struct is_service<manipulator_interfaces::srv::MoveToPose>
  : std::true_type
{
};

template<>
struct is_service_request<manipulator_interfaces::srv::MoveToPose_Request>
  : std::true_type
{
};

template<>
struct is_service_response<manipulator_interfaces::srv::MoveToPose_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MANIPULATOR_INTERFACES__SRV__DETAIL__MOVE_TO_POSE__TRAITS_HPP_
