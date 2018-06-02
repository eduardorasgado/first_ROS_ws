#include "ros/ros.h"
#include "beginner_tutorials/mensajeTest.h"
/**
Este nodo llamado nodo emisor emite mensajes "mensajeTest_topic
del tipo beginner_tutorials/mensajeTest
**/
int main(int argc, char **argv){
	ros::init(argc,argv, "nodo_emisor"); //registra el nombre del nodo

	ros::nodeHandle nodo; //Creamos un objeto nodo
	//imprimimos en /stdout un mensaje
	ROS_INFO("nodo emisor creado y registrado");

	//Es necesario advertir el tipo de mensaje a enviar y
	//como lo hemos llamado(topic).
	//En este caso es de tipo userInfo y el topic se llama
	//use_info_topic
	ros::Publisher publicadorMensajes = nodo.advertise<beginner_tutoriales::mensajeTest>("mensajeTest_topic", 0);

	//tiempo a dormir en cada iteracion
	ros::Duration seconds_sleep(1);

	//ejecuta constantemente hasta recibir un Ctrl C
	int contador = 0;
	while (ros::ok()){
		//iniciamos un mensaje que queremos enviar
		beginner_tutorials::mensajeTest mensajeAEnviar;

		//en el mensaje enviamos el numero de veces que
		//se ha iterado en este bucle
		mensajeAEnviar.numero = contador;

		//Se publica el mensaje
		publicadorMensajes.publish(mensajeAEnviar);

		//en este programa no es necesario spinOnce,
		//pero si estuviera una funcion callback
		ros::spinOnce();
		ROS_DEBUG("Se duerme el nodo emisor durante un segundo");

		//dormmimos el nodo durante un tiempo
		seconds_sleep.sleep();

		//incrementamos el contador
		contador++;
	}
}
