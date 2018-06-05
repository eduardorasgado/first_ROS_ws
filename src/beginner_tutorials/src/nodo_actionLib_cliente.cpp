#include "ros/ros.h"
/**Debemos incluir el Action al final del nombre del action
con ello le decimos que se trata de una accion
**/
#include <beginner_tutorials/TestAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<beginner_tutorials::TestAction> Client;

int main(int argc, char **argv){
	ros::init(argc, argv, "nodo_ActionLib_cliente");
	Client client("testALService", true);
	client.waitForServer();

	//creamos un goal para endviarselo
	beginner_tutorials::TestGoal goal;
	goal.goal = 3;
	client.sendGoal(goal);
	client.waitForResult(ros::Duration(5.0));

	if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
	{
		ROS_INFO("Completado!");
	}

	ROS_INFO("Estado: %s\n", client.getState().toString().c_str());

	//no hace falta hacer un spin porque al crear el cliente el segundo 
	//parametro es tru
	return 0;
}
