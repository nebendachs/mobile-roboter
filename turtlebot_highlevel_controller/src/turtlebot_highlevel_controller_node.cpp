#include <ros/ros.h>
#include "turtlebot_highlevel_controller/TurtlebotHighlevelController.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtlebot_highlevel_controller");
  ros::NodeHandle nodeHandle("~");

  turtlebot_highlevel_controller::TurtlebotHighlevelController turtlebotHighlevelController(nodeHandle);

  ros::spin();
  return 0;
}
