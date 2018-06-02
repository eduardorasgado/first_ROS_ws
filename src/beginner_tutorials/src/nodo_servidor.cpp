#include "ros/ros.h"
#include "beginner_tutorials/tipo_servicio.h"

/**Funcion ofertada: servicio**/
bool servicio(beginner_tutorials::tipo_servicio::Request &req, beginner_tutorials::tipo_servicio::Response &res){
	res.resultado1 = req.argumento1 + 1;
	ROS_INFO("Peticion: x = %d",(int)req.argumento1);
	ROS_INFO("Respuesta: %d",(int)res.resultado1);
	return true;
}

int main(int argc,char **argv){
	//registra el nombre del nodo
	ros::init(argc, argv, "nombre_servidor");

	ros::NodeHandle n;

	//registra el servicio
	ros::ServiceServer service = n.advertiseService("nombre_servicio", servicio);

	ROS_INFO("Servicio registrado");

	//nos quedamos a la espera de llamadas al servicio
	ros::spin();
	return 0;
}
