#!/usr/bin/env python2
# -*- coding: UTF-8 -*-
import rospy
from plumbing_pub_sub.msg import person

if __name__ == "__main__":
    #初始化ros节点
    rospy.init_node("dama")
    #创建发布者对象
    pub = rospy.Publisher("nihao", person, queue_size = 10)
    #组织发布逻辑并发布数据
    #创建person数据
    p = person()
    p.name = "kerry"
    p.age = 15
    p.height = 1.75
    #创建rate对象
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        pub.publish(p)
        rospy.loginfo("published name%s, age %d, height %.2f", p.name, p.age, p.height)
        rate.sleep()
