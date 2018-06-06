#include <ros/ros.h>

void funcionManejadoraTimer(){

}

int main(int argc, char **argv){
	//registrar nodo
	ros::init(argc, argv "nodo_timer");
	//realizar suscripciones
	ros::NodeHandle n;
	//suscripciones...
	Subscriber subscriptor1 = n.subscribe("topic_name", 0, funcionCallbackllamada);
	//creamos timer
	ros::Timer timer;
	timer = n.createTimer(ros::Duration(10), funcionManejadoraTimer);

	ros::AsyncSpinner spinner(n)
	spinner.start();
	ros::waitForShutdown();
}
