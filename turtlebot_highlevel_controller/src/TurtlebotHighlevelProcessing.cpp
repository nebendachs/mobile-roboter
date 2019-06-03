#include "turtlebot_highlevel_controller/TurtlebotHighlevelProcessing.hpp"

namespace turtlebot_highlevel_controller {

TurtlebotHighlevelProcessing::TurtlebotHighlevelProcessing(std::string actionName) 
: actionServer_(nodeHandle_, actionName, boost::bind(&TurtlebotHighlevelProcessing::execute, this, _1), false), actionName_(actionName)
{
  actionServer_.start();
  ROS_INFO("Successfully launched server.");
}

TurtlebotHighlevelProcessing::~TurtlebotHighlevelProcessing()
{
}

void TurtlebotHighlevelProcessing::execute(const turtlebot_highlevel_controller::ReachTargetGoalConstPtr& goal)
{
  ROS_INFO("Action started.");
  actionServer_.setSucceeded();
}
}
