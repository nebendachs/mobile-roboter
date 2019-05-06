#pragma once

// ROS
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <std_srvs/Trigger.h>

namespace turtlebot_highlevel_controller {

class TurtlebotHighlevelController
{
 public:
  TurtlebotHighlevelController(ros::NodeHandle& nodeHandle);

  virtual ~TurtlebotHighlevelController();

 private:
  bool readParameters();
  void topicCallback(const sensor_msgs::LaserScan& message);

  ros::NodeHandle& nodeHandle_;
  ros::Subscriber subscriber_;
  std::string subscriberTopic_;
  int queueSize_;
};

}
