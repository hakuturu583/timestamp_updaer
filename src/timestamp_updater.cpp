// Headers in this package
#include <timestamp_updater/timestamp_updater.h>

TimeStampUpdater::TimeStampUpdater(ros::NodeHandle nh,ros::NodeHandle pnh)
{
    nh_ = nh;
    pnh_ = pnh;
    pnh_.param<std::string>("topic_type", topic_type_, "");
    pnh_.param<std::string>("input_topic", input_topic_, "");
    pnh_.param<std::string>("output_topic", output_topic_, "");
    if(topic_type_ == "nav_msgs/Odometry")
    {
        pub_ = nh_.advertise<nav_msgs::Odometry>(output_topic_,1);
        sub_ = nh_.subscribe(input_topic_,1,&TimeStampUpdater::odomCallback,this);
    }
    else if(topic_type_ == "sensor_msgs/PointCloud2")
    {
        pub_ = nh_.advertise<sensor_msgs::PointCloud2>(input_topic_,1);
        sub_ = nh_.subscribe(input_topic_,1,&TimeStampUpdater::pointCloudCallback,this);
    }
}

TimeStampUpdater::~TimeStampUpdater()
{

}

void TimeStampUpdater::odomCallback(nav_msgs::Odometry msg)
{
    msg.header.stamp = ros::Time::now();
    pub_.publish(msg);
}

void TimeStampUpdater::pointCloudCallback(sensor_msgs::PointCloud2 msg)
{
    msg.header.stamp = ros::Time::now();
    pub_.publish(msg);
}