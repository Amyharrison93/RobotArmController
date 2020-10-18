//inverse kinematics functions
#include "robot-arm-config.hpp"
#include <math.h>

//calculate the angle for the joint
float calcTrigAngle(float arm1Length, float arm2Length, float arm3Length, float jointDistance)
{
    float arm1LengthSqr = pow(arm1Length,2);
    float arm2LengthSqr = pow(arm2Length,2);
    float arm3LengthSqr = pow(arm3Length,2);
    
    float joint1Angle = acos((arm2LengthSqr + arm3LengthSqr - arm1LengthSqr)/2*arm2Length*arm3Length);
    float joint2Angle = acos((arm3LengthSqr + arm1LengthSqr - arm2LengthSqr)/2*arm3Length*arm1Length);
    float joint3Angle = acos((arm1LengthSqr + arm2LengthSqr - arm3LengthSqr)/2*arm1Length*arm2Length);

}

float calcJointDistance(float distance)
{
    float jointDistance; 

    jointDistance = distance/armSegments-1;

    return jointDistance;
}