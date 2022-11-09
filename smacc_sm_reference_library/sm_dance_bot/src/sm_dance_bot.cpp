#include <sm_dance_bot/sm_dance_bot.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "dance_bot");
    ros::NodeHandle nh;

    ros::Duration(5).sleep();
    smacc::run<SmDanceBot>();
}
