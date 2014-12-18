#ifndef _CART_WALK_H
#define _CART_WALK_H

#include "CartWalk/PolySpline.hpp"
#include "CartWalk/SigmabanLeg.h"

namespace Rhoban
{
    class CartWalk
    {
        public:
            CartWalk();
            void setLength(double L1, double L2);

            // Current time
            double t;

            // Splines
            PolySpline rise;
            PolySpline step;
            PolySpline swing;

            // Time gain (frequency)
            double timeGain;

            // Position offset
            double xOffset;
            double yOffset;
            double zOffset;
            double yLat;
            double hipOffset;

            // Rising of the steps
            double riseGain;

            // Swinging
            double swingGain;
            double swingHeight;
            double swingPhase;

            // Arms
            double armsGain;

            // Stepping
            double stepGain;

            // Lateral stepping
            double lateralStepGain;

            double sLX, sLY, sLZ, sRX, sRY, sRZ;
            double swingForce;
            double smoothing;
            double riseRatio;
            double riseStepPhase;

            // Turning
            double turn;

            // Walk enabling
            bool isEnabled;
            double enabledRatio;

            // Speeds to flush
            float l_rotationSpeed, l_speed, l_lateralSpeed;
            float r_rotationSpeed, r_speed, r_lateralSpeed;
            float l_stepGain, r_stepGain;

            virtual void tick(double elapsed);

            float a_l_hip_pitch, a_l_knee, a_l_foot_pitch, a_l_arm, a_l_hip_roll, a_l_hip_yaw, a_l_foot_roll;
            float a_r_hip_pitch, a_r_knee, a_r_foot_pitch, a_r_arm, a_r_hip_roll, a_r_hip_yaw, a_r_foot_roll;

        protected:
            SigmabanLeg legModel;
    };
}

#endif // _CART_WALK_H

