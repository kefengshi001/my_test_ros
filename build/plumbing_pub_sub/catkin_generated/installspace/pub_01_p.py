#!/usr/bin/env python3

import rospy
from std_msgs.msg import String     #发布消息的对象

"""
1、导包；
2、初始化ros节点；
3、创建发布者对象；
4、编写发布逻辑并发布数据。
"""

if __name__ == "__main__":
    
    
    #2、初始化ros节点
    rospy.init_node("sandai")
    #3、创建发布者对象
    pub = rospy.Publisher("che",String,queue_size=10)

    #4、编写发布逻辑并发布数据
    #创建数据
    msg = String()

    #指定发布频率
    rate = rospy.Rate(10)   #一秒钟发十次，与rate.sleep()共同使用

    #设置计数器
    count = 0

    #休眠3秒防止数据丢失
    rospy.sleep(3)
    
    #使用循环发布数据
    while not rospy.is_shutdown():
        count+=1
        msg.data= "hello" + str(count)  #将count转换为字符串和“hello”拼接起来

        #发布数据
        pub.publish(msg)

        #日志输出
        rospy.loginfo("发布的数据：%s",msg.data)

        rate.sleep()
