#include "ros/ros.h"
#include "std_msgs/String.h" //普通文本类型的消息
#include <sstream>

int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");
    //初始化ros节点；
    ros::init(argc, argv,"erGouzi");
    //创建节点句柄；
    ros::NodeHandle nh;
    //创建发布者对象；
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);
    //编写发布逻辑并发布数据
    //10hz 频率频率发布数据，文本后添加编号
    //先创建被发布的消息
    std_msgs::String msg;
    //发布频率
    ros::Rate rate(10);
    //设置编号
    int count = 0;
    //编写循环，循环中发布数据
    while(ros::ok())
    {
        count++;
        //实现字符串拼接数字ddd
        std::stringstream ss;
        ss << "hello --->" << count;
        //msg.data = "hello";
        msg.data = ss.str();
        pub.publish(msg);
        //添加日志
        ROS_INFO("data !!!!!!!!!!!!11111 ");
        ROS_INFO("data being published is %s",msg.data.c_str());
        rate.sleep();
        ros::spinOnce();//官方建议，处理会调函数
    }

}