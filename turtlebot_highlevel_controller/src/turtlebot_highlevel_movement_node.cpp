#include <ros/ros.h>
#include "turtlebot_highlevel_controller/TurtlebotHighlevelMovement.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtlebot_highlevel_server");

  turtlebot_highlevel_controller::TurtlebotHighlevelMovement turtlebotHighlevelMovement("ReachGoal");

  ros::spin();
  return 0;
}
