#include "ros/ros.h"

/*
    在该文件中实现参数的查询：
        实现：
            ros::NodeHandle----

                param(键,默认值) 
                    存在，返回对应结果，否则返回默认值

                getParam(键,存储结果的变量)
                    存在,返回 true,且将值赋值给参数2
                    若果键不存在，那么返回值为 false，且不为参数2赋值

                getParamCached(键,存储结果的变量)--提高变量获取效率
                    存在,返回 true,且将值赋值给参数2
                    若果键不存在，那么返回值为 false，且不为参数2赋值

                getParamNames(std::vector<std::string>)
                    获取所有的键,并存储在参数 vector 中 

                hasParam(键)
                    是否包含某个键，存在返回 true，否则返回 false

                searchParam(参数1，参数2)
                    搜索键，参数1是被搜索的键，参数2存储搜索结果的变量

            ros::param---与NodleHandle类似
*/
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    
    // 初始化ROS节点
    ros::init(argc,argv,"parm_get_c");

    //创建节点句柄
    ros::NodeHandle nh;

        //ros::NodeHandle--------------------------
        // 1、param(键,默认值)
                // 存在，返回对应结果，否则返回默认值 
        double radius_01  = nh.param("radius",0.01);
        ROS_INFO("radius = %.2f",radius_01);
        
        // 2、getParam(键,存储结果的变量)
                // 存在,返回 true,且将值赋值给参数2
                // 若果键不存在，那么返回值为 false，且不为参数2赋值
        double radius_02;
        bool result_01 = nh.getParam("radius",radius_02);
        if (result_01)
        {
            ROS_INFO("获取的半径是：radius = %.2f",radius_02);
        }else{
            ROS_INFO("被查询变量不存在");
        }
        

        // 3、getParamCached(键,存储结果的变量)--提高变量获取效率
                // 存在,返回 true,且将值赋值给参数2
                // 若果键不存在，那么返回值为 false，且不为参数2赋值
        double radius_03;
        bool result_02 = nh.getParamCached("radius",radius_03);
        if (result_02)
        {
            ROS_INFO("获取的半径是：radius = %.2f",radius_03);
        }else{
            ROS_INFO("被查询变量不存在");
        }


        // 4、getParamNames(std::vector<std::string>)
                //获取所有的键,并存储在参数 vector 中 
        std::vector<std::string>names;
        nh.getParamNames(names);
        for (auto &&name : names)
        {
            ROS_INFO("遍历的元素：%s",name.c_str());
        }    

        // 5、hasParam(键)
                //是否包含某个键，存在返回 true，否则返回 false
        bool result_03 = nh.hasParam("radius");
        bool result_04 = nh.hasParam("radiusxxx");
        ROS_INFO("radius 存在吗？%d",result_03);
        ROS_INFO("radius 存在吗？%d",result_04);



        // 6、searchParam(参数1，参数2)
                //搜索键，参数1是被搜索的键，参数2存储搜索结果的变量
        std::string key;    //该变量的类型根据函数要求来定制
        nh.searchParam("radius",key);  
        ROS_INFO("搜索结果：%s",key.c_str());   //key 值为/radius



    //ros::param----------------------------------------------
    // 1、ros::param::param(键,默认值)
            // 存在，返回对应结果，否则返回默认值 
    double p1_result = ros::param::param("radius",p1_result);
    ROS_INFO("radius = %.2f",p1_result);

    // 2、ros::param::getCached(键,存储结果的变量)
            // 存在,返回 true,且将值赋值给参数2
            // 若果键不存在，那么返回值为 false，且不为参数2赋值
    double radius_getParam;
    bool p2_result = ros::param::getCached("radius",radius_getParam);
    if (p2_result)
    {
        ROS_INFO("获取的半径是：radius = %.2f",radius_getParam);
    }else{
        ROS_INFO("被查询变量不存在");
    }

    //3、ros::param::getParamNames(std::vector<std::string>)
    //获取所有的键,并存储在参数 vector 中 
    std::vector<std::string>lists;
    ros::param::getParamNames(lists);
    for (auto &&list : lists)
    {
        ROS_INFO("遍历的元素：%s",list.c_str());
    }
    
    //4、ros::param::has(键)
    //是否包含某个键，存在返回 true，否则返回 false
    bool p_has_01 = ros::param::has("radius");
    bool p_has_02 = ros::param::has("radiusxxx");
    ROS_INFO("radius 存在吗？%d",p_has_01);
    ROS_INFO("radius 存在吗？%d",p_has_02);


    //5、ros::param::search(参数1，参数2)
    //搜索键，参数1是被搜索的键，参数2存储搜索结果的变量
    std::string value;
    ros::param::search("radius",value);
    ROS_INFO("搜索结果：%s",value.c_str());   //value 值为/radius



    return 0;
}

