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
  publisher_ = nodeHandle_.advertise<geometry_msgs::Twist>(publisherTopic_, 1);
  ROS_INFO("Successfully launched node.");
}

TurtlebotHighlevelController::~TurtlebotHighlevelController()
{
}

bool TurtlebotHighlevelController::readParameters()
{
  if (!nodeHandle_.getParam("subsciber_topic", subscriberTopic_)) return false;
  if (!nodeHandle_.getParam("publisher_topic", publisherTopic_)) return false;
  if (!nodeHandle_.getParam("queue_size", queueSize_)) return false;
  return true;
}

void TurtlebotHighlevelController::topicCallback(const sensor_msgs::LaserScan& message)
{
  std::vector<float> ranges = message.ranges;
  std::vector<float> intensities = message.intensities;
  float max_elem = *std::max_element(intensities.begin(), intensities.end());
  float min_elem = *std::min_element(ranges.begin(), ranges.end());
  ROS_INFO("Min distance: %3.3f with intensiti<: %3.3f", min_elem, max_elem);

/*
  if (max_elem < 1) {
    geometry_msgs::Twist msg;
    msg.linear.x = 0.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;
    msg.angular.x = 1.0;
    msg.angular.y = 1.0;
    msg.angular.z = 1.0;
    this->publisher_.publish(msg);
  }
*/
}

}
