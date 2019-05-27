#include <ros/ros.h>
#include "turtlebot_highlevel_controller/TurtlebotWallDetection.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtlebot_wall_detection");
  ros::NodeHandle nodeHandle;

  turtlebot_highlevel_controller::TurtlebotWallDetection turtlebotWallDetection(nodeHandle);

  ros::spin();
  return 0;
}
