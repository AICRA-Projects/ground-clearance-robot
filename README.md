# ground-clearance-robot
A Robot that can move autonomously from place to place to achieve a set of goals. Mobile robots have been around for some time. If we think about it on the most basic level, the small vacuum cleaner that runs along your floor is a mobile robot. Since then, the technology has advanced significantly. Today, they are used in factories, for military operations, in healthcare, for search and rescue, as security guards, and in homes.
AGVs have been the traditional method for autonomous transport, but mobile robots have adapted to provide the support demanded by today’s end user, such as less predictable floor layouts and workstation use.
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
## Methodoly:
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

