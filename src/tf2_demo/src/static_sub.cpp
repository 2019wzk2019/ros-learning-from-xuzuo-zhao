#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
/*  
    订阅坐标系信息，生成一个相对于 子级坐标系的坐标点数据，转换成父级坐标系中的坐标点

    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建 TF 订阅节点
        4.生成一个坐标点(相对于子级坐标系)
        5.转换坐标点(相对于父级坐标系)
        6.spin()
*/
int main(int argc, char **argv)
{
    ros::init(argc, argv, "static_sub");
    ros::NodeHandle nh;
    //创建订阅对象 订阅坐标系相对关系
    //创建一个buffer缓存
    tf2_ros::Buffer buffer;
    //创建监听对象，将订阅的数据存入buffer
    tf2_ros::TransformListener listener(buffer);
    //组织一个坐标点数据
    geometry_msgs::PointStamped ps;
    ps.header.frame_id = "laser";
    ps.header.stamp = ros::Time::now();
    ps.point.x = 2.0;
    ps.point.y = 3.0;
    ps.point.z = 5.0;

    //添加休眠
    ros::Duration(2).sleep();
    //转换算法。需要调用tf内置实现
    ros::Rate rate(1);
    while(ros::ok())
    {
        //核心代码 将ps转换成相对于base_link的坐标点
        geometry_msgs::PointStamped ps_out;

        ps_out = buffer.transform(ps,"base_link");
        //最后输出
        ROS_INFO("coordination after transformation:(%.2f, %.2f, %.2f), reference frame: %s",
                    ps_out.point.x, ps_out.point.y, ps_out.point.z, ps_out.header.frame_id.c_str());
        rate.sleep();
        ros::spinOnce();
        
    }

}