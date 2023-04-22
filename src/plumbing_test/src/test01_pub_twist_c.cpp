#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

/*
    需求：
        话题：/turtle1/cmd_vel
        消息：geometry_msgs/Twist
    
    1、包含头文件
    2、初始化 ROS 节点
    3、创建节点句柄
    4、创建发布对象
    5、发布逻辑
    6、spinonce()
*/

int main(int argc, char  *argv[])
{
    // 2、初始化 ROS 节点
    ros::init(argc,argv,"mycontrol");

    // 3、创建节点句柄
    ros::NodeHandle nh;

    // 4、创建发布对象
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);

    // 5、发布逻辑
    //设置发布频率
    ros::Rate rate(10); 
    //组织发布消息
    geometry_msgs::Twist twist;//可以在终端输入rosmsg info geometry_msgs/Twist 查看消息类型
    twist.linear.x = 5.0;
    twist.linear.y = 0.0;
    twist.linear.z = 0.0;

    twist.angular.x = 0.0;
    twist.angular.y = 0.0;
    twist.angular.z = 1.0;
    //循环发布消息
    while (ros::ok())
    {
        pub.publish(twist);
        //休眠
        rate.sleep();
        //回头
        // 6、spinonce()
        ros::spinOnce();
    }
    
    
    return 0;
}


//rostopic echo 话题名 可以打印发布的消息内容。