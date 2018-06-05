cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

## Add support for C++11, supported in ROS Kinetic and newer
# add_definitions(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  actionlib
  actionlib_msgs

)


## Generate messages in the 'msg' folder
 add_message_files(
  FILES
  mensajeTest.msg
 )

## Generate services in the 'srv' folder
 add_service_files(
   FILES
   tipo_servicio.srv
 )

## Generate actions in the 'action' folder
 add_action_files(
    FILES
    Test.action
 )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
   actionlib_msgs
 )

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)


## EXECUTABLES
 add_executable(nodo_emisor src/nodo_emisor.cpp)
 add_executable(nodo_receptor src/nodo_receptor.cpp)
 add_executable(nodo_servidor src/nodo_servidor.cpp)
 add_Executable(nodo_cliente src/nodo_cliente.cpp)
 add_executable(nodo_actionLib_cliente src/nodo_actionLib_cliente.cpp)
 add_executable(nodo_actionLib_servidor src/nodo_actionLib_servidor.cpp)
# add_executable(nodo_escribe_SP src/nodo_escribe_SP.cpp)
# add_executable(nodo_leer_SP src/nodo_leer_SP.cpp)



# DEPENDENCIES
add_dependencies(nodo_emisor
          beginner_tutorials_generate_messages_cpp
          ${catkin_EXPORTED_TARGETS})
add_dependencies(nodo_receptor
          beginner_tutorials_generate_messages_cpp
          ${catkin_EXPORTED_TARGETS})
add_dependencies(nodo_servidor
          beginner_tutorials_generate_messages_cpp
          ${catkin_EXPORTED_TARGETS})
add_dependencies(nodo_cliente
          beginner_tutorials_generate_messages_cpp
          ${catkin_EXPORTED_TARGETS})
add_dependencies(nodo_actionLib_cliente
          beginner_tutorials_generate_messages_cpp
          ${catkin_EXPORTED_TARGETS})
add_dependencies(nodo_actionLib_servidor
          beginner_tutorials_generate_messages_cpp
          ${catkin_EXPORTED_TARGETS})
#add_dependencies(nodo_escribe_SP
#          beginner_tutorials_generate_messages_cpp
#          ${catkin_EXPORTED_TARGETS})
#add_dependencies(nodo_leer_SP
#          beginner_tutorials_generate_messages_cpp
#          ${catkin_EXPORTED_TARGETS})


## LIBRARIES
 target_link_libraries (nodo_emisor
  ${catkin_LIBRARIES}
 )
 target_link_libraries (nodo_receptor
  ${catkin_LIBRARIES}
 )
 target_link_libraries (nodo_servidor
  ${catkin_LIBRARIES}
 )
 target_link_libraries (nodo_cliente
  ${catkin_LIBRARIES}
 )
 target_link_libraries (nodo_actionLib_servidor
  ${catkin_LIBRARIES}
 )
 target_link_libraries (nodo_actionLib_cliente
  ${catkin_LIBRARIES}
 )

# target_link_libraries (nodo_leer_SP
#  ${catkin_LIBRARIES}
# )
# target_link_libraries (nodo_escribe_SP
#  ${catkin_LIBRARIES}
# )

