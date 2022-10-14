# Python 2/3 compatibility imports
from __future__ import print_function
from six.moves import input

import sys
import copy
import rospy
import moveit_commander
import moveit_msgs.msg
import geometry_msgs.msg

from math import pi, tau, dist, fabs, cos

from std_msgs.msg import String
from moveit_commander.conversions import pose_to_list

# connecte le robot à rviz
moveit_commander.roscpp_initialize(sys.argv)
rospy.init_node("move_group_python_interface_tutorial", anonymous=True)
# initialise l'objet à commander, récupère les listes de joints et links à commander
robot = moveit_commander.RobotCommander()
# objet faisant le lien entre le robot et le monde
scene = moveit_commander.PlanningSceneInterface()
# définition des links et joints à bouger
rospy.sleep(2)
group_name = "hc10_arm"
move_group = moveit_commander.MoveGroupCommander(group_name)
move_group.set_goal_tolerance(0.1)
rospy.sleep(2)

# coordonnée de la boite : x=0 ; y = 1 ; z = 0.2
# taille cube de 0.2 de coté.

# définition des points à atteindre 
pose_goal = []
pose_goal0 = geometry_msgs.msg.Pose()
pose_goal0.orientation.w = 1.0
pose_goal0.position.x = -0.3
pose_goal0.position.y = 1
pose_goal0.position.z = 0.2
pose_goal.append(pose_goal0)

pose_goal1 = geometry_msgs.msg.Pose()
pose_goal1.orientation.w = 1.0
pose_goal1.position.x = 0.3
pose_goal1.position.y = 1
pose_goal1.position.z = 0.2
pose_goal.append(pose_goal1)

pose_goal2 = geometry_msgs.msg.Pose()
pose_goal2.orientation.w = 1.0
pose_goal2.position.x = 0
pose_goal2.position.y = 0.3
pose_goal2.position.z = 1
pose_goal.append(pose_goal2)

pose_goal3 = geometry_msgs.msg.Pose()
pose_goal3.orientation.w = 1.0
pose_goal3.position.x = 0
pose_goal3.position.y = 0.6
pose_goal3.position.z = 1
pose_goal.append(pose_goal3)

# génération de la trajectoire pour atteindre chaque point
for i in pose_goal:
    move_group.set_pose_target(i)
    success = move_group.go(wait=True)
    move_group.stop()
    rospy.sleep(5)

move_group.clear_pose_targets()