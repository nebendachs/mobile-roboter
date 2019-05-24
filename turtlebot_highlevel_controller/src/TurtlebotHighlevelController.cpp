#include "turtlebot_highlevel_controller/TurtlebotHighlevelController.hpp"
#include <string>
#include <visualization_msgs/Marker.h>

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

void TurtlebotHighlevelController::placeMarker()
{
  uint32_t shape = visualization_msgs::Marker::CUBE;
  visualization_msgs::Marker marker;
  marker.header.frame_id = "/base_link";
  marker.header.stamp = ros::Time::now();
  marker.ns = "basic_shapes";
  marker.id = 0;
  marker.type = shape;
  marker.action = visualization_msgs::Marker::ADD;
  marker.pose.position.x = 5.0;
  marker.pose.position.y = 0.0;
  marker.pose.position.z = 0.0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;
  marker.scale.x = 1.0;
  marker.scale.y = 1.0;
  marker.scale.z = 1.0;
  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;
  marker.lifetime = ros::Duration();
  marker_pub_.publish(marker);
}

void TurtlebotHighlevelController::topicCallback(const sensor_msgs::LaserScan& message)
{
  std::vector<float> ranges = message.ranges;
  std::vector<float> intensities = message.intensities;
  //float max_elem = *std::max_element(intensities.begin(), intensities.end());
  //float min_elem = *std::min_element(ranges.begin(), ranges.end());

//  sensor_msgs::PointCloud cloud;
  //projector_.projectLaser(message, cloud)



/*
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

  float angle_in_rad = message.angle_min + min_index * message.angle_increment;
  ROS_INFO("%d, %3.3f", min_index, angle_in_rad);

  geometry_msgs::Twist msg;
  if(min_element < 5.0)
  {
    msg.linear.x = 0.1;
  } else {
    msg.linear.x = 0.0;
  }
  msg.linear.y = 0.0;
  msg.linear.z = 0.0;
  msg.angular.x = 0.0;
  msg.angular.y = 0.0;
  msg.angular.z = angle_in_rad;
  this->publisher_.publish(msg);
*/
/*
  geometry_msgs::TransformStamped transformStamped;
  try {
    transformStamped = tfBuffer_.lookupTransform("odom", "base_laser_link", ros::Time(0));
  } catch (tf2::TransformException &exception) {
    ROS_WARN("%s", exception.what());
  }

  ROS_INFO("%3.3f", transformStamped.transform.translation.x);
  ROS_INFO("%3.3f", transformStamped.transform.translation.y);
  ROS_INFO("%3.3f\n", transformStamped.transform.translation.z);
*/


}

}
