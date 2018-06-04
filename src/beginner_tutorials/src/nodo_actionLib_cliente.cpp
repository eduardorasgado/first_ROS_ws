#include "ros/ros.h"
/**Debemos incluir el Action al final del nombre del action
con ello le decimos que se trata de una accion
**/
#include <beginner_tutorials/TestAction.h>
#include <actionlib/client/simple_action_client>

typedef actionlib::SimpleActionClinet<beginner_tutorials::TestAction> Client;



