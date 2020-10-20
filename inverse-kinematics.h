//definitions for calculating the inverse kinemartics of the robot arm
#pragma once

void calcTrigAngle(float armeture1Length, float armeture2Length, float jointDistance, float output[3]);
float calcJointDistance(float distance);
float calcPointDistance(float* toolPosition, float* armBase);
float baseAngle(float toolPosition[], float armBase[]);
float jointAngle(float toolPosition[], float armBase[], float distance);