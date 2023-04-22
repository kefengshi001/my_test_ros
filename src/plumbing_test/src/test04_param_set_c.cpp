#include "ros/ros.h"

/*
    参数获取：rosparam list
    响应结果：/turtlesim/background_b
            /turtlesim/background_g
            /turtlesim/background_r



    参数设置：
        1、初始化节点
        2、
            2-1 方案一：ros::NodeHandle     setParam("键",值)
                2.1 创建节点句柄
                2.2 修改参数
            
            2-2 方案二：ros::param          set("键"，值)
                

*/

int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"set_bgcolor");
    // // 方案一：
    // ros::NodeHandle nh("turtlesim");
    // nh.setParam("background_r",0);
    // nh.setParam("background_g",0);
    // nh.setParam("background_b",0);

    // 方案二：
    ros::param::set("/turtlesim/background_r",0);
    ros::param::set("/turtlesim/background_g",0);
    ros::param::set("/turtlesim/background_b",0);

    return 0;
}
