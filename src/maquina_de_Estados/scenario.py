from morse.builder import *

# A 'naked' PR2 robot to the scene
james = BarePR2()
james.translate(x=2.5, y=3.2, z=0.0)

# An odometry sensor to get odometry information
odometry = Odometry()
james.append(odometry)
odometry.add_interface('ros', topic="/odom")

# Keyboard control
keyboard = Keyboard()
james.append(keyboard)

# Set the environment
env = Environment('tum_kitchen/tum_kitchen')
env.aim_camera([1.0470, 0, 0.7854])
