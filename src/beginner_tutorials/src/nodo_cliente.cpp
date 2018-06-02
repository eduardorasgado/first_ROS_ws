#include "ros/ros.h"
#include "beginner_tutorials/tipo_servicio.h"
#include "cstdlib"

int main(int argc,char **argv){
	//registra el nombre del nodo
	ros::init(argc, argv, "nodo_cliente");
	ros::NodeHandle n;

	//vamos a invocar el servicio llamado nombre_servicio
	ros::ServiceClient client = n.serviceClient<beginner_tutorials::tipo_servicio>("nombre_servicio");

	beginner_tutorials::tipo_servicio srv;

	srv.request.argumento1 = 2; //le damos un valor de prueba

	if(client.call(srv)){
		ROS_INFO("Respuesta del servicio %d", (int)srv.response.resultado1);
	} else {
		ROS_ERROR("Fallo al llamar al servicio: nombre_servicio");
		return 1;
	}

	//para que no finalice el proceso
	ros::waitForShutdown();
	return 0;
}
