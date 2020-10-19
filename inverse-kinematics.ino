//inverse kinematics functions
#include "robot-arm-config.hpp"
#include <math.h>
#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

//calculate the angle for the joint
vector<float> calcTrigAngle1(float arm1Length, float arm2Length, float arm3Length, float jointDistance)
{
    float arm1LengthSqr = pow(arm1Length,2);
    float arm2LengthSqr = pow(arm2Length,2);
    float arm3LengthSqr = pow(arm3Length,2);
    
    float joint1Angle = acos((arm2LengthSqr + arm3LengthSqr - arm1LengthSqr)/2*arm2Length*arm3Length);
    float joint2Angle = acos((arm3LengthSqr + arm1LengthSqr - arm2LengthSqr)/2*arm3Length*arm1Length);
    float joint3Angle = acos((arm1LengthSqr + arm2LengthSqr - arm3LengthSqr)/2*arm1Length*arm2Length);

    return {joint1Angle, joint2Angle, joint3Angle};
}

float calcJointDistance(float distance)
{
    float jointDistance = distance/armSegments-1;

    return jointDistance;
}
//calculated the distance from the base to the point from x,y,z
//float calcPointDistance()