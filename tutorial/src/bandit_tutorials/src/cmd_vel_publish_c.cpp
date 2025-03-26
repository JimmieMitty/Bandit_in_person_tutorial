#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

ros::Publisher movebase;
ros::Rate* rate;

void publishVelocityLoop() {
    while (ros::ok()) {
        geometry_msgs::Twist current_twist;
        current_twist.linear.x = 0; // move forward and back
        current_twist.linear.y = 0; // move left to right
        current_twist.angular.z = 1.0;
        movebase.publish(current_twist);
        rate->sleep();
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "movecontroller");
    ros::NodeHandle nh;
    
    movebase = nh.advertise<geometry_msgs::Twist>("/mobile_base_controller/cmd_vel", 1);
    rate = new ros::Rate(10); // 10Hz
    
    publishVelocityLoop();
    
    delete rate;
    return 0;
}
