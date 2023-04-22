#include "ros/ros.h"

/*
    ros::NodeHandle
        deleteParam("键")
        根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false

    ros::param
        del("键")
        根据键删除参数，删除成功，返回 true，否则(参数不存在)，返回 false
*/

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");

    //ros::NodeHandle------------------------------------------------
    ros::init(argc,argv,"del_parm");
    ros::NodeHandle nh;

    bool result_01 = nh.deleteParam("radius");
    if (result_01)
    {
        ROS_INFO("删除成功");
    }else{
        ROS_INFO("删除失败");

    }
    
    //ros::param--------------------
    bool request_02 = ros::param::del("type_param");
    if (request_02)
        {
            ROS_INFO("删除成功");
        }else{
            ROS_INFO("删除失败");

        }


    return 0;
}
