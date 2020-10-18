#include "ServoController.h"

//convert angles to PWM value between 0 and 1
float AngleToPWM(float angle, float maxAngle)
{
    float 
        pwm;

    maxAngle = maxAngle;
    angle = angle;

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

//move a joint
void MoveJointByAngle(float angle, float maxAngle, int pin)
{
    int 
        frequency;
    float 
        pwm,
        dutyCycle;
        
    pwm = AngleToPWM(angle, maxAngle);

    if (pin == 5 || pin == 6)
        frequency = 980;
    
    else
        frequency = 490;
  
    dutyCycle = CalculateDutyCycle(pwm, frequency);

    analogWrite(pin, dutyCycle);
}
