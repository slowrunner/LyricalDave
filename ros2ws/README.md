# Lyrical-Dave  ROS 2 Workspace


### Base Lyrical-Dave  Raspberry Pi 4 Processor Utilization

Base Lyrical-Dave ROS 2 configuration is:  
- ros2_gopigo3_node GoPiGo3 ROS2 publishes odom, offers /cmd_vel etc  
- battery_node: publishes /battery_state  
- docking_node: publishes /dock_status, offers /dock and /undock services  
- dave_node: calls /dock when vBatt<10v, and calls /undock when charge current < -175mA  
- odometer: logs all /cmd_vel movement (does not record dock/undock movement)  
- joy_node: handles wireless SNES joy controller to publish /cmd_vel  
- say_node: TTS speech server offers /say {"phrase"} service  




NOTE:  Due to the new GoPiGo3 API being a virtual environment installation,  
the virtutal environment site packages are added to the PYTHONPATH before  
launching or ros2 run of all nodes.  See start_LyricalDave.sh and ss.sh 


```

Base Lyrical-Dave Processor Utilization:  
- Total Load (1 min uptime / 4 cores):   40%
- Total CPU usage: 13% - 20%


14:58:57 1m load: 1.62  40.% demand on RPi 4's four cores
14:58:57 total cpu usage: 20% of RPi 4 CPU
 
               total        used        free      shared  buff/cache   available
Mem:           3.7Gi       1.4Gi       119Mi        10Mi       2.3Gi       2.3Gi
Swap:          2.0Gi        60Ki       2.0Gi
 *** 
 
14:59:03 1m load: 1.57  39.% demand on RPi 4's four cores
14:59:03 total cpu usage: 13% of RPi 4 CPU
 
               total        used        free      shared  buff/cache   available
Mem:           3.7Gi       1.4Gi       118Mi        10Mi       2.3Gi       2.3Gi
Swap:          2.0Gi        60Ki       2.0Gi
 *** 



(gopigo3) ubuntu@U26LDave:~/LyricalDave/ros2ws$ ros2 node list
/battery
/dave_node
/docking
/gopigo3_node
/joint_state_publisher
/joy_node
/odometer
/robot_state_publisher
/teleop_twist_joy_node

```
