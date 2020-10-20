//servo control
#include "servo-controller.h"
#include "robot-arm-config.hpp"
#include "inverse-kinematics.h"
#include <vector>
using std::vector;

float 
  angle = 90,
  distanceXYZ,
  jointDistance;
vector<float>
  toolPose = {0,0,0,0,0,0},
  armZJoints(armSegments,0),
  armXJoints(armSegments,0);
int
  jointMove = 0;

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
    angle = jointAngle(toolPose, worldCoordinatePose, jointDistance);
    MoveJointByAngle(angle, maxAngle, baseAxisZ);
  }
  
}