#include "ros/ros.h"
#include <cstdlib>

int main(int argc, char **argv){
	//registrar el nodo
	ros::init(argc, argv, "nodo_escribe_SP");
	ros::NodeHandle n;

	//el parametro a enviar se llamara parametroTest
	//y tendra el valor string "calorPrueba"
	n.setParam("parametroTest", "valorPrueba");

	//para que no finalice el proceso
	ros::waitForShutdown();
	return 0;
}
