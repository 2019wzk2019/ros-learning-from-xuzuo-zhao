#!/usr/bin/env python2
# -*- coding: UTF-8 -*-
import rospy
from plumbing_pub_sub.msg import person

def doperson(p):
    rospy.loginfo("%s, %d, %.2f", p.name, p.age, p.height)

if __name__ == "__main__":
    #初始化ros节点
    rospy.init_node("grandpa")
    #创建订阅者对象
    sub = rospy.Subscriber("nihao", person, doperson, queue_size= 10)
    #处理订阅数据
    #spin
    rospy.spin()
