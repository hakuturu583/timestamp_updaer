#ifndef TIMESTAMP_UPDATER_TIMESTAMP_UPDATER_H_INCLUDED
#define TIMESTAMP_UPDATER_TIMESTAMP_UPDATER_H_INCLUDED

// Headers in ROS
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/PointCloud2.h>

class TimeStampUpdater
{
public:
    TimeStampUpdater(ros::NodeHandle nh,ros::NodeHandle pnh);
    ~TimeStampUpdater();
private:
    void odomCallback(nav_msgs::Odometry msg);
    void pointCloudCallback(sensor_msgs::PointCloud2 msg);
    std::string topic_type_;
    ros::NodeHandle nh_;
    ros::NodeHandle pnh_;
    ros::Subscriber sub_;
    ros::Publisher pub_;
    std::string input_topic_;
    std::string output_topic_;
};

#endif  //TIMESTAMP_UPDATER_TIMESTAMP_UPDATER_H_INCLUDED