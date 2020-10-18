//servo control
#include "ServoController.h"

float 
  angle,
  maxAngle = 180;

int   
  pin;

void setup() 
{
  // pin definitions
}

void loop() 
{
  //calculate 
  //move joint (wrap in [for each], also smooth)
  MoveJointByAngle(angle, maxAngle, pin);
}