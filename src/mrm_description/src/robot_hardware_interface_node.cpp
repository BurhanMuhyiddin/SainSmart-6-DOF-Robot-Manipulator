#include <mrm_description/robot_hardware_interface.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "robot_hardware_interface");
    //ros::AsyncSpinner spinner(2);
    //spinner.start();
    MyRobot robot;
    controller_manager::ControllerManager cm(&robot);
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
