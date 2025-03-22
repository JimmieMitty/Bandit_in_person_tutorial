#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

class BanditTutorial {
public:
    BanditTutorial() {
        movebase = nh.advertise<geometry_msgs::Twist>("/mobile_base_controller/cmd_vel", 1);
    }

    void publishVelocityLoop() {
        ros::Rate rate(10); // Adjust loop rate as necessary
        while (ros::ok()) {
            geometry_msgs::Twist current_twist;
            current_twist.linear.x = 0;
            current_twist.linear.y = 0;
            current_twist.linear.z = 0;
            movebase.publish(current_twist);
            rate.sleep();
        }
    }

private:
    ros::NodeHandle nh;
    ros::Publisher movebase;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "movecontroller");
    
    BanditTutorial client;
    client.publishVelocityLoop();
    
    return 0;
}
