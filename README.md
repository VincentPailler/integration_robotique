# integration_robotique
Dans un terminal

git clone https://github.com/VincentPailler/integration_robotique.git

renommer le dossier integration robotique en catkin_ws

Ouvrir un second terminal

Faire les commandes suivantes dans les 2 terminaux
. /opt/ros/noetic/setup.bash
catkin build
. devel/setup.bash

Dans un terminal lancez Rviz avec la commande suivante:
roslaunch hc10_move_config demo.launch

Dans l'autre terminal, lancez le script python :
Ce script genère une trajectoire avec 4 points à atteindre tout en évitant poteaux et le sol.
python3 src/trajectoire.py


Pour ajouter gazebo, dans un terminal lancez la commande suivante:
roslaunch hc10_move_config demo_gazebo.launch

