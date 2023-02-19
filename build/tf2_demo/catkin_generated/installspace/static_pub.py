#!/usr/bin/env python2
# -*- coding: UTF-8 -*-
import rospy
import tf2_ros
import tf
from geometry_msgs.msg import TransformStamped

if __name__ == "__main__":
    #初始化节点
    rospy.init_node("static_pub")
    #创建发布对象
    pub = tf2_ros.StaticTransformBroadcaster()
    #组织被发布的数据
    ts = TransformStamped()
    #header
    ts.header.stamp = rospy.Time.now()
    ts.header.frame_id = "base_link"
    #child
    ts.child_frame_id = "laser"
    #相对关系（偏移与四元数）
    ts.transform.translation.x = 0.2
    ts.transform.translation.y = 0.0
    ts.transform.translation.z = 0.5
    #先从欧拉角转换成四元数
    qtn = tf.transformations.quaternion_from_euler(0, 0, 0)
    #设置四元数
    ts.transform.rotation.x = qtn[0]
    ts.transform.rotation.y = qtn[1]
    ts.transform.rotation.z = qtn[2]
    ts.transform.rotation.w = qtn[3]
    #发布数据
    pub.sendTransform(ts)
    #spin()
    rospy.spin()

 