/*****************************************************************************************************************
 * ReelRobotix Inc. - Software License Agreement      Copyright (c) 2018
 * 	 Authors: Pablo Inigo Blasco, Brett Aldrich
 *
 ******************************************************************************************************************/
#pragma once

#include <functional>
#include <array>
#include <ros/ros.h>

#include <move_base_z_client_plugin/move_base_z_client_plugin.h>
#include <smacc/component.h>

#include <dynamic_reconfigure/DoubleParameter.h>
#include <dynamic_reconfigure/Reconfigure.h>
#include <dynamic_reconfigure/Config.h>


namespace cl_move_base_z
{
class CostmapProxy;

class CostmapSwitch : public smacc::ISmaccComponent
{
public:
    enum class StandardLayers
    {
        GLOBAL_OBSTACLES_LAYER = 0,
        LOCAL_OBSTACLES_LAYER = 1,
        GLOBAL_INFLATED_LAYER = 2,
        LOCAL_INFLATED_LAYER = 3
    };

    static std::array<std::string, 4> layerNames;

    CostmapSwitch();

    virtual void onInitialize() override;

    static std::string getStandardCostmapName(StandardLayers layertype);

    bool exists(std::string layerName);

    void enable(std::string layerName);

    void enable(StandardLayers layerType);

    void disable(std::string layerName);

    void disable(StandardLayers layerType);

    void registerProxyFromDynamicReconfigureServer(std::string costmapName, std::string enablePropertyName = "enabled");

private:
    std::map<std::string, std::shared_ptr<CostmapProxy>> costmapProxies;
    cl_move_base_z::ClMoveBaseZ *moveBaseClient_;
};
//-------------------------------------------------------------------------
class CostmapProxy
{
public:
    CostmapProxy(std::string costmap_name, std::string enablePropertyName);

    void setCostmapEnabled(bool value);

private:
    std::string costmapName_;
    dynamic_reconfigure::Config enableReq;
    dynamic_reconfigure::Config disableReq;

    void dynreconfCallback(const dynamic_reconfigure::Config::ConstPtr &configuration_update);

    ros::Subscriber dynrecofSub_;
};
}
