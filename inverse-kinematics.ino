//inverse kinematics functions
#include "robot-arm-config.hpp"
#include <math.h>
#include <vector>

using std::vector;

//calculate the angle for the joints
vector<float> calcTrigAngle(float armeture1Length, float armeture2Length, float jointDistance)
{
    float arm1LengthSqr = pow(armeture1Length,2);
    float arm2LengthSqr = pow(armeture2Length,2);
    float arm3LengthSqr = pow(jointDistance,2);
    //A
    float joint1Angle = acos((arm2LengthSqr + arm3LengthSqr - arm1LengthSqr)/2*armeture2Length*jointDistance);
    //B
    float joint2Angle = acos((arm3LengthSqr + arm1LengthSqr - arm2LengthSqr)/2*jointDistance*armeture1Length);
    //C
    float joint3Angle = acos((arm1LengthSqr + arm2LengthSqr - arm3LengthSqr)/2*armeture1Length*armeture2Length);

    return {joint1Angle, joint2Angle, joint3Angle};
}

//calculated the distance between the joints by dividing the total distance to reach
//note: add a curve to this for better planning
float calcJointDistance(float distance)
{
    float jointDistance = distance/armSegments-1;

    return jointDistance;
}
//calculated the distance from the base to the point from x,y,z
float calcPointDistance(vector<float> toolPosition, vector<float> armBase)
{
    float distanceXY = sqrt(pow(toolPosition[0],2) + pow(toolPosition[1],2));
    float distanceXZ = sqrt(pow(toolPosition[0],2) + pow(toolPosition[2],2));
    float distanceXYZ = (pow(toolPosition[0] - armBase[0],2) + pow(toolPosition[1] - armBase[1],2) + pow(toolPosition[2] - armBase[2],2));

    distanceXYZ = pow(distanceXYZ,1/2);

    return distanceXYZ;
}
float baseAngle(vector<float> toolPosition, vector<float> armBase)
{
    float distance = calcPointDistance(toolPosition, armBase);

    float angle = calcTrigAngle(toolPosition[0], toolPosition[2], distance)[0];

    return angle;
}
float jointAngle(vector<float> toolPosition, vector<float> armBase, float distance)
{
    float angle = calcTrigAngle(toolPosition[0], toolPosition[2], distance)[2];

    return angle;
}