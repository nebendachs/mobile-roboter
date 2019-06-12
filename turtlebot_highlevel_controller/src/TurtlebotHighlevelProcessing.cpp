#include "turtlebot_highlevel_controller/TurtlebotHighlevelProcessing.hpp"

namespace turtlebot_highlevel_controller {

TurtlebotHighlevelProcessing::TurtlebotHighlevelProcessing(std::string actionName) 
: actionServer_(nodeHandle_, actionName, boost::bind(&TurtlebotHighlevelProcessing::execute, this, _1), false), actionName_(actionName), tfListener_(tfBuffer_)
{
  transportPublisher_ = nodeHandle_.advertise<turtlebot_highlevel_controller::TransportMessage>("/transport", 1);

  actionServer_.start();
  ROS_INFO("SERVER: Successfully launched server.");
}

TurtlebotHighlevelProcessing::~TurtlebotHighlevelProcessing()
{
}

void TurtlebotHighlevelProcessing::execute(const turtlebot_highlevel_controller::ReachTargetGoalConstPtr& goal)
{
  turtlebot_highlevel_controller::TransportMessage msg;
  float remaining_distance = 1000;
  bool inner_break = false;
  while(remaining_distance > 0.05)
  {
    if(actionServer_.isPreemptRequested())
    {
      actionServer_.setPreempted(result_);
      inner_break = true;
			break;
    }
    else
    {
			geometry_msgs::TransformStamped transform;
			tf2::Stamped<tf2::Transform> tf2;
			tf2::Vector3 point(goal->target.x, goal->target.y, goal->target.z);
			try {
				transform = tfBuffer_.lookupTransform("base_link", "map", ros::Time(0));
				tf2::convert(transform, tf2);
				tf2::Vector3 robot_point = tf2 * point;

				remaining_distance = std::sqrt(robot_point[0] * robot_point[0] + robot_point[1] * robot_point[1]);

				msg.header.seq = 0;
				msg.header.stamp = ros::Time(0);
				msg.header.frame_id = "map";

				msg.move.linear.x = 0.25f;
				msg.move.linear.y = 0.0;
				msg.move.linear.z = 0.0;
				msg.move.angular.x = 0.0;
				msg.move.angular.y = 0.0;
				float angle = std::atan2(robot_point[1], robot_point[0]);
				msg.move.angular.z = angle;

				msg.marker_pose.position.x = goal->target.x;
				msg.marker_pose.position.y = goal->target.y;
				msg.marker_pose.position.z = goal->target.z;
				msg.marker_pose.orientation.x = 0.0;
				msg.marker_pose.orientation.y = 0.0;
				msg.marker_pose.orientation.z = 0.0;

				transportPublisher_.publish(msg);
				feedback_.remaining_distance = remaining_distance;
				result_.finished_distance = remaining_distance;
				actionServer_.publishFeedback(feedback_);
			} catch (tf2::TransformException &exception) {
				ROS_WARN("%s", exception.what());
			}
		}
  }
  if(!inner_break)
  {
    actionServer_.setSucceeded(result_);
  }
}
}
