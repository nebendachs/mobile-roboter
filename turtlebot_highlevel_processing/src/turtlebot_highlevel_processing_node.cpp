#include <ros/ros.h>
#include "turtlebot_highlevel_processing/TurtlebotHighlevelProcessing.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtlebot_highlevel_processing");
  ros::NodeHandle nodeHandle("~");

  turtlebot_highlevel_processing::TurtlebotHighlevelProcessing turtlebotHighlevelProcessing(nodeHandle);

  ros::spin();
  return 0;
}
