#pragma once

#include <ros/ros.h>
#include <geometry_msgs/TransformStamped.h>
#include <turtlebot_highlevel_controller/TransportMessage.h>
#include <turtlebot_highlevel_controller/ReachTargetAction.h>
#include <actionlib/server/simple_action_server.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <iostream>

namespace turtlebot_highlevel_controller {

class TurtlebotHighlevelProcessing
{
 protected:
  ros::NodeHandle nodeHandle_;
  actionlib::SimpleActionServer<turtlebot_highlevel_controller::ReachTargetAction> actionServer_;
  std::string actionName_;
  turtlebot_highlevel_controller::ReachTargetFeedback feedback_;
  turtlebot_highlevel_controller::ReachTargetResult result_;

 public:
  TurtlebotHighlevelProcessing(std::string actionName);
  ros::Publisher transportPublisher_;
  std::string transportTopic_;
  void execute(const turtlebot_highlevel_controller::ReachTargetGoalConstPtr& goal);
  virtual ~TurtlebotHighlevelProcessing();
  tf2_ros::Buffer tfBuffer_;
  tf2_ros::TransformListener tfListener_;
};

}

