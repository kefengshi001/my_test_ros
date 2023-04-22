#include "ros/ros.h"
#include "turtlesim/Pose.h"

/*
    话题：/turtle1/pose     <rostopic list>
        获取消息类型：rostopic type  /turtle1/pose
    消息：turtlesim/Pose    <rosmsg info turtlesim/Pose>

    turtlesim/Pose:
        float32 x
        float32 y
        float32 theta
        float32 linear_velocity
        float32 angular_velocity


    需求：订阅乌龟的位姿信息，并输出到控制台
    1、包含头文件
    2、初始化Ros节点
    3、创建节点句柄
    4、创建订阅对象
    5、处理订阅数据
    6、spin()
*/

void doPose(const turtlesim::Pose::ConstPtr &pose)
{
    ROS_INFO("乌龟的位姿信息：坐标 (%.2f, %.2f), 朝向： %.2f, 线速度：%.2f, 角速度：%.2f",pose->x,pose->y,pose->theta,pose->linear_velocity,pose->angular_velocity);
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    //2、初始化ros节点
    ros::init(argc,argv,"sub_pose");

    //3、创建节点句柄
    ros::NodeHandle nh;
    
    //4、创建订阅对象
    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose",100,doPose);

    //5、处理订阅的数据

    //6、spin()
    ros::spin();

    return 0;
}
