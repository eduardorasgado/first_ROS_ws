#include "ros/ros.h"
#include <beginner_tutorials/TestAction.h>
#include <actionlib/server/simple_action_server.h>

//para simplificar la biblioteca, en lugar
//de escribir todo esto, simplemente escribimos Server
typedef actionlib::SimpleActionServer<beginner_tutorials::TestAction> Server;

/**La funcion del actionlib server**/
void actionLib_callback(const beginner_tutorials::TestGoalConstPtr& goal, Server* as)
{
	as->setSucceeded();
	ROS_INFO("ActionLib goal recibido");

	//emitimos feedback
	beginner_tutorials::TestFeedback feedback;
	feedback.feedback = 0;

	as->publishFeedback(feedback);
	ROS_INFO("ActionLib feedback emitido");
}

/**Funcion principal**/
int main (int argc, char **argv){
	//registramos el nombre del nodo
	ros::init(argc, argv, "nodo_actionLib_servidor");
	ros::NodeHandle n;

	//registramos el servicio
	//asociamos "testALService" a la funcion manejadora
	Server server(n, "testALService", boost::bind(&actionLib_callback, _1, &server), false);
	server.start();
	ROS_INFO("ActionLib servicio registrado");

	//nos quedamos a la espera de llamadas al servicio
	ros::spin();
	return 0;
}
