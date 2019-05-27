#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <turtlebot_highlevel_controller/ReachTargetAction.h>
#include <string>
#include <math.h>
#include <actionlib/client/simple_action_client.h>

namespace turtlebot_highlevel_controller {

class TurtlebotHighlevelProcessing
{
 public:
  TurtlebotHighlevelProcessing(std::string actionName, bool flag);
  virtual ~TurtlebotHighlevelProcessing();
};

}

