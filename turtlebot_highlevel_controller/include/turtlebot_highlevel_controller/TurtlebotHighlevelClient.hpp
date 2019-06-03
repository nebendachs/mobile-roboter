#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Point.h>
#include <string>
#include <math.h>
#include <turtlebot_highlevel_controller/ReachTargetAction.h>
#include <actionlib/client/simple_action_client.h>

namespace turtlebot_highlevel_controller {

typedef actionlib::SimpleActionClient<turtlebot_highlevel_controller::ReachTargetAction> Client;

class TurtlebotHighlevelClient
{
 public:
  TurtlebotHighlevelClient(ros::NodeHandle& nodeHandle, std::string actionName);
  void doAction(const geometry_msgs::Point& message);
  void doCallback(const actionlib::SimpleClientGoalState& state, const ReachTargetResultConstPtr& result);
  virtual ~TurtlebotHighlevelClient();

 private:
  ros::NodeHandle& nodeHandle_;
  Client actionClient_;
  ros::Subscriber subscriber_;
  std::string subscriberTopic_;
};

}

