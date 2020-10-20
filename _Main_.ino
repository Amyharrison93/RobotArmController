//servo control
#include "servo-controller.h"
#include "robot-arm-config.hpp"
#include "inverse-kinematics.h"


float angle = 90;
float distanceXYZ = 0;
float jointDistance = 0;
float toolPose[5] = {0};
float armZJoints[armSegments] = {0};
float armXJoints[armSegments] = {0};
float offsetAngles[3] = {0};

int jointMove = 0;

void setup() 
{
  // pin definitions
}


void loop() 
{
  //read serial for new tool position

  //calculate distance to target
  distanceXYZ = calcPointDistance(toolPose, worldCoordinatePose);
  //calculate joint angle for the base
  armXJoints[0]  = baseAngle(toolPose, worldCoordinatePose);
  //joint disyance 
  jointDistance = calcJointDistance(distanceXYZ);
  //for each joint
  
  //calculate elbow joint angle
  armXJoints[1] = jointAngle(toolPose, worldCoordinatePose, jointDistance);
  //calculate base offset angle
  calcTrigAngle(arm1Length, arm2Length, distanceXYZ, offsetAngles);
  //apply offset
  armXJoints[0] += offsetAngles[0];

  for(jointMove = 0; jointMove <= sizeof(armXJoints); jointMove++)
  {
    //move joints to position
    MoveJointByAngle(armXJoints[jointMove], maxAngle, baseAxisZ);
  }
  
}