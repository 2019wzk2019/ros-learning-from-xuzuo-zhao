#include "ros/ros.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "get_param_c");
    ros::NodeHandle nh;

    double radius = nh.param("radius", 0.5);
    //double radius = 1.2;
    ROS_INFO("radius = %.2f", radius);

    double radius2 = 0.0;
    bool result = nh.getParam("radius", radius2);
    if(result)
    {
        ROS_INFO("radius2 = %.2f", radius2);
    }
    else
    {
        ROS_INFO("no result");
    }

    std::vector<std::string> names;
    nh.getParamNames(names);
    for(auto &&name : names)
    {
        ROS_INFO("BIAN LI:%s", name.c_str());
    }

    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("r");
    ROS_INFO("is radius exist? %d", flag1);
    ROS_INFO("is r exist? %d", flag2);

    std::string key;
    nh.searchParam("param_int",key);
    ROS_INFO("%s",key.c_str());
    return 0;

}