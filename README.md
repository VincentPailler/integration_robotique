# integration_robotique
git clone https://github.com/VincentPailler/integration_robotique.git

Ouvrir deux terminaux

cd catkin_ws

Faire les commandes suivantes dans les 2 terminaux
. /opt/ros/noetic/setup.bash
catkin build
. devel/setup.bash

Dans un terminal lancez Rviz avec la commande suivante:
roslaunch hc10_move_config demo.launch

dans l'autre terminal, lancez le script python :

python3 src/trajectoire.py

Modification des points à atteindre par le robot:

Modifier les coordonnées du point que vous voulez changer puis ajoutez le à la liste des positions

pose_goal0 = geometry_msgs.msg.Pose()
pose_goal0.orientation.w = 1.0
pose_goal0.position.x = 0.5
pose_goal0.position.y = 0.4
pose_goal0.position.z = 1
pose_goal.append(pose_goal0)


Pour ajouter un obstacle suivez ces instructions : 


box_pose = geometry_msgs.msg.PoseStamped()
box_pose.header.frame_id = "world"
box_pose.pose.orientation.w = 1.0
box_pose.pose.position.x = 0
box_pose.pose.position.y = 0.45
box_pose.pose.position.z = 1 
box_name = "poto1"
scene.add_box(box_name, box_pose, size=(0.2, 0.2, 2))

Pour ajouter gazebo, dans un terminal lancez la commande suivante:
roslaunch hc10_move_config demo_gazebo.launch

