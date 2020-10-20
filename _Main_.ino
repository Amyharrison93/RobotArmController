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
  for(jointMove = 0; jointMove <= armSegments; jointMove++)
  {
    armXJoints[1] = jointAngle(toolPose, worldCoordinatePose, jointDistance);
    MoveJointByAngle(angle, maxAngle, baseAxisZ);
  }
  
}