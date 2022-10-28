# Python 2/3 compatibility imports
from __future__ import print_function
from six.moves import input

import sys
import copy
import rospy
import moveit_commander
import moveit_msgs.msg
import geometry_msgs.msg
import numpy as np

from math import pi, tau, dist, fabs, cos

from std_msgs.msg import String
from moveit_commander.conversions import pose_to_list

def get_quaternion_from_euler(roll, pitch, yaw):
  """
  Convert an Euler angle to a quaternion.
   
  Input
    :param roll: The roll (rotation around x-axis) angle in radians.
    :param pitch: The pitch (rotation around y-axis) angle in radians.
    :param yaw: The yaw (rotation around z-axis) angle in radians.
 
  Output
    :return qx, qy, qz, qw: The orientation in quaternion [x,y,z,w] format
  """
  qx = np.sin(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) - np.cos(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
  qy = np.cos(roll/2) * np.sin(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.cos(pitch/2) * np.sin(yaw/2)
  qz = np.cos(roll/2) * np.cos(pitch/2) * np.sin(yaw/2) - np.sin(roll/2) * np.sin(pitch/2) * np.cos(yaw/2)
  qw = np.cos(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
 
  return [qx, qy, qz, qw]

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

qx,qy,qz,qw = get_quaternion_from_euler(0,pi/2,0)

# définition des points à atteindre 
pose_goal = []
pose_goal0 = geometry_msgs.msg.Pose()
pose_goal0.orientation.x = qx
pose_goal0.orientation.y = qy
pose_goal0.orientation.z = qz
pose_goal0.orientation.w = qw
pose_goal0.position.x = -0.3
pose_goal0.position.y = 1
pose_goal0.position.z = 0.2
pose_goal.append(pose_goal0)

qx,qy,qz,qw = get_quaternion_from_euler(0,-pi/2,0)

pose_goal1 = geometry_msgs.msg.Pose()
pose_goal1.orientation.x = qx
pose_goal1.orientation.y = qy
pose_goal1.orientation.z = qz
pose_goal1.orientation.w = qw
pose_goal1.position.x = 0.3
pose_goal1.position.y = 1
pose_goal1.position.z = 0.2
pose_goal.append(pose_goal1)

qx,qy,qz,qw = get_quaternion_from_euler(-pi/2,0,0)

pose_goal2 = geometry_msgs.msg.Pose()
pose_goal2.orientation.x = qx
pose_goal2.orientation.y = qy
pose_goal2.orientation.z = qz
pose_goal2.orientation.w = qw
pose_goal2.position.x = 0
pose_goal2.position.y = 0.3
pose_goal2.position.z = 0.2
pose_goal.append(pose_goal2)

qx,qy,qz,qw = get_quaternion_from_euler(pi/2,0,0)

pose_goal3 = geometry_msgs.msg.Pose()
pose_goal3.orientation.x = qx
pose_goal3.orientation.y = qy
pose_goal3.orientation.z = qz
pose_goal3.orientation.w = qw
pose_goal3.position.x = 0
pose_goal3.position.y = 1.4
pose_goal3.position.z = 0.2
pose_goal.append(pose_goal3)

# génération de la trajectoire pour atteindre chaque point
for i in pose_goal:
    move_group.set_pose_target(i)
    success = move_group.go(wait=True)
    move_group.stop()
    rospy.sleep(5)

move_group.clear_pose_targets()