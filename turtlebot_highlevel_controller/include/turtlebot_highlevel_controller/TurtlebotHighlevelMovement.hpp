#pragma once

#include <ros/ros.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/Twist.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <turtlebot_highlevel_controller/ReachTargetAction.h>
#include <string>
#include <visualization_msgs/Marker.h>
#include <math.h>
#include <actionlib/server/simple_action_server.h>

namespace turtlebot_highlevel_controller {

class TurtlebotHighlevelMovement
{
 protected:
  ros::NodeHandle nodeHandle_;
  actionlib::SimpleActionServer<turtlebot_highlevel_controller::ReachTargetAction> as_;
  std::string actionName_;
  turtlebot_highlevel_controller::ReachTargetFeedback feedback_;
  turtlebot_highlevel_controller::ReachTargetResult result_;

 public:
  TurtlebotHighlevelMovement(std::string actionName);
  virtual ~TurtlebotHighlevelMovement();
  void execute(const turtlebot_highlevel_controller::ReachTargetGoalConstPtr& goal);

 private:
  bool readParameters();
  void moveRobot(float lx, float ly, float lz, float ax, float ay, float az);
  void placeMarker(std::string frame_id, float x, float y, float z);

  ros::Publisher movementPublisher_;
  ros::Publisher markerPublisher_;
  std::string movementTopic_;
};

}

