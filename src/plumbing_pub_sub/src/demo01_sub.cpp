#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I HEAR:%s",msg->data.c_str());
}

int main(int argc, char **argv)
{
    //初始化ros节点
    ros::init(argc,argv,"cuihua");
    //创建节点句柄
    ros::NodeHandle nh;
    //创建订阅者对象
    ros::Subscriber sub = nh.subscribe("fang",10,doMsg);
    //处理订阅到的数据
    ros::spin();
    return 0;
}