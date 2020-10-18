#include "ServoController.h"
#include "RobotArmConfig.h"

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
        frequency = frequencyHigh;
    
    else
        frequency = frequencyLow;
  
    dutyCycle = CalculateDutyCycle(pwm, frequency);

    analogWrite(pin, dutyCycle);
}

//smoothing proportional
float proportional(float goal, float measurement)
{
    float prop;

    prop = (goal - measurement) * kp; 

    return prop;
}
//smoothing integral
float integral(float goal, float measurement)
{
    float
        arryMeasured[50],
        integ;
    int 
        arraySum,
        stepPosition;

    //record current measurment
    arryMeasured[stepPosition] = measurement;

    //sum array
    if(arraySum < sizeof(arryMeasured))
    {
        integ = arryMeasured[arraySum];
        arraySum++;
    }
    //scale
    integ = ki * integ;

    if(arraySum >= sizeof(arryMeasured))
    {
        arraySum = 0;
    }

    return integ;
}
float dirivetive(float goal, float measurement)
{
    float 
        error,
        errorLast = 0,
        dir;

    error = goal - measurement;

    dir = kd * (error - errorLast);

    errorLast = error;

    return dir;
}
//sum PID controller components 
float PID(float goal, float measurement)
{
    float
        p,
        i,
        d, 
        pid;
        
    if(proportionalController)
    {
        p = proportional(goal, measurement);
    }
    else
    {
        p = 0;
    }
        
    if(integralController)
    {
        i = integral(goal, measurement);
    }
    else
    {
        i = 0;
    }
    if(dirivetiveController)
    {
        d = dirivetive(goal, measurement);
    }
    else
    {
        d = 0;
    }

    pid = p + i + d;

    return pid;
}
