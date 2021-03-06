#pragma once

#include <ros/ros.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/Twist.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/PointCloud.h>
#include <string>
#include <visualization_msgs/Marker.h>

namespace turtlebot_highlevel_controller {

class TurtlebotHighlevelController
{
 public:
  TurtlebotHighlevelController(ros::NodeHandle& nodeHandle);
  virtual ~TurtlebotHighlevelController();

 private:
  bool readParameters();
  void moveRobot(float lx, float ly, float lz, float ax, float ay, float az);
  void placeMarker(std::string frame_id, float x, float y, float z);
  void topicCallback(const sensor_msgs::LaserScan& message);

  ros::NodeHandle& nodeHandle_;
  ros::Subscriber subscriber_;
  ros::Publisher publisher_;
  ros::Publisher marker_pub_;
  std::string subscriberTopic_;
  std::string publisherTopic_;
  tf2_ros::Buffer tfBuffer_;
  tf2_ros::TransformListener tfListener_;
  int queueSize_;
  int drive_speed_;
};

}
