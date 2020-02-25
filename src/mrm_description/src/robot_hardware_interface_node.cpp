#include <mrm_description/robot_hardware_interface.h>

MyRobot::MyRobot(ros::NodeHandle& nh) : nh_(nh){
    init();
    controller_manager_.reset(new controller_manager::ControllerManager(this, nh_));
}

void MyRobot::init(){
    num_joints_ = 5;
    joint_names_[0] = "base_waist";
    joint_names_[1] = "waist_forearm";
    joint_names_[2] = "forearm_forearmRotation";
    joint_names_[3] = "forearmRotation_wrist";
    joint_names_[4] = "wrist_wristRotation";

    for (int i = 0; i < num_joints_; i++)
    {
        hardware_interface::JointStateHandle joint_state_handle(joint_names_[i], &pos[0], &vel[0], &eff[0]);
        jnt_state_interface.registerHandle(joint_state_handle);

        hardware_interface::JointHandle joint_pos_handle(jnt_state_interface.getHandle(joint_names_[i]), &cmd[0]);
        jnt_pos_interface.registerHandle(joint_pos_handle);
    }

    registerInterface(&jnt_state_interface);
    registerInterface(&jnt_pos_interface);
    
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "robot_hardware_interface");
    ros::NodeHandle nh;
    //ros::AsyncSpinner spinner(2);
    //spinner.start();
    MyRobot robot(nh);
    //controller_manager::ControllerManager cm(&robot);
    //ros::spin();

    while(1);
    /*while (true)
    {
        robot.read();
        cm.update(robot.get_time(), robot.get_period());
        robot.write();
        sleep();
    }*/
}
