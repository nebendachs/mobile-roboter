#include "turtlebot_highlevel_controller/TurtlebotHighlevelProcessing.hpp"

namespace turtlebot_highlevel_controller {

TurtlebotHighlevelProcessing::TurtlebotHighlevelProcessing(std::string actionName, bool flag)
{
  actionlib::SimpleActionClient<turtlebot_highlevel_controller::ReachTargetAction> client(actionName, flag);
  ROS_INFO("Successfully launched client.");
  ROS_INFO("Wait for Server...");
  client.waitForServer();
  turtlebot_highlevel_controller::ReachTargetGoal goal;

  goal.move.linear.x = 0.0;
  goal.move.linear.y = 0.0;
  goal.move.linear.z = 0.0;
  goal.move.angular.x = 0.0;
  goal.move.angular.y = 0.0;
  goal.move.angular.z = 0.0;

  goal.marker_pose.position.x = 0.0;
  goal.marker_pose.position.y = 0.0;
  goal.marker_pose.position.z = 0.0;
  goal.marker_pose.orientation.x = 0.0;
  goal.marker_pose.orientation.y = 0.0;
  goal.marker_pose.orientation.z = 0.0;

  client.sendGoal(goal);
  client.waitForResult(ros::Duration(5.0));

  if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    ROS_INFO("Reached goal.");
  } else {
    printf("Current State: %s\n", client.getState().toString().c_str());
  }
}

TurtlebotHighlevelProcessing::~TurtlebotHighlevelProcessing()
{
}

}

