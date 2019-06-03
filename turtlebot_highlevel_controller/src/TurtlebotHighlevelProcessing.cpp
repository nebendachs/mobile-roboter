#include "turtlebot_highlevel_controller/TurtlebotHighlevelProcessing.hpp"

namespace turtlebot_highlevel_controller {

typedef actionlib::SimpleActionClient<turtlebot_highlevel_controller::ReachTargetAction> Client;

TurtlebotHighlevelProcessing::TurtlebotHighlevelProcessing(ros::NodeHandle& nodeHandle, std::string actionName): actionClient_(actionName, true), nodeHandle_(nodeHandle)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }
  subscriber_ = nodeHandle_.subscribe(subscriberTopic_, 1, &TurtlebotHighlevelProcessing::doAction, this);

  ROS_INFO("Waiting for action server to start...");
  actionClient_.waitForServer();
  ROS_INFO("...action server started.");
}

TurtlebotHighlevelProcessing::~TurtlebotHighlevelProcessing()
{
}

bool TurtlebotHighlevelProcessing::readParameters()
{
  if (!nodeHandle_.getParam("action_topic", subscriberTopic_)) return false;
  return true;
}

void TurtlebotHighlevelProcessing::doAction(const geometry_msgs::Twist& message)
{
  ROS_INFO("Build goal.");
  turtlebot_highlevel_controller::ReachTargetGoal goal;

  goal.move = message;

  goal.marker_pose.position.x = 0.0;
  goal.marker_pose.position.y = 0.0;
  goal.marker_pose.position.z = 0.0;
  goal.marker_pose.orientation.x = 0.0;
  goal.marker_pose.orientation.y = 0.0;
  goal.marker_pose.orientation.z = 0.0;

  ROS_INFO("Send goal.");
  actionClient_.sendGoal(goal,
			boost::bind(&TurtlebotHighlevelProcessing::doCallback, this, _1, _2),
			Client::SimpleActiveCallback(),
			Client::SimpleFeedbackCallback());
}

void TurtlebotHighlevelProcessing::doCallback(const actionlib::SimpleClientGoalState& state, const ReachTargetResultConstPtr& result)
{
  ROS_INFO("Finished in state [%s]", state.toString().c_str());
  ROS_INFO("Answer: %i", result->finished);
}

}

