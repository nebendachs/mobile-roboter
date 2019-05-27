#include "turtlebot_highlevel_controller/TurtlebotWallFollowing.hpp"

namespace turtlebot_highlevel_controller {

TurtlebotWallFollowing::TurtlebotWallFollowing(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }
  subscriber_ = nodeHandle_.subscribe(subscriberTopic_, 1, &TurtlebotWallFollowing::topicCallback, this);
  movementPublisher_ = nodeHandle_.advertise<geometry_msgs::Twist>(movementTopic_, 1);
  ROS_INFO("Successfully launched node.");
}

TurtlebotWallFollowing::~TurtlebotWallFollowing()
{
}

bool TurtlebotWallFollowing::readParameters()
{
  if (!nodeHandle_.getParam("transport_topic", subscriberTopic_)) return false;
  if (!nodeHandle_.getParam("movement_topic", movementTopic_)) return false;
  return true;
}

void TurtlebotWallFollowing::moveRobot(float lx, float ly, float lz, float ax, float ay, float az)
{
  geometry_msgs::Twist msg;
  msg.linear.x = lx;
  msg.linear.y = ly;
  msg.linear.z = lz;
  msg.angular.x = ax;
  msg.angular.y = ay;
  msg.angular.z = az;
  this->movementPublisher_.publish(msg);
}

void TurtlebotWallFollowing::topicCallback(const turtlebot_highlevel_controller::TransportMessage& message)
{
  float lx = message.move.linear.x;
  float ly = message.move.linear.y;
  float lz = message.move.linear.z;
  float ax = message.move.angular.x;
  float ay = message.move.angular.y;
  float az = message.move.angular.z;

  float x = message.marker_pose.position.x;
  float y = message.marker_pose.position.y;
  float z = message.marker_pose.position.z;
  std::string tf_frame = message.header.frame_id;

  this->moveRobot(lx, ly, lz, ax, ay, az);
}

}

