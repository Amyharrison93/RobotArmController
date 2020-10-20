//controller for servo motors
#pragma once

float AngleToPWM(float angle, float maxAngle);
float CalculateDutyCycle(float pwm, float frequency);
void MoveJointByAngle(float angle, float maxAngle, int pin);

float proportional(float goal, float measurement);
float integral(float goal, float measurement);
float dirivetive(float goal, float measurement);
float PID(float goal, float measurement);