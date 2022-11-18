#pragma once

#include <smacc/smacc_orthogonal.h>
#include <move_group_interface_client/cl_movegroup.h>
#include <sm_fetch_six_table_pick_n_sort_1/clients/move_group_interface_client/components/cp_constraint_lateral_workspace.h>
#include <sm_fetch_six_table_pick_n_sort_1/clients/move_group_interface_client/components/cp_constraint_virtual_side_wall.h>
#include <sm_fetch_six_table_pick_n_sort_1/clients/move_group_interface_client/components/cp_constraint_tables_workspaces.h>

#include <move_group_interface_client/components/cp_grasping_objects.h>

namespace sm_fetch_six_table_pick_n_sort_1
{
    using namespace cl_move_group_interface;
    using namespace sm_fetch_six_table_pick_n_sort_1::cl_move_group_interface;


    class OrArm : public smacc::Orthogonal<OrArm>
    {
    public:
        virtual void onInitialize() override
        {
            auto moveGroupClient = this->createClient<ClMoveGroup>("arm_with_torso");
            moveGroupClient->initialize();

            // (Constraint workspace) create obstacles around table surfaces (optionally covering the cubes volume)
            moveGroupClient->createComponent<cl_move_group_interface::CpConstraintTableWorkspaces>();

            // (Constraint workspace) create two simetrics virtual-collision side walls from the robot base reference frame
            {
                std::string referenceFrame = "base_link";
                double lateralDistance = 0.38;

                geometry_msgs::Vector3 size;
                size.x = 1.0;
                size.y = 0.2;
                size.z = 0.6;

                geometry_msgs::Vector3 offset;
                offset.z = 0.3;

                moveGroupClient->createComponent<cl_move_group_interface::CpConstraintLateralWorkspace>(referenceFrame, lateralDistance, size, offset);
            }

            // (Constraint workspace) create one tall virtual-wall-collision at the left side (from the robot base reference frame)
            {
                std::string referenceFrame = "base_link";

                geometry_msgs::Vector3 size;
                size.x = 0.5;
                size.y = 0.1;
                size.z = 1.2;

                geometry_msgs::Vector3 offset;
                offset.x = -0.1;
                offset.y = 0.48;
                offset.z = 0.6;

                moveGroupClient->createComponent<cl_move_group_interface::CpConstraintVirtualSideWall>(referenceFrame, size, offset);
            }

            //-----------------------------------------------
            {
                auto *graspingComponent = moveGroupClient->createComponent<GraspingComponent>();
                graspingComponent->fingerTipNames = {"l_gripper_finger_link", "r_gripper_finger_link"};

                // create 10 graspable cubes located exactly in the tf frames with the same name
                for (int i = 0; i < 10; i++)
                {
                    graspingComponent->createGraspableBox("cube_" + std::to_string(i + 1), 0, 0, 0, 0.06, 0.06, 0.06);
                }
            }
        }
    };
} // namespace sm_fetch_six_table_pick_n_sort_1
