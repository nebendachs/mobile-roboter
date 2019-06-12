cmake_minimum_required(VERSION 2.8.3)
project(turtlebot_highlevel_controller)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  tf2_ros
  std_msgs
  geometry_msgs
  genmsg
  actionlib
  actionlib_msgs
  message_generation
)

add_message_files(
  FILES
  TransportMessage.msg
  ActionMessage.msg
)

add_action_files(
  DIRECTORY 
    action 
  FILES
    ReachTarget.action
)

generate_messages(
  DEPENDENCIES
    std_msgs
    sensor_msgs
    geometry_msgs
    actionlib
    actionlib_msgs
)

catkin_package(
  INCLUDE_DIRS
    include
  CATKIN_DEPENDS
    roscpp
    std_msgs
    sensor_msgs
    geometry_msgs
    actionlib_msgs
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

add_executable(turtlebot_highlevel_movement
  src/turtlebot_highlevel_movement_node.cpp
  src/TurtlebotHighlevelMovement.cpp
)

add_executable(turtlebot_highlevel_client
  src/turtlebot_highlevel_client_node.cpp
  src/TurtlebotHighlevelClient.cpp
)



add_dependencies(turtlebot_highlevel_processing
  ${catkin_EXPORTED_TARGETS} ${PROJECT_NAME}_generate_messages_cpp
)

add_dependencies(turtlebot_highlevel_movement
  ${catkin_EXPORTED_TARGETS} ${PROJECT_NAME}_generate_messages_cpp
)

add_dependencies(turtlebot_highlevel_client
  ${catkin_EXPORTED_TARGETS} ${PROJECT_NAME}_generate_messages_cpp
)



target_link_libraries(turtlebot_highlevel_processing
  ${catkin_LIBRARIES}
)

target_link_libraries(turtlebot_highlevel_movement
  ${catkin_LIBRARIES}
)

target_link_libraries(turtlebot_highlevel_client
  ${catkin_LIBRARIES}
)

