#pragma once

// ROS
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

namespace turtlebot_highlevel_controller {

class TurtlebotHighlevelProcessing
{
 public:
  TurtlebotHighlevelProcessing(ros::NodeHandle& nodeHandle);
  virtual ~TurtlebotHighlevelProcessing();

 private:
  bool readParameters();
  void topicCallback(const sensor_msgs::LaserScan& message);

  ros::NodeHandle& nodeHandle_;
  ros::Subscriber subscriber_;
  ros::Publisher publisher_;
  std::string subscriberTopic_;
  std::string publisherTopic_;
  int queueSize_;
};

}
