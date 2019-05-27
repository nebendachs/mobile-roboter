#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <turtlebot_highlevel_controller/TransportMessage.h>
#include <string>
#include <math.h>

namespace turtlebot_highlevel_controller {

class TurtlebotWallDetection
{
 public:
  TurtlebotWallDetection(ros::NodeHandle& nodeHandle);
  virtual ~TurtlebotWallDetection();

 private:
  bool readParameters();
  void moveRobot(float lx, float ly, float lz, float ax, float ay, float az);
  void placeMarker(std::string frame_id, float x, float y, float z);
  void topicCallback(const sensor_msgs::LaserScan& message);

  ros::NodeHandle& nodeHandle_;
  ros::Subscriber subscriber_;
  ros::Publisher transportPublisher_;
  std::string subscriberTopic_;
  std::string transportTopic_;
  int queueSize_;
  int message_sequence_id_;
};

}

