//add configuration elements to this file for easy editing.
#ifndef ROBOT_ARM_CONFIG_H
#define ROBOT_ARM_CONFIG_H
#include <vector>
using std::vector;

//robot arm world position, change reletive to what you want to be moving to
const vector<float> worldCoordinatePose = {0,0,0,0,0,0};

//frequency of pins uno: 490, 980
const int frequencyHigh = 980;
const int frequencyLow = 490;

//servo constraints
const float maxAngle = 180;

//number of segments to arm and lengths in mm
const int armSegments = 3;
const int arm1Length = 300;
const int arm2Length = 300;
const int arm3Length = 300;

//joint definitions uno:3, 5, 6, 9, 10, 11
const int baseAxisZ = 3;
const int arm1AxisX = 5;
const int arm1AxisZ = 6;
const int arm2AxisX = 9;
const int arm2AxisZ = 10;
const int toolAxisX = 11;

//actuvate/deactivate using PID settings
const bool proportionalController = true;
const bool integralController = true;
const bool dirivetiveController = true;

//sensor definitions
const bool IMU = false;

//PID controller definitions, change usually between 0 and 1
const float kp = 0;
const float ki = 0;
const float kd = 0;

#endif