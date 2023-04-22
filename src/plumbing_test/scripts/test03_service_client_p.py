#! usr/bin/env python

"""
/*
    服务名称与消息获取：
        获取话题：rosservice list  --------------------------->/spawn
        获取消息类型：rosservice type /spawn  ----------------->turtlesim/Spawn
        获取消息格式：rossrv info turtlesim/Spawn-------------->float32 x
                                                              float32 y
                                                              float32 theta
                                                              string name
                                                              ---
                                                              string name

*/



"""




"""
/*
    需求：向服务器发送请求，生成一只新乌龟
        话题：/spawn
        消息：turtlesim/Spawn


    1、导包
    2、初始化 ROS 节点
    3、创建客户端对象
    4、组织数据并发送
    5、处理响应
*/
"""

import rospy
from turtlesim.srv import Spawn, SpawnRequest, SpawnResponse
#from turtlesim.srv import *

if __name__ == "__main__":
    # 2、初始化 ROS 节点
    rospy.init_node("service_call_p")

    # 3、创建客户端对象
    client = rospy.ServiceProxy("/spawn",Spawn)

    # 4、组织数据并发送
    # 4-1 组织数据
    request = SpawnRequest()
    request.x = 6.0
    request.y = 6.0
    request.theta = -3
    request.name = "turtle3"
    # 4-2 判断服务器状态并发送
    # 方案一：
    # rospy.wait_for_service("/spawn")
    # 方案二：
    client.wait_for_service()
    try:
        # 4-3 发送数据
        response = client.call(request)
        # 5、处理响应
        rospy.loginfo("生成乌龟的名字叫：%s",response.name)
    except Exception as e:
        rospy.logerr("请求处理异常")