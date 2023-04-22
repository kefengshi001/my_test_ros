#! usr/bin/env python

import rospy
# from plumbing_severe_client.srv import AddInts,AddIntsRequest, AddIntsResponse
from plumbing_severe_client.srv import *
"""
    客户端：组织并提交请求，处理服务端响应。
        1、导包；
        2、初始化ROS节点；
        3、创建客户端对象；
        4、组织请求数据，并发送请求；
        5、处理响应。
"""

if __name__ == "__main__":
    #判断传入参数长度
    if len(sys.argv) != 3:
        rospy.logerr("传入参数不对")
        sys.exit(1)

    # 2、初始化ROS节点；
    rospy.init_node("erHei")
    
    # 3、创建客户端对象；
    client = rospy.ServiceProxy("addInts",AddInts) #话题名称  载体类型
    rospy.loginfo("客户端启动")
    # 4、组织请求数据，并发送请求；
    # 解析传入参数
    num1 = int(sys.argv[1])
    num2 = int(sys.argv[2])
   
    # 等待服务端启动
    # 方案一：
    # client.wait_for_service()
    # 方案二
    rospy.wait_for_service("addInts")     #参数为话题
    response = client.call(num1,num2)

    # 5、处理响应
    rospy.loginfo("相应的数据为 sum = %d",response.sum) 


#相关配置
#1、添加可执行权限
    # 在scripts文件夹下打开终端，运行chmod +x *.py
#2、配置CMakeList.txt
# catkin_install_python(PROGRAMS
#   scripts/sereve_p.py
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )