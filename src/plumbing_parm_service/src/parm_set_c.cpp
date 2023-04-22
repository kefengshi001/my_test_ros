#include "ros/ros.h"

/*
    参数服务器操作的新增和修改（二者API一样）实现：
        在ROS中提供了两套API实现参数操作
            ros::NodeHandle
                setParam("键",值)
            
            ros::param
                set("键"，值)
*/

int main(int argc, char  *argv[])
{
    // 初始化节点
    ros::init(argc,argv,"parm_set_c");

    // 创建节点句柄
    ros::NodeHandle nh;

    //参数新增---
    // 方案一：
    nh.setParam("type","xiaoHuang");
    nh.setParam("radius",0.15);
    //方案二：
    ros::param::set("type_param","xiaoBai");
    ros::param::set("radius_param",0.15);

    //参数修改<按照键修改值>
    // 方案一：
    nh.setParam("radius",0.25);
    //方案二：
    ros::param::set("radius_param",0.25);

 

    return 0;
}

/*
    验证：<终端启动>
        1、列出参数服务器的所有参数：rosparam list
        2、获取参数对应的值：       rosparam get /键值
*/  