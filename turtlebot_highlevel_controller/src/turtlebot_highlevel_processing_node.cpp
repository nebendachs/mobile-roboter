#include <ros/ros.h>
#include "turtlebot_highlevel_controller/TurtlebotHighlevelProcessing.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtlebot_highlevel_client");

  turtlebot_highlevel_controller::TurtlebotHighlevelProcessing turtlebotHighlevelProcessing("ReachGoal", true);

  ros::spin();
  return 0;
}
