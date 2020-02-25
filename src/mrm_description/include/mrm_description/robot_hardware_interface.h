#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>
#include <controller_manager/controller_manager.h>
#include <ros/ros.h>
#include <boost/scoped_ptr.hpp>

class MyRobot : public hardware_interface::RobotHW
{
public:
  MyRobot(ros::NodeHandle& nh);
  void init();

private:
  hardware_interface::JointStateInterface jnt_state_interface;
  hardware_interface::PositionJointInterface jnt_pos_interface;

  int num_joints_;
  std::string joint_names_[5]; 
  double cmd[5];
  double pos[5];
  double vel[5];
  double eff[5];

  ros::NodeHandle nh_;
  boost::shared_ptr<controller_manager::ControllerManager> controller_manager_;
};