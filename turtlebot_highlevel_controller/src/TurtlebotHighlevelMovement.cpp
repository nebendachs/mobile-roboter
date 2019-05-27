#include "turtlebot_highlevel_controller/TurtlebotHighlevelMovement.hpp"

namespace turtlebot_highlevel_controller {

TurtlebotHighlevelMovement::TurtlebotHighlevelMovement(std::string actionName)
    : as_(nodeHandle_, actionName, boost::bind(&TurtlebotHighlevelMovement::execute, this, _1), false), actionName_(actionName)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }
  movementPublisher_ = nodeHandle_.advertise<geometry_msgs::Twist>(movementTopic_, 1);
  markerPublisher_ = nodeHandle_.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  as_.start();
  ROS_INFO("Successfully launched server.");
}

TurtlebotHighlevelMovement::~TurtlebotHighlevelMovement()
{
}

bool TurtlebotHighlevelMovement::readParameters()
{
  if (!nodeHandle_.getParam("movement_topic", movementTopic_)) return false;
  return true;
}

void TurtlebotHighlevelMovement::execute(const turtlebot_highlevel_controller::ReachTargetGoalConstPtr& goal)
{
  as_.setSucceeded();
}

void TurtlebotHighlevelMovement::moveRobot(float lx, float ly, float lz, float ax, float ay, float az)
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

void TurtlebotHighlevelMovement::placeMarker(std::string frame_id, float x, float y, float z)
{
  uint32_t shape = visualization_msgs::Marker::CYLINDER;
  visualization_msgs::Marker marker;
  marker.header.frame_id = frame_id;
  marker.header.stamp = ros::Time::now();
  marker.ns = "target_pillar";
  marker.id = 0;
  marker.type = shape;
  marker.action = visualization_msgs::Marker::ADD;
  marker.pose.position.x = x;
  marker.pose.position.y = y;
  marker.pose.position.z = z;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;
  marker.scale.x = 0.2;
  marker.scale.y = 0.2;
  marker.scale.z = 0.2;
  marker.color.r = 1.0f;
  marker.color.g = 0.5f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;
  marker.lifetime = ros::Duration();
  markerPublisher_.publish(marker);
}

}

