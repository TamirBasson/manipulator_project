from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from moveit_configs_utils import MoveItConfigsBuilder


def generate_launch_description():
    # Load MoveIt configuration for the robot
    moveit_config = MoveItConfigsBuilder("robot2").to_moveit_configs()
    moveit_config_dict = moveit_config.to_dict()
    moveit_config_dict.update({'use_sim_time': True})

    # Robot State Publisher Node
    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="screen",
        parameters=[{"robot_description": moveit_config.robot_description, "use_sim_time": True}]
    )

    # Joint State Publisher Node
    joint_state_publisher = Node(
        package="joint_state_publisher",
        executable="joint_state_publisher",
        output="screen",
        parameters=[{"use_sim_time": True}]
    )

    # Path to the MoveIt demo.launch.py file
    demo_launch = PathJoinSubstitution([
        FindPackageShare("robot2_moveit_config"),
        "launch",
        "demo.launch.py"
    ])

    # Include the demo launch file for MoveIt
    include_demo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(demo_launch),
        launch_arguments={"use_sim_time": "true"}.items()
    )

    return LaunchDescription([
        robot_state_publisher,
        joint_state_publisher,
        include_demo_launch
    ])
