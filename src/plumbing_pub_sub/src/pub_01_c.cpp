#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>      //实现数据拼接

/*
    发布方实现：
        1、包含头文件
        2、初始化节点
        3、创建节点句柄
        4、创建发布对象
        5、编写发布逻辑并发布数据

*/

int main(int argc, char  *argv[])
{
    //解决中文乱码
    setlocale(LC_ALL, "");
    
    //2、初始化节点
    ros::init(argc,argv,"ergouzi");

    //3、创建节点句柄
    ros::NodeHandle nh;

    //4、创建发布对象
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10); //nh.advertise<数据类型>(话题，队列大小)
    
    //5、编写发布逻辑并发布数据
    //要求以10Hz的频率发布数据，并在文本后面添加编号

    //先创建发布类型和变量
    std_msgs::String msg;
    //发布频率
    ros::Rate rate(10);     //以10Hz的频率发送数据，与rate.sleep()配套使用
    //添加编号
    int count = 0;
    
    //休眠三秒，防止订阅者遗失部分数据
    ros::Duration(3).sleep();

    //编写循环，循环中发布数据
    while(ros::ok())        //节点不死
    {
        count++;
        //msg.data = "hello";

        std::stringstream ss;   //创建拼接变量
        ss<<"hello,你好-->"<<count;//拼接文本消息和编号
        msg.data = ss.str();

        pub.publish(msg);

        //日志输出。让消息在终端显示出来,或者在终端使用   rostopic echo 话题<fang>
        ROS_INFO("发布的数据是：%s",ss.str().c_str());  //或者采用msg.date.c_str()


        rate.sleep();


    }
 
    
    return 0; 
}
