#include "ros/ros.h"
#include "beginner_tutorials/mensajeTest.h"
/**
* Se implementa un nodo que espera recibir mensajes cuyo topic es "mensajeT
est_topic" del tipo beginner_tutorials::mensajeTest.
* Muestra en pantalla este mensaje recibido
*/
/**
* Esta función muestra por pantalla el mensaje recibido que es de tipo mensa
jeTest
*/
void funcionCallback(const beginner_tutorials::mensajeTest::ConstPtr& msg){
    ROS_INFO("He recibido un mensaje de test con el numero: %d", msg->numero);
}
int main(int argc, char **argv){//registra el nombre del nodo: nodo_receptor
    ros::init(argc, argv, "nodo_receptor");
    ros::NodeHandle nodoReceptor;
    ROS_INFO("nodo_receptor creado y registrado"); //muestra en pantalla
    //si recibimos el mensaje cuyo topic es: "mensajeTest_topic" llamamos a la
    //función manejadora: funcionCallback
    ros::Subscriber subscriptor = nodoReceptor.subscribe("mensajeTest_topic", 0, funcionCallback);
/** Loop infinito para que no finalice la ejecución del nodo y siempre se p
ueda llamar al callback */
    ros::spin();
    return 0;
}
