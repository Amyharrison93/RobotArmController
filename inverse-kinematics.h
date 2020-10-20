//definitions for calculating the inverse kinemartics of the robot arm
#pragma once
#include <vector>
using std::vector;

float calcTrigAngle(float angleA);
float calcJointDistance(float distance);
float calcPointDistance(vector<float> goal, vector<float> armBase);
float baseAngle(vector<float> toolPosition, vector<float> armBase);
float jointAngle(vector<float> toolPosition, vector<float> armBase, float distance);