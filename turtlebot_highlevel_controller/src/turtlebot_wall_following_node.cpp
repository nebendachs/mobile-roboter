#include <ros/ros.h>
#include "turtlebot_highlevel_controller/TurtlebotWallFollowing.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtlebot_wall_following");
  ros::NodeHandle nodeHandle("~");

  turtlebot_highlevel_controller::TurtlebotWallFollowing turtlebotWallFollowing(nodeHandle);

  ros::spin();
  return 0;
}
