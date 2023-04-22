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

#include "ros/ros.h"
#include "turtlesim/Spawn.h"
/*
    需求：向服务器发送请求，生成一只新乌龟
        话题：/spawn
        消息：turtlesim/Spawn


    1、包含头文件
    2、初始化 ROS 节点
    3、创建节点句柄
    4、创建客户端对象
    5、组织数据并发送
    6、处理响应
*/

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 2、初始化 ROS 节点
    ros::init(argc,argv,"service_call");

    // 3、创建节点句柄
    ros::NodeHandle nh;

    // 4、创建客户端对象
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    // 5、组织数据并发送
    //5-1 组织请求数据
    turtlesim::Spawn spawn;
    spawn.request.x = 8.8;
    spawn.request.y = 8.8;
    spawn.request.theta = 8.8;
    spawn.request.name = "turtle2";
    //5-2 发送请求  
    // 判断服务器状态
    // 方案一：
    // ros::service::waitForService("/spawn");
    //方案二：
    client.waitForExistence();
    bool flag = client.call(spawn);//flag 接收响应状态，响应结果也会被设置为spawn对象
    // 6、处理响应
    if (flag)
    {
        ROS_INFO("乌龟生成成功，新乌龟叫：%s",spawn.response.name.c_str());
    }else
    {
        ROS_INFO("响应失败！！！");
    }
    
    

    return 0;
}
