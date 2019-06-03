#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <string>
#include <math.h>
#include <turtlebot_highlevel_controller/ReachTargetAction.h>
#include <actionlib/server/simple_action_server.h>

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
  void execute(const turtlebot_highlevel_controller::ReachTargetGoalConstPtr& goal);
  virtual ~TurtlebotHighlevelProcessing();
};

}

