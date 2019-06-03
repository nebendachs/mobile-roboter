#include "turtlebot_highlevel_controller/TurtlebotHighlevelClient.hpp"

namespace turtlebot_highlevel_controller {

typedef actionlib::SimpleActionClient<turtlebot_highlevel_controller::ReachTargetAction> Client;

TurtlebotHighlevelClient::TurtlebotHighlevelClient(ros::NodeHandle& nodeHandle, std::string actionName): actionClient_(actionName, true), nodeHandle_(nodeHandle)
{
  subscriber_ = nodeHandle_.subscribe("/action_topic", 1, &TurtlebotHighlevelClient::doAction, this);

  ROS_INFO("Waiting for action server to start...");
  actionClient_.waitForServer();
  ROS_INFO("...action server started.");
}

TurtlebotHighlevelClient::~TurtlebotHighlevelClient()
{
}

void TurtlebotHighlevelClient::doAction(const geometry_msgs::Point& message)
{
  ROS_INFO("Build action message.");
  turtlebot_highlevel_controller::ReachTargetGoal goal;

  goal.target = message;

  ROS_INFO("Send action message.");
  actionClient_.sendGoal(goal,
			boost::bind(&TurtlebotHighlevelClient::doCallback, this, _1, _2),
			Client::SimpleActiveCallback(),
			Client::SimpleFeedbackCallback());
}

void TurtlebotHighlevelClient::doCallback(const actionlib::SimpleClientGoalState& state, const ReachTargetResultConstPtr& result)
{
  ROS_INFO("Finished in state [%s]", state.toString().c_str());
  ROS_INFO("Answer: %i", result->finished);
}

}

