// Headers in ROS
#include <ros/ros.h>

// Headers in this package
#include <timestamp_updater/timestamp_updater.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "timestamp_updater_node");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");
    ros::spin();
    return 0;
}