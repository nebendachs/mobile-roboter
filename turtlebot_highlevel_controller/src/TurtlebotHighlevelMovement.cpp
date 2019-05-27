#include "turtlebot_highlevel_controller/TurtlebotHighlevelMovement.hpp"
#include <string>

namespace turtlebot_highlevel_controller {

TurtlebotHighlevelMovement::TurtlebotHighlevelMovement(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }
  subscriber_ = nodeHandle_.subscribe(subscriberTopic_, 1, &TurtlebotHighlevelMovement::topicCallback, this);
  publisher_ = nodeHandle_.advertise<geometry_msgs::Twist>(publisherTopic_, 1);
  ROS_INFO("Successfully launched node.");
}

TurtlebotHighlevelMovement::~TurtlebotHighlevelMovement()
{
}

bool TurtlebotHighlevelMovement::readParameters()
{
  if (!nodeHandle_.getParam("subsciber_topic", subscriberTopic_)) return false;
  if (!nodeHandle_.getParam("publisher_topic", publisherTopic_)) return false;
  if (!nodeHandle_.getParam("queue_size", queueSize_)) return false;
  return true;
}

void TurtlebotHighlevelMovement::topicCallback(const sensor_msgs::LaserScan& message)
{
  std::vector<float> ranges = message.ranges;
  std::vector<float> intensities = message.intensities;
  float max_elem = *std::max_element(intensities.begin(), intensities.end());
  float min_elem = *std::min_element(ranges.begin(), ranges.end());
  ROS_INFO("Min distance: %3.3f with intensiti<: %3.3f", min_elem, max_elem);
}

}
