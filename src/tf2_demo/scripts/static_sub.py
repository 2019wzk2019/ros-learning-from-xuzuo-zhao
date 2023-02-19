#! /usr/bin/env python
# -*- coding: UTF-8 -*-
import rospy
import tf2_ros
from tf2_geometry_msgs import tf2_geometry_msgs

if __name__ == "__main__":
    #初始化
    rospy.init_node("static_sub")
    #创建订阅对象
    #创建缓存对象
    buffer = tf2_ros.Buffer()
    #创建订阅对象（将缓存传入）
    sub = tf2_ros.TransformListener(buffer)
    #组织被转换的坐标点
    ps = tf2_geometry_msgs.PointStamped()
    ps.header.stamp = rospy.Time.now()
    ps.header.frame_id = "laser"
    ps.point.x = 2.0
    ps.point.y = 3.0
    ps.point.z = 5.0
    #转换逻辑实现，调用tf封装的算法
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        try:
            #转换实现
            ps_out = buffer.transform(ps, "base_link")
            #输出结果
            rospy.loginfo("coordination after transformation: %.2f, %.2f, %.2f, reference frame %s",
                        ps_out.point.x, ps_out.point.y, ps_out.point.z, ps_out.header.frame_id)
        except Exception as e:
            rospy.logwarn("warning:%s", e)
            pass

        rate.sleep()




