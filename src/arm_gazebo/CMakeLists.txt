cmake_minimum_required(VERSION 3.8)
project(arm_gazebo)

find_package(ament_cmake REQUIRED)
find_package(gazebo_ros REQUIRED)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
