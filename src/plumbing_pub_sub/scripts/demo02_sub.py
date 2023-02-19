#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#导包
import rospy
from std_msgs.msg import String

def doMsg(msg):
    rospy.loginfo("i hear %s", msg.data)

if __name__ == "__main__":
    #初始化ros节点
    rospy.init_node("listener")
    #实例化 订阅者对象
    sub = rospy.Subscriber("chatter", String, doMsg, queue_size = 10)
    #处理订阅的消息 回调函数
    #设置循环调用回调函数
    rospy.spin()
