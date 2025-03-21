// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from manipulator_interfaces:srv/MoveToPose.idl
// generated code does not contain a copyright notice

#ifndef MANIPULATOR_INTERFACES__SRV__DETAIL__MOVE_TO_POSE__STRUCT_H_
#define MANIPULATOR_INTERFACES__SRV__DETAIL__MOVE_TO_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/MoveToPose in the package manipulator_interfaces.
typedef struct manipulator_interfaces__srv__MoveToPose_Request
{
  geometry_msgs__msg__Pose target_pose;
} manipulator_interfaces__srv__MoveToPose_Request;

// Struct for a sequence of manipulator_interfaces__srv__MoveToPose_Request.
typedef struct manipulator_interfaces__srv__MoveToPose_Request__Sequence
{
  manipulator_interfaces__srv__MoveToPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} manipulator_interfaces__srv__MoveToPose_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/MoveToPose in the package manipulator_interfaces.
typedef struct manipulator_interfaces__srv__MoveToPose_Response
{
  bool success;
} manipulator_interfaces__srv__MoveToPose_Response;

// Struct for a sequence of manipulator_interfaces__srv__MoveToPose_Response.
typedef struct manipulator_interfaces__srv__MoveToPose_Response__Sequence
{
  manipulator_interfaces__srv__MoveToPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} manipulator_interfaces__srv__MoveToPose_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MANIPULATOR_INTERFACES__SRV__DETAIL__MOVE_TO_POSE__STRUCT_H_
