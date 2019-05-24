#include <ros/ros.h>
#include "turtlebot_highlevel_controller/TurtlebotHighlevelController.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtlebot_highlevel_controller");
  ros::NodeHandle nodeHandle("~");

  //tf2_ros::Buffer tfBuffer;
  //tf2_ros::TransformListener tfListener(tfBuffer);
  turtlebot_highlevel_controller::TurtlebotHighlevelController turtlebotHighlevelController(nodeHandle);

  ros::spin();
  return 0;
}
