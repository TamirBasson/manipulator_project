# manipulator_project

Welcome to the Manipulator Project! This repository contains the ROS2-based implementation for controlling and simulating a 2 DOF robotic manipulator.

First, source humble and moveit work space:

    source /opt/ros/humble/setup.bash
    source ~/moveit_ws/install/setup.bash

Clone the repository and do a colcon build for the interfaces:

    git clone https://github.com/TamirBasson/manipulator_project.git
    cd manipulator_project/src/manipulator_interfaces
    colcon build
    source install/setup.bash
    
Now you can do colcon build for the package:

    cd manipulator_project
    colcon build
    source install/setup.bash

Perform colcon build for the moveit_config provided by moveit assistant:

    cd config
    colcon build
    source install/setup.bash

Launch rviz simulation for visuallization:

    ros2 launch manipulator_project simulation.launch.py

In new terminal launch a file containing the service move_to_position:

    source install/setup.bash
    ros2 launch manipulator_project start_service.launch.py
    
After launching the lauch files you can now use the service, here are some examples:

    ros2 service call /move_to_pose manipulator_interfaces/srv/MoveToPose "{
      target_pose: {
      position: {x: 0.4, y: 0.0, z: 0.5},
      orientation: {x: 0.0, y: 0.707, z: 0.0, w: 0.707}
          }
        }"

    ros2 service call /move_to_pose manipulator_interfaces/srv/MoveToPose "{
      target_pose: {
      position: {x: 0.17, y: -0.362, z: 0.5},
      orientation: {x: 0.379, y: 0.597, z: -0.379, w: 0.597}
        }
      }"
# Workspace of the robot
The workspace of a robot refers to the physical region or area within which the robot can operate and perform tasks.
The base_link is 0.1 [m] hight, link1 is 0.4 [m] and link 2 is 0.4 [m]. Joint 1: base_link_to_link1 can rotate 360 degrees, and link1_to_link2 can rotate -90 to 90 degrees.

![image](https://github.com/user-attachments/assets/06043b53-47ce-4d17-a378-2eabc26427ce)

Since joint2 can only rotate 180 degrees, the workspace is limited to the upper half of an empty sphere. Therefore, the workspace coordinates must satisfy the following conditions:

                    $x^2 + y^2 + \hat{z}^2 = l^2$

                $x = x, \, y = y, \, z = \hat{z} + 0.5$

This defines the top half of the sphere with a 0.5 [m] translation in the z-direction.




