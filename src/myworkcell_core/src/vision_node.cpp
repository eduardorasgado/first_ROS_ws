/**
** Simple ROS Node
**/
#include <ros/ros.h>

int main(int argc, char* argv[])
{
	//this must be called beforeanything else ROS-relative
	ros::init(argc, argv, "vision_node");

	//Create a ROS node handle
	ros::NodeHandle nh;

	//logging method, print messg to terminal output
	//and send it to he /rosout topic for other nodes to
	//monitor
	ROS_INFO("Hello, world");

	//Dont exit the program
	ros::spin();
}
