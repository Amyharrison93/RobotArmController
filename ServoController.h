#pragma once

float AngleToPWM(float angle, float maxAngle);
float CalculateDutyCycle(float pwm, float frequency);
void ServoMove(float dutyCycle, float period, int pin);