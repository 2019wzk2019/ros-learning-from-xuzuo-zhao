#include "ros/ros.h"

int main(int argc, char **argv)
{
    //初始化ros节点
    ros::init(argc, argv, "set_param_c");
    //创建ros句柄
    ros::NodeHandle nh;
    //zeng
    nh.setParam("type", "huang");
    nh.setParam("radius", 0.15);
    //gai
    ros::param::set("type", "bai");
    ros::param::set("radius", 0.14);






}