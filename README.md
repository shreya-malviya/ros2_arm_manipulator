Building a 4-DOF Robotic Manipulator Simulation

This repository contains the ROS 2 packages required to simulate a 4-DOF robotic manipulator in Gazebo. The project includes:

Robot Description (URDF/Xacro files)
Gazebo Simulation (Spawning the robot in Gazebo)
Controllers (Using ros2_control for joint position control)
Camera Sensor (Adding a camera to the robot)
ROS Node (Publishing and subscribing to joint states)


Clone: https://github.com/RoboticsLab2024/
 arm_description.git into your ros2_ws 

 Build the workspace:
/`colcon build
source install/setup.bash
`

Launch the simulation : 
/`ros2 launch arm_gazebo arm_world.launch.py
`

Launch controller 
/`ros2 launch arm_controller arm_control.launch.py`