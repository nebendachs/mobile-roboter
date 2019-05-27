#include <ros/ros.h>
#include "turtlebot_highlevel_movement/TurtlebotHighlevelMovement.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtlebot_highlevel_movement");
  ros::NodeHandle nodeHandle("~");

  turtlebot_highlevel_movement::TurtlebotHighlevelMovement turtlebotHighlevelMovement(nodeHandle);

  ros::spin();
  return 0;
}
