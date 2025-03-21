// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from manipulator_interfaces:srv/MoveToPose.idl
// generated code does not contain a copyright notice

#ifndef MANIPULATOR_INTERFACES__SRV__DETAIL__MOVE_TO_POSE__BUILDER_HPP_
#define MANIPULATOR_INTERFACES__SRV__DETAIL__MOVE_TO_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "manipulator_interfaces/srv/detail/move_to_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace manipulator_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveToPose_Request_target_pose
{
public:
  Init_MoveToPose_Request_target_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::manipulator_interfaces::srv::MoveToPose_Request target_pose(::manipulator_interfaces::srv::MoveToPose_Request::_target_pose_type arg)
  {
    msg_.target_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::manipulator_interfaces::srv::MoveToPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::manipulator_interfaces::srv::MoveToPose_Request>()
{
  return manipulator_interfaces::srv::builder::Init_MoveToPose_Request_target_pose();
}

}  // namespace manipulator_interfaces


namespace manipulator_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveToPose_Response_success
{
public:
  Init_MoveToPose_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::manipulator_interfaces::srv::MoveToPose_Response success(::manipulator_interfaces::srv::MoveToPose_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::manipulator_interfaces::srv::MoveToPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::manipulator_interfaces::srv::MoveToPose_Response>()
{
  return manipulator_interfaces::srv::builder::Init_MoveToPose_Response_success();
}

}  // namespace manipulator_interfaces

#endif  // MANIPULATOR_INTERFACES__SRV__DETAIL__MOVE_TO_POSE__BUILDER_HPP_
