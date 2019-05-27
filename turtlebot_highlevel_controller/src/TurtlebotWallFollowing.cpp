#include "turtlebot_highlevel_controller/TurtlebotWallFollowing.hpp"

namespace turtlebot_highlevel_controller {

TurtlebotWallFollowing::TurtlebotWallFollowing(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle), tfListener_(tfBuffer_)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }
  subscriber_ = nodeHandle_.subscribe(subscriberTopic_, 1, &TurtlebotWallFollowing::topicCallback, this);
  movementPublisher_ = nodeHandle_.advertise<geometry_msgs::Twist>(movementTopic_, 1);
  markerPublisher_ = nodeHandle_.advertise<visualization_msgs::Marker>("visualization_marker", 1);
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

void TurtlebotWallFollowing::placeMarker(std::string frame_id, float x, float y, float z)
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

  geometry_msgs::TransformStamped transform;
  tf2::Stamped<tf2::Transform> tf2;
  tf2::Vector3 point(x, y, z);
  try {
    transform = tfBuffer_.lookupTransform("odom", tf_frame, ros::Time(0));
    tf2::convert(transform, tf2);
    tf2::Vector3 new_point = tf2 * point;
    placeMarker("odom", new_point[0], new_point[1], new_point[2]);
  } catch (tf2::TransformException &exception) {
    ROS_WARN("%s", exception.what());
  }
}

}

