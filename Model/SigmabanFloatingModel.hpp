#ifndef LEPH_SIGMABANFLOATINGMODEL_HPP
#define LEPH_SIGMABANFLOATINGMODEL_HPP

#include "Model/SigmabanModel.hpp"

namespace Leph {

/**
 * SigmabanFloatingModel
 *
 * Specialization of Model for Sigmaban robot.
 * Handle feet geometry and ground 
 * position transformation using 6 DOF on
 * Sigmaban trunk
 */
class SigmabanFloatingModel : public SigmabanModel
{
    public:

        /**
         * Enum for support foot
         */
        enum SupportFoot {
            LeftSupportFoot,
            RightSupportFoot,
        };

        /**
         * Initialization with sigmaban URDF model
         */
        SigmabanFloatingModel();

        /**
         * Return the current support foot
         */
        SupportFoot getSupportFoot() const;
        
        /**
         * Return the frame name of
         * current support foot and 
         * moving foot
         */
        std::string supportFootName() const;
        std::string movingFootName() const;

        /**
         * Update the floating joint 6 degrees of freedom
         * to constraint the support foot to lay flat
         * on the ground
         */
        void putOnGround();

    private:

        /**
         * Current support foot
         */
        SupportFoot _supportFoot;

        /**
         * State (translation and yaw)
         * of current supporting foot
         * which must remain fixed
         */
        double _statePosX;
        double _statePosY;
        double _stateRotYaw;

        /**
         * Set current support foot
         * and update foot state (target fixed
         * position on ground) on support foot 
         * transition
         */
        void findSupportFoot();

        /**
         * Update roll, pitch and yaw floating
         * base degree of freedom to put the
         * support foot parralel to ground
         */
        void putSupportFootFlat();

        /**
         * Update floating base translation
         * to put support foot at world
         * origin
         */
        void putSupportFootOrigin();
};

}

#endif
