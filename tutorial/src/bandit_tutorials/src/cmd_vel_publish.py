#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist

class BanditTutorial:
    def __init__(self): 
        self.movebase = rospy.Publisher('/mobile_base_controller/cmd_vel', Twist, queue_size=1)
    
    # publishes velocity commands based on Twist
    def publish_velocity_loop(self):
        while not rospy.is_shutdown:
            self.current_twist.linear.x = 0
            self.current_twist.linear.y = 0
            self.current_twist.linear.z = -0.3
            self.movebase.publish(self.current_twist)

if __name__ == "__main__":
    try:
        rospy.init_node('movecontroller')
        client = BanditTutorial()
        client.publish_velocity_loop()
        
    except rospy.ROSInterruptException:
        pass