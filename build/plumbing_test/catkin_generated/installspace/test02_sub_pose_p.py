#!/usr/bin/env python3
import rospy
from turtlesim.msg import Pose 
"""
    话题：/turtle1/pose     <rostopic list>
        获取消息类型：rostopic type  /turtle1/pose
    消息：turtlesim/Pose    <rosmsg info turtlesim/Pose>

    turtlesim/Pose:
        float32 x
        float32 y
        float32 theta
        float32 linear_velocity
        float32 angular_velocity

    需求：订阅并输出乌龟位姿信息

    1、导包；
    2、初始化ROS节点；
    3、创建订阅对象；
    4、使用回调函数处理订阅消息；
    5、spin()
"""
def doPose(pose):
    rospy.loginfo("乌龟的位姿信息：坐标 (%.2f, %.2f), 朝向： %.2f, 线速度：%.2f, 角速度：%.2f",pose.x,pose.y,pose.theta,pose.linear_velocity,pose.angular_velocity)

if __name__ == "__main__":
    # 2、初始化ROS节点；
    rospy.init_node("sub_pose_p")

    # 3、创建订阅对象；
    sub = rospy.Subscriber("/turtle1/pose",Pose,doPose,queue_size=10)
    # 4、使用回调函数处理订阅消息；

    # 5、spin()
    rospy.spin()