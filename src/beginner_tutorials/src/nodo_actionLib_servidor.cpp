#include "ros/ros.h"
#include <beginner_tutorials/TestAction.h>
#include <actionlib/server/simple_Action_server.h>

//para simplificar la biblioteca
typedef actionlib::SimpleActionServer<beginner_tutorials::TestAction>Server;

/**La funcion del actionlib server**/
void actionLib_callback(const beginner_tutorials::TestGoalConstPtr& goal, Server* as){
	as->setSucceeded();
	ROS_INFO("ActionLib goal recibido");

	//emitimos feedback
	beginner_tutorials::TestFeedback feedback;
	feedback.infoFeedback = 0;

	as->publishFeedback(feedback);
	ROS_INFO("ActionLib feedback emitido");
}

/**Funcion principal**/
int main (int argc, chat **argv){
	//registramos el nombre del nodo
	ros::init(argc, argv, "nodo_actionLib_servidor");
	ros::NodeHandle n;

	//registramos el servicio
	Server server(n, "testALService", boost::bind(&actionLib_callback, _1, &server), false);
	server.start();
	ROS_INFO("ActionLib servicio registrado");
}
