//definitions for calculating the inverse kinemartics of the robot arm
#pragma once

float calcTrigAngle(float angleA);
float calcJointDistance(float distance);
float calcPointDistance(float* goal, float* armBase);
float baseAngle(float* toolPosition, float* armBase);
float jointAngle(float* toolPosition, float* armBase, float distance);