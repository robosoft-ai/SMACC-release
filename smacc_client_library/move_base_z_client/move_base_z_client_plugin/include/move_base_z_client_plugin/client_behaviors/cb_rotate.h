/*****************************************************************************************************************
 * ReelRobotix Inc. - Software License Agreement      Copyright (c) 2018
 * 	 Authors: Pablo Inigo Blasco, Brett Aldrich
 *
 ******************************************************************************************************************/
#pragma once

#include "cb_move_base_client_behavior_base.h"
#include <tf/transform_listener.h>

namespace cl_move_base_z
{
class CbRotate : public CbMoveBaseClientBehaviorBase
{
public:
    tf::TransformListener listener;

    boost::optional<float> rotateDegree;

    CbRotate();

    CbRotate(float rotate_degree);

    virtual void onEntry() override;
};
} // namespace cl_move_base_z
