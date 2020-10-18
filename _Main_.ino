//servo control
#include "ServoController.h"
#include "RobotArmConfig.h"

float 
  angle = 90;

void setup() 
{
  // pin definitions
}

void loop() 
{
  //calculate 
  //move joint (wrap in [for each], also smooth)

  MoveJointByAngle(angle, maxAngle, baseAxisZ);
}