#include "ros/ros.h"
#include "plumbing_pub_sub/person.h"

void doperson(const plumbing_pub_sub::person::ConstPtr & kerry)
{
    ROS_INFO("my name is %s, my age is %d, my height is %.2f", kerry -> name.c_str(), kerry -> age, kerry -> height);

}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    //初始化ros节点
    ros::init(argc,argv,"parents");
    //创建ros句柄
    ros::NodeHandle nh;
    //创建订阅对象
    ros::Subscriber sub = nh.subscribe<plumbing_pub_sub::person>("liaotian",10,doperson);
    //回调函数处理
    
    //spin
    ros::spin();
    return 0;

}