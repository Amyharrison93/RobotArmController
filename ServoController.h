#pragma once

float AngleToPWM(float angle, float maxAngle);
float CalculateDutyCycle(float pwm, float frequency);
void MoveJointByAngle(float angle, float maxAngle, int pin);