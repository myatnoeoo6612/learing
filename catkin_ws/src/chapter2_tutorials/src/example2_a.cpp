#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "chapter2_tutorials/chapter2_srv1.h"

bool add(chapter2_tutorials::chapter2_srv1::Request &req,
         chapter2_tutorials::chapter2_srv1::Response &res)
{
    res.sum = req.A + req.B + req.C;
    ROS_INFO("request: A = %ld, B = %ld, C = %ld", (int)req.A, (int)req.B, (int)req.C);
    ROS_INFO("Sending back response: [%ld]", (int)res.sum);
}         


int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_3_ints_server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("add_3_ints", add);
    ROS_INFO("ready to add 3 ints");
    ros::spin();

    return 0;
}
