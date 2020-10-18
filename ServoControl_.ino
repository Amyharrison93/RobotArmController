//servo control
#include "ServoController.h"

float 
  dutyCycle,
  angle,
  pwm,
  frequency,
  maxAngle = 180;

int   
  pin;

void setup() 
{
  // put your setup code here, to run once:S
}

void loop() 
{
  MoveJointByAngle(angle, maxAngle, pin);
}