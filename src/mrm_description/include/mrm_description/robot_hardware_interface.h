#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>
#include <controller_manager/controller_manager.h>
#include <ros/ros.h>

class MyRobot : public hardware_interface::RobotHW
{
public:
  MyRobot() 
 { 
   // connect and register the joint state interface
   hardware_interface::JointStateHandle state_handle_base_waist("base_waist", &pos[0], &vel[0], &eff[0]);
   jnt_state_interface.registerHandle(state_handle_base_waist);

   hardware_interface::JointStateHandle state_handle_waist_forearm("waist_forearm", &pos[1], &vel[1], &eff[1]);
   jnt_state_interface.registerHandle(state_handle_waist_forearm);

    hardware_interface::JointStateHandle state_handle_forearm_forearmRotation("forearm_forearmRotation", &pos[2], &vel[2], &eff[2]);
   jnt_state_interface.registerHandle(state_handle_forearm_forearmRotation);

   hardware_interface::JointStateHandle state_handle_forearmRotation_wrist("forearmRotation_wrist", &pos[3], &vel[3], &eff[3]);
   jnt_state_interface.registerHandle(state_handle_forearmRotation_wrist);

   hardware_interface::JointStateHandle state_handle_wrist_wristRotation("wrist_wristRotation", &pos[4], &vel[4], &eff[4]);
   jnt_state_interface.registerHandle(state_handle_wrist_wristRotation);

   registerInterface(&jnt_state_interface);

   // connect and register the joint position interface
   hardware_interface::JointHandle pos_handle_base_waist(jnt_state_interface.getHandle("base_waist"), &cmd[0]);
   jnt_pos_interface.registerHandle(pos_handle_base_waist);

   hardware_interface::JointHandle pos_handle_waist_forearm(jnt_state_interface.getHandle("waist_forearm"), &cmd[1]);
   jnt_pos_interface.registerHandle(pos_handle_waist_forearm);

   hardware_interface::JointHandle pos_handle_forearm_forearmRotation(jnt_state_interface.getHandle("forearm_forearmRotation"), &cmd[2]);
   jnt_pos_interface.registerHandle(pos_handle_forearm_forearmRotation);

   hardware_interface::JointHandle pos_handle_forearmRotation_wrist(jnt_state_interface.getHandle("forearmRotation_wrist"), &cmd[3]);
   jnt_pos_interface.registerHandle(pos_handle_forearmRotation_wrist);

   hardware_interface::JointHandle pos_handle_wrist_wristRotation(jnt_state_interface.getHandle("wrist_wristRotation"), &cmd[4]);
   jnt_pos_interface.registerHandle(pos_handle_wrist_wristRotation);

   registerInterface(&jnt_pos_interface);
  }

private:
  hardware_interface::JointStateInterface jnt_state_interface;
  hardware_interface::PositionJointInterface jnt_pos_interface;
  double cmd[5];
  double pos[5];
  double vel[5];
  double eff[5];
};