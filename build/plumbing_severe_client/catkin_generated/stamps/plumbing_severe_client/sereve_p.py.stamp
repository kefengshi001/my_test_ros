#! usr/bin/env python

import rospy
from plumbing_severe_client.srv import AddInts,AddIntsRequest,AddIntsResponse
# from plumbing_severe_client.srv import *
import sys
"""
    服务端：解析客户请求，产生响应。
        1、导包；
        2、初始化ROS节点；
        3、创建服务端对象；
        4、处理请求并产生响应（回调函数）  #处理请求的时间由client来决定，故采用回调函数
        5、spin()。
"""
def doNums(request):
    #1. 解析提交的两个整数
    num1 = request.num1
    num2 = request.num2
    #2. 求和
    sum = num1 + num2
    #3. 将所得结果封装进响应
    response = AddIntsResponse()
    response.sum = sum

    rospy.loginfo("服务器解析数据 num1 = %d, num2 = %d",request.num1,request.num2)
    rospy.loginfo("响应的结果 sum = %d",response.sum)
    return response 

if __name__ == "__main__":
    # 2、初始化ROS节点；
    rospy.init_node("heiShui")

    # 3、创建服务端对象；
    severe = rospy.Service("addInts",AddInts,doNums) #话题 数据类型 回调函数
    rospy.loginfo("服务器已经启动")
    # 4、处理请求并产生响应（回调函数） 

    # 5、spin()    
    rospy.spin()


# //服务端话题测试
# 1、在工作空间先source；
# 2、终端执行rosrun 包名 映射名
# 3、终端执行rosservice call 话题名 （最后空格加两次Tab回车）


#相关配置
#1、添加可执行权限
    # 在scripts文件夹下打开终端，运行chmod +x *.py
#2、配置CMakeList.txt
# catkin_install_python(PROGRAMS
#   scripts/sereve_p.py
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )