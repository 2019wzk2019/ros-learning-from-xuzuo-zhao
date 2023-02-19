#include "ros/ros.h"
#include "plumbing_pub_sub/person.h"

int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");

    //初始化ros节点
    ros::init(argc, argv, "monitor");
    //创建ros句柄
    ros::NodeHandle nh;

    //创建发布者对象
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::person>("liaotian", 10);
    //编写发布逻辑，发布数据
    //创建被发布的数据
    plumbing_pub_sub::person kerry;
    kerry.name = "kerry";
    kerry.age = 14;
    kerry.height = 1.70;
    //设置发布频率
    ros::Rate rate(1);
    //循环发布数据
    while(ros::ok())
    {
        //发布数据
        pub.publish(kerry);
        rate.sleep();
        ROS_INFO("my name is %s, my age is %d, my height is %.2f", kerry.name.c_str(), kerry.age, kerry.height);
        ros::spinOnce();
    }
}