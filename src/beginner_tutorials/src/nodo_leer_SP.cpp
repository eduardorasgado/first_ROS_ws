#include "ros/ros.h"
#include <cstdlib>

int main(int argc, char **argv){
	//registrar nodo
	ros::init(argc, argv, "nodo_leer_SP");
	ros::NodeHandle n;

	std::String parametro;
	n.getParam("parametroTest", parametro);

	ROS_INFO("Parametro leido: %s", parametro.c_str());

	//para que no finalice el proceso
	ros::waitForShutdown();
	return 0;
}
