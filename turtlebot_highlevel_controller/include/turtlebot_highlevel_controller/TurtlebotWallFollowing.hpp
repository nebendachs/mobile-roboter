#pragma once

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlebot_highlevel_controller/TransportMessage.h>
#include <string>

namespace turtlebot_highlevel_controller {

class TurtlebotWallFollowing
{
 public:
  TurtlebotWallFollowing(ros::NodeHandle& nodeHandle);
  virtual ~TurtlebotWallFollowing();

 private:
  bool readParameters();
  void moveRobot(float lx, float ly, float lz, float ax, float ay, float az);
  void placeMarker(std::string frame_id, float x, float y, float z);
  void topicCallback(const turtlebot_highlevel_controller::TransportMessage& message);

  ros::NodeHandle& nodeHandle_;
  ros::Subscriber subscriber_;
  ros::Publisher movementPublisher_;
  ros::Publisher markerPublisher_;
  std::string subscriberTopic_;
  std::string movementTopic_;
};

}
