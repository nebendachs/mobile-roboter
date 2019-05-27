#include <ros/ros.h>
#include "turtlebot_highlevel_controller/TurtlebotHighlevelProcessing.hpp"
#include "turtlebot_highlevel_controller/TurtlebotHighlevelMovement.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtlebot_highlevel_controller");
  ros::NodeHandle nodeHandle1("~");
  ros::NodeHandle nodeHandle2("~");

  turtlebot_highlevel_controller::TurtlebotHighlevelProcessing turtlebotHighlevelProcessing(nodeHandle1);
  turtlebot_highlevel_controller::TurtlebotHighlevelMovement turtlebotHighlevelMovement(nodeHandle2);

  ros::spin();
  return 0;
}
