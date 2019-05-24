#include "turtlebot_highlevel_controller/TurtlebotHighlevelController.hpp"
#include <string>
#include <visualization_msgs/Marker.h>
#include <math.h>

namespace turtlebot_highlevel_controller {

TurtlebotHighlevelController::TurtlebotHighlevelController(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle), tfListener_(tfBuffer_)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }
  subscriber_ = nodeHandle_.subscribe(subscriberTopic_, 1, &TurtlebotHighlevelController::topicCallback, this);
  publisher_ = nodeHandle_.advertise<geometry_msgs::Twist>(publisherTopic_, 1);
  marker_pub_ = nodeHandle_.advertise<visualization_msgs::Marker>("visualization_marker", 1);
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

void TurtlebotHighlevelController::moveRobot(float lx, float ly, float lz, float ax, float ay, float az)
{
  geometry_msgs::Twist msg;
  msg.linear.x = lx;
  msg.linear.y = ly;
  msg.linear.z = lz;
  msg.angular.x = ax;
  msg.angular.y = ay;
  msg.angular.z = az;
  this->publisher_.publish(msg);
}

void TurtlebotHighlevelController::placeMarker(std::string frame_id, float x, float y, float z)
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
  marker_pub_.publish(marker);
}

void TurtlebotHighlevelController::topicCallback(const sensor_msgs::LaserScan& message)
{
  std::vector<float> ranges = message.ranges;
  std::vector<float> intensities = message.intensities;

  float min_element = message.range_max;
  int min_index = 0;
  for(int i = 0; i < ranges.size(); i++)
  {
    if(ranges[i] < min_element)
    {
      min_element = ranges[i];
      min_index = i;
    }
  }

  // Aufgabe 2,3,4
  float angle = message.angle_min + min_index * message.angle_increment;
  if(min_element < 5.0)
  {
    this->moveRobot(0.1, 0.0, 0.0, 0.0, 0.0, angle);
  } else {
    this->moveRobot(0.0, 0.0, 0.0, 0.0, 0.0, angle);
  }

  // Aufgabe 6.a
  double x = cos(angle) * min_element;
  double y = sin(angle) * min_element;
  double z = 0.0;
  placeMarker("base_laser_link", x, y, z);

  // Aufgabe 6.b
  tf2::Vector3 point(x, y, z);
  geometry_msgs::TransformStamped transform;
  tf2::Stamped<tf2::Transform> tf2;
  try {
    transform = tfBuffer_.lookupTransform("odom", "base_laser_link", ros::Time(0));
    tf2::convert(transform, tf2);
    tf2::Vector3 new_point = tf2 * point;
    placeMarker("odom", new_point[0], new_point[1], new_point[2]);
  } catch (tf2::TransformException &exception) {
    ROS_WARN("%s", exception.what());
  }
}

}
