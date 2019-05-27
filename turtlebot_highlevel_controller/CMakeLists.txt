cmake_minimum_required(VERSION 2.8.3)
project(turtlebot_highlevel_controller)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  tf2_ros
  std_msgs
  geometry_msgs
  message_generation
)

add_message_files(
  FILES
  TransportMessage.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)

catkin_package(
  INCLUDE_DIRS
    include
  CATKIN_DEPENDS
    roscpp
    sensor_msgs
    message_runtime
)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtlebot_highlevel_processing
  src/turtlebot_highlevel_processing_node.cpp
  src/TurtlebotHighlevelProcessing.cpp
)

add_dependencies(turtlebot_highlevel_processing
  ${catkin_EXPORTED_TARGETS}
)

target_link_libraries(turtlebot_highlevel_processing
  ${catkin_LIBRARIES}
)

add_executable(turtlebot_highlevel_movement
  src/turtlebot_highlevel_movement_node.cpp
  src/TurtlebotHighlevelMovement.cpp
)

add_dependencies(turtlebot_highlevel_movement
  ${catkin_EXPORTED_TARGETS}
)

target_link_libraries(turtlebot_highlevel_movement
  ${catkin_LIBRARIES}
)
