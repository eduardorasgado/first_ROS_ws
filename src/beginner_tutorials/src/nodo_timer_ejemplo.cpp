#include <ros/ros.h>

void funcionManejadoraTimer(){

}

int main(int argc, char **argv){
	//registrar nodo
	//realizar suscripciones

	//creamos timer
	ros::Timer timer;
	timer = nodo.createTimer(ros::Duration(10), funcionManejadoraTimer);

	ros::AsyncSpinner spinner(n)
	spinner.start();
	ros::waitForShutdown();
}
