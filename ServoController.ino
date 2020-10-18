#include "ServoController.h"

//convert angles to PWM value between 0 and 1
float AngleToPWM(float angle, float maxAngle)
{
    float 
        pwm;

    pwm = angle/maxAngle;

    return pwm;
}

//calculate duty cycle
float CalculateDutyCycle(float pwm, float frequency)
{
    float 
        dutyCycle,
        period;

    period = 1/frequency;

    dutyCycle = pwm/period;

    return dutyCycle;
}

//write cycle to the Servo 
void ServoMove(float dutyCycle, float period, int pin)
{
    digitalWrite(HIGH, pin);
    delay(period*dutyCycle);
    digitalWrite(LOW, pin);
    delay(period - (period*dutyCycle));
}
