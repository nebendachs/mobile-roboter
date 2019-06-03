#include <ros/ros.h>
#include "turtlebot_highlevel_controller/TurtlebotHighlevelClient.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtlebot_highlevel_client");
  ros::NodeHandle nodeHandle("~");

  turtlebot_highlevel_controller::TurtlebotHighlevelClient turtlebotHighlevelClient(nodeHandle, "ReachTarget");

  ros::spin();
  return 0;
}
