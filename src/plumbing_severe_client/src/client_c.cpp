#include "ros/ros.h"
#include "plumbing_severe_client/AddInts.h"

/*
    客户端实现流程：
        1、包含头文件；
        2、创建Ros节点；
        3、创建ros句柄；
        4、创建客户端对象；
        5、处理并产生响应；
*/

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    //判命令行传入参数是否正确，该程序需要传递两个参数进数组
    // 故argv数组由三个元素组成，分别为 文件名 参数1 参数二
    if (argc != 3)
    {
        ROS_INFO("参数传递有误，程序结束。");
        return 0;
    }
    
    // 2、创建Ros节点；
    ros::init(argc,argv,"daBao");

    // 3、创建ros句柄；
    ros::NodeHandle nh;

    // 4、创建客户端对象；
    ros::ServiceClient client = nh.serviceClient<plumbing_severe_client::AddInts>("addInts");//括号内是话题，应与severe里面保持一致。

    // 5、处理并产生响应；
    plumbing_severe_client::AddInts ai;//定义数据对象
    // 5-1 处理请求
    ai.request.num1 = atoi(argv[1]);    //argv[]里面存放的时char类型的字符，atoi的作用是将char类型的字符转化为数字
    ai.request.num2 = atoi(argv[2]);

    //程序休眠等待服务端启动
    //方案一
    //client.waitForExistence();

    //方案二
    ros::service::waitForService("addInts");//括号内为话题名
    // 5-2 组织响应
    bool flag = client.call(ai);
    if (flag)
    {
        ROS_INFO("响应成功！sum = %d",ai.response.sum);
    }else{
        ROS_INFO("处理失败。");
    }
    return 0;

}
