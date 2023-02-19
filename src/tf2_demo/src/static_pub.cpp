 #include "ros/ros.h"
 #include "tf2_ros/static_transform_broadcaster.h"
 #include "geometry_msgs/TransformStamped.h"
 #include "tf2/LinearMath/Quaternion.h"

 int main(int argc, char **argv)
 {
    ros::init(argc, argv, "static_brocast");
    ros::NodeHandle nh;
    tf2_ros::StaticTransformBroadcaster pub;
    // 创建发布消息
    geometry_msgs::TransformStamped tfs;
    tfs.header.stamp = ros::Time::now();
    tfs.header.frame_id = "base_link";//相对坐标系关系中被参考的那一个
    tfs.child_frame_id = "laser";
    tfs.transform.translation.x = 0.2;
    tfs.transform.translation.y = 0.0;
    tfs.transform.translation.z = 0.5;
    //需要根据欧拉角转换
    tf2::Quaternion qtn;//创建四元数
    //向该对象设置欧拉角，将欧拉角转换为四元数
    qtn.setRPY(0, 0, 0);
    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();
    //发布数据
    pub.sendTransform(tfs);
    //spin
    ros::spin();
    return 0;
 }