# ground-clearance-robot
A Robot that can move autonomously from place to place to achieve a set of goals. Mobile robots have been around for some time. If we think about it on the most basic level, the small vacuum cleaner that runs along your floor is a mobile robot. Since then, the technology has advanced significantly. Today, they are used in factories, for military operations, in healthcare, for search and rescue, as security guards, and in homes.
AGVs have been the traditional method for autonomous transport, but mobile robots have adapted to provide the support demanded by today’s end user, such as less predictable floor layouts and workstation use.

## how to operate
### step 1:  Give Power to the robot by connecting White Usb Cable with USB connector of black power bank is in downward 
### step 2:   press "On" Red switch and Green Light will get ON in 360 degree RPlidar   
### step 3:   wait for the RPlidar stops or delay for fraction of seconds 
### step 4:  After the delay motor activation and robot comes in motion
### step 5:  Robot will start moving without getting collisions 

## Hardwares:
* I shaped Motor 300rpm
* Arduino Nano 
* L298n Motor Driver 
* Metal chassis off Road 
* Arcylic chassis 
* RPI Lidar 360 
* Jumper Wires Male - female and Male -male 
* Lithium ION battery 12 v 
* Bread Board 
* Wheels 
* Nvidia JetSON Nano 
* usb Type C
* Metal Button /switch 
* Lithium ION battery Holder 
* 12v connector Male and Female 
* Mobile POWER bank 
* Samsung SD CARD 32gb  

## Methodology:
1. Device Settings
 * Use following udev rules to set permission for a rplidar device.

``` KERNEL=="ttyUSB*", MODE="0666" ```
 * For fixed rplidar port, you can using the script file to remap the USB port name:
 
``` ./scripts/create_udev_rules.sh ```
 * Once you have change the USB port remap, you can change the launch file about the serial_port value.

``` <param name="serial_port" type="string" value="/dev/rplidar"/> ```

2. Launch File Examples
 * Check the authority of rplidar's serial-port :
 
``` ls -l /dev |grep ttyUSB ```
 * Add the authority of write: (such as /dev/ttyUSB0)

``` sudo chmod 666 /dev/ttyUSB0 ```
 * Start a rplidar node and view the scan result in rviz.

``` 
 $ roslaunch rplidar_ros view_rplidar.launch    #for rplidar A1/A2
or
 $ roslaunch rplidar_ros view_rplidar_a3.launch #for rplidar A3
```
 * Start a rplidar node and run rplidar client process to print the raw scan result

```
 $ roslaunch rplidar_ros rplidar.launch  #for rplidar A1/A2
or
 $ roslaunch rplidar_ros_a3 rplidar.launch  #for rplidar A3

 $ rosrun rplidar_ros rplidarNodeClient
```
#### ROS Setup :
* Setup your sources.list
Setup your computer to accept software from packages.ros.org
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
* Set up your keys
sudo apt install curl 
###### if you haven't already installed curl 
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
* Installation : sudo apt update
* Desktop-Full Install: sudo apt install ros-melodic-desktop-full
* apt search ros-melodic
* Environment setup : echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
source ~/.bashrc
* Dependencies for building packages : sudo apt install python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential
* Initialize rosdep : sudo apt install python-rosdep       sudo rosdep init

## Rplidar setup :
RPLIDAR is a low cost LIDAR sensor suitable for indoor robotic SLAM application. It provides 360 degree scan field, 5.5hz/10hz rotating frequency with guaranteed 8 meter ranger distance, current more than 16m for A2 and 25m for A3 . By means of the high speed image processing engine designed by RoboPeak, the whole cost are reduced greatly, RPLIDAR is the ideal sensor in cost sensitive areas like robots consumer and hardware hobbyist.
## Rplidar ROS setup :

#### Step 1: Install RPLIDAR ROS Package
* mkdir -p ~/catkin_ws/src
* cd ~/catkin_ws/
* catkin_make
* and source it to bashrc:

* echo "source $HOME/catkin_ws/devel/setup.bash" >> ~/.bashrc
Okay, we’re ready to start installing RPLIDAR ROS package.

* cd src
* sudo git clone  https://github.com/Slamtec/rplidar_ros.git
* catkin_make
Wait for the package compilation to finish. Try launching the package to see if the compilation was successful:

* roslaunch rplidar_ros rplidar.launch
## Step 2 : 
* Setup the service file and udev files for autonomous active of lidar
* Define the script or code of LASER Scan data 
## Step 3:
* Define the decision making script for motor control process
* Follow the arduino code 
## Step 4:
1. Use case: auto start MAVROS node
 * Create a shell script and type the commands that you would execute in a normal terminal. Fro example,
 ```
 mkdir ~/scripts
cd ~/scripts
touch startup_launch.sh
chmod +x startup_launch.sh
 ```
* Type the following in the startup_launch.sh file (you can use the nano startup_launch.sh command). It is assumed that the username is odroid
```
#!/bin/bash
source /opt/ros/kinetic/setup.bash
source /home/odroid/catkin_ws/devel/setup.bash
roslaunch mavros px4.launch
```
* Create mavros.service file in /lib/systemd/system
```
cd /lib/systemd/system
sudo nano mavros.service
```
* Add the following contents:
```
[Unit]
Description=mavros

[Service]
Type=forking
ExecStart=/home/odroid/scripts/startup_launch.sh
Restart=on-failure

[Install]
WantedBy=multi-user.target
```
* Save and exit by hitting CTRL+x, then Y, then [ENTER]
Then run:
```
sudo systemctl daemon-reload

```
* And enable it on boot:
```
sudo systemctl enable mavros.service

```
* Then, reboot and px4.launch should be executed after boot.

To disable a service,
```
sudo systemctl disable mavros.service
```

# Reference :
* https://www.slamtec.com/en/Lidar/A3
* http://wiki.ros.org/rplidar
* https://www.theconstructsim.com/read-laserscan-data/


