#include "turtlebot_highlevel_controller/TurtlebotWallDetection.hpp"


namespace turtlebot_highlevel_controller {

TurtlebotWallDetection::TurtlebotWallDetection(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }
  subscriber_ = nodeHandle_.subscribe(subscriberTopic_, this->queueSize_, &TurtlebotWallDetection::topicCallback, this);
  transportPublisher_ = nodeHandle_.advertise<turtlebot_highlevel_controller::TransportMessage>(transportTopic_, 1);
  message_sequence_id_ = 0;
  ROS_INFO("Successfully launched node.");
}

TurtlebotWallDetection::~TurtlebotWallDetection()
{
}

bool TurtlebotWallDetection::readParameters()
{
  if (!nodeHandle_.getParam("subsciber_topic", subscriberTopic_)) return false;
  if (!nodeHandle_.getParam("transport_topic", transportTopic_)) return false;
  if (!nodeHandle_.getParam("queue_size", queueSize_)) return false;
  return true;
}

void TurtlebotWallDetection::topicCallback(const sensor_msgs::LaserScan& message)
{
  std::vector<float> ranges = message.ranges;
  float min_value = *std::min_element(ranges.begin(), ranges.end());

  turtlebot_highlevel_controller::TransportMessage msg;
  msg.header.seq = this->message_sequence_id_;
  msg.header.stamp = ros::Time(0);
  msg.header.frame_id = "base_laser_link";

  if (min_value > 0.5) {
    msg.move.linear.x = 0.25;
    msg.move.angular.z = 0.0;
  } else {
    msg.move.linear.x = 0.0;
    msg.move.angular.z = 0.25;
  }

  msg.move.linear.y = 0.0;
  msg.move.linear.z = 0.0;
  msg.move.angular.x = 0.0;
  msg.move.angular.y = 0.0;

  msg.marker_pose.position.x = 0.0;
  msg.marker_pose.position.y = 0.0;
  msg.marker_pose.position.z = 0.0;
  msg.marker_pose.orientation.x = 0.0;
  msg.marker_pose.orientation.y = 0.0;
  msg.marker_pose.orientation.z = 0.0;

  transportPublisher_.publish(msg);
  this->message_sequence_id_ += 1;
}

}

