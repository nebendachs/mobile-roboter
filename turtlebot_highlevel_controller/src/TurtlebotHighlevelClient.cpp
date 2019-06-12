#include "turtlebot_highlevel_controller/TurtlebotHighlevelClient.hpp"

namespace turtlebot_highlevel_controller {

typedef actionlib::SimpleActionClient<turtlebot_highlevel_controller::ReachTargetAction> Client;

TurtlebotHighlevelClient::TurtlebotHighlevelClient(ros::NodeHandle& nodeHandle, std::string actionName): actionClient_(actionName, true), nodeHandle_(nodeHandle)
{
  subscriber_ = nodeHandle_.subscribe("/action_topic", 1, &TurtlebotHighlevelClient::doAction, this);
  active_goal_ = false;

  ROS_INFO("CLIENT: Waiting for action server to start...");
  actionClient_.waitForServer();
  ROS_INFO("CLIENT: ...action server started.");
  ROS_INFO("CLIENT: Successfully launched client.");
}

TurtlebotHighlevelClient::~TurtlebotHighlevelClient()
{
}

void TurtlebotHighlevelClient::doAction(const turtlebot_highlevel_controller::ActionMessage& message)
{
  if(message.cancel == true) 
  {
    ROS_INFO("CLIENT: Cancel all goals.");
    actionClient_.cancelAllGoals();
    active_goal_ = false;
  } 
  else if(message.cancel == false) 
  {
    if(active_goal_ == true)
    {
      ROS_INFO("CLIENT: Another goal is active.");
    } 
    else if(active_goal_ == false)
    {
      ROS_INFO("CLIENT: New goal.");
      ROS_INFO("CLIENT: Build action message.");

      turtlebot_highlevel_controller::ReachTargetGoal goal;
      goal.target = message.target;

      actionClient_.sendGoal(goal,
			boost::bind(&TurtlebotHighlevelClient::doDoneCallback, this, _1, _2),
  			boost::bind(&TurtlebotHighlevelClient::doActiveCallback, this),
			boost::bind(&TurtlebotHighlevelClient::doFeedbackCallback, this, _1));
      active_goal_ = true;
      ROS_INFO("CLIENT: Sent action message.");
    }
  }
}

void TurtlebotHighlevelClient::doDoneCallback(const actionlib::SimpleClientGoalState& state, const ReachTargetResultConstPtr& result)
{
  if(state == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("CLIENT: Action SUCCEEDED with remaining distance to target position: %.3f", result->finished_distance);
    active_goal_ = false;
  }
  else if(state == actionlib::SimpleClientGoalState::ABORTED)
  {
    ROS_INFO("CLIENT: Action ABORTED with remaining distance to target position: %.3f", result->finished_distance);
    active_goal_ = false;
  }
  else if(state == actionlib::SimpleClientGoalState::PREEMPTED)
  {
    ROS_INFO("CLIENT: Action PREEMPTED with remaining distance to target position: %.3f", result->finished_distance);
    active_goal_ = false;
  }
}

void TurtlebotHighlevelClient::doActiveCallback()
{
  ROS_INFO("CLIENT: An action were activated.");
}

void TurtlebotHighlevelClient::doFeedbackCallback(const ReachTargetFeedbackConstPtr& feedback)
{
  ROS_INFO("CLIENT: Remaining distance to target position: %.3f", feedback->remaining_distance);
}

}

