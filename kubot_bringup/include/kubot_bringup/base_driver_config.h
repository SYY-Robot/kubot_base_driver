#ifndef  KUBOT_BASE_DRIVER_CONFIG_
#define KUBOT_BASE_DRIVER_CONFIG_

#include <ros/ros.h>

#define USE_DYNAMIC_RECONFIG

#ifdef USE_DYNAMIC_RECONFIG
#include <dynamic_reconfigure/server.h>
#include "kubot_bringup/kubot_driverConfig.h"
#endif

class Robot_parameter;

class BaseDriverConfig
{
      public:
            BaseDriverConfig(ros::NodeHandle &p);
                  ~BaseDriverConfig();

            void init(Robot_parameter* r);
            void SetRobotParameters();

#ifdef USE_DYNAMIC_RECONFIG
            void dynamic_callback(kubot_bringup::kubot_driverConfig &config, uint32_t level);
            bool get_param_update_flag();

      private:
            dynamic_reconfigure::Server<kubot_bringup::kubot_driverConfig > server;
            dynamic_reconfigure::Server<kubot_bringup::kubot_driverConfig >::CallbackType f;
#endif

      public:
            Robot_parameter* rp;
  
            std::string port;
            int32_t baudrate;
            std::string robot_ip;
            
            std::string base_frame;
            std::string odom_frame;

            bool publish_tf;
        //double ticks_per_meter;.

            std::string cmd_vel_topic;
            std::string odom_topic;
 //TODO           std::string led_status_topic;
           std::string robot_status_topic;
 
            int32_t freq;

            bool out_pid_debug_enable;
 //TODO           bool led_status_control_enable;

      private:
#ifdef USE_DYNAMIC_RECONFIG
            bool param_update_flag;
#endif
            ros::NodeHandle& pn;
            ros::ServiceClient client;

            bool set_flag;
};

#endif

// KUBOT_BASE_DRIVER_CONFIG_H_