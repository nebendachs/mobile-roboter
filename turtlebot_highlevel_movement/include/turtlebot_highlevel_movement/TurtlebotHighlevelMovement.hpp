#pragma once

#include <ros/ros.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/Twist.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <string>
#include <visualization_msgs/Marker.h>
#include "turtlebot_highlevel_movement/TransportMessage.h"

namespace turtlebot_highlevel_movement {

class TurtlebotHighlevelMovement
{
 public:
  TurtlebotHighlevelMovement(ros::NodeHandle& nodeHandle);
  virtual ~TurtlebotHighlevelMovement();

 private:
  bool readParameters();
  void moveRobot(float lx, float ly, float lz, float ax, float ay, float az);
  void placeMarker(std::string frame_id, float x, float y, float z);
  void topicCallback(const turtlebot_highlevel_movement::TransportMessage& message);

  ros::NodeHandle& nodeHandle_;
  ros::Subscriber subscriber_;
  ros::Publisher movementPublisher_;
  ros::Publisher markerPublisher_;
  std::string subscriberTopic_;
  std::string movementTopic_;
  tf2_ros::Buffer tfBuffer_;
  tf2_ros::TransformListener tfListener_;
};

}
