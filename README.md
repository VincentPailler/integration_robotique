# integration_robotique
Dans un terminal

git clone https://github.com/VincentPailler/integration_robotique.git

renommer le dossier integration robotique en catkin_ws

Ouvrir un second terminal

Faire les commandes suivantes dans les 2 terminaux :
. /opt/ros/noetic/setup.bash
. devel/setup.bash

catkin build

Dans un terminal lancez Rviz avec la commande suivante:
roslaunch hc10_move_config demo.launch

Dans l'autre terminal, lancez le script python :
Ce script genère une trajectoire avec 4 points à atteindre tout en évitant poteaux et le sol.
python3 src/trajectoire.py


Pour ajouter gazebo, dans un terminal lancez la commande suivante:
roslaunch hc10_move_config demo_gazebo.launch

Ajouter une boîte en x=0, y=1, z=0.2 avec une épaisseur de 0.2

Une fois cela fait lancer le programme python. ATTENTION nos machines n'ont pas pu supporter le lancement de ce programme.
python3 src/trajectoire_finale.py
