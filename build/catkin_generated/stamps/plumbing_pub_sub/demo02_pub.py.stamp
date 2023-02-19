#! /usr/bin/env python
# -*- coding: UTF-8 -*-
#导报
import rospy
from std_msgs.msg import String

if __name__ == "__main__":

    rospy.init_node("wang")

    pub = rospy.Publisher("chatter", String, queue_size = 10)

    msg = String()
    #制定发布频率
    rate = rospy.Rate(1)
    count = 0
    while not rospy.is_shutdown():
        count += 1
        msg.data = "hello" + str(count)
        pub.publish(msg)
        rospy.loginfo("发布的数据是%s",msg.data)
        rate.sleep()