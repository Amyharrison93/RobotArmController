#pragma once

float AngleToPWM(float angle, float maxAngle);
float CalculateDutyCycle(float pwm, float frequency);
void MoveJointByAngle(float angle, float maxAngle, int pin);

float proportional(float kp,float goal, float measurement);
float integral(float ki, float goal, float measurement);
float dirivetive(float kd, float goal, float measurement);
float PID(float goal, float measurement);