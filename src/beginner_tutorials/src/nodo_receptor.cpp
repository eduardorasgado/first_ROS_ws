#include "ros/ros.h"
#include "beginer_tutorials/mensajeTest.h"

/**
Se implementa un nodo que espera recibir mensajes cuyo topic
es mensajeTest_topic del tipo beginner_tutorials::mensajeTest
**/

/*
Esta funcion muestra por pantalla el mensaje reibido que es de
tipo mensajeTest
*/

void funcionCallback(const beginner_tutorials::mensajeTest::ConstPtr& msg){
	ROS_INFO("He recibido un mensaje de test con el numero %d", msg->numero);
}

int main(int argc, char **argv){
	//registra el nombre del nodo: nodo receptor
	ros::init(argc,argv,"nodo_receptor");
	//crear el nodo
	ros::NodeHandle nodoReceptor;

	ROS_INFO("Nodo receptor creado y registrado");


	//Si recibimos el mensaje cuyo topic es:
	//mensajeTest_topic, llamamos a la funcion
	//manejadora funcionCallback
	ros::Subscriber subscriptor = nodoReceptor.subscribe("mensajeTest_topic", 0, funcionCallback);

	/**loop infinito para que no finalice la ejecucion del nodo
	y siempre se pueda llamar al callback
	**/
	ros::spin();
	return 0;
}
