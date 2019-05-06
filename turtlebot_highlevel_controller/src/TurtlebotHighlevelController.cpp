#include "turtlebot_highlevel_controller/TurtlebotHighlevelController.hpp"
#include <string>

namespace turtlebot_highlevel_controller {

TurtlebotHighlevelController::TurtlebotHighlevelController(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }
  subscriber_ = nodeHandle_.subscribe(subscriberTopic_, 1, &TurtlebotHighlevelController::topicCallback, this);
  ROS_INFO("Successfully launched node.");
}

TurtlebotHighlevelController::~TurtlebotHighlevelController()
{
}

bool TurtlebotHighlevelController::readParameters()
{
  if (!nodeHandle_.getParam("topic", subscriberTopic_)) return false;
  if (!nodeHandle_.getParam("queue_size", queueSize_)) return false;
  return true;
}

void TurtlebotHighlevelController::topicCallback(const sensor_msgs::LaserScan& message)
{
  std::vector<float> ranges = message.ranges;
  float min_elem = *std::min_element(ranges.begin(), ranges.end());
  ROS_INFO("Min distance: %3.3f", min_elem);
}

} /* namespace */
