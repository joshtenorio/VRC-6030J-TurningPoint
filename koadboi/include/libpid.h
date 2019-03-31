#pragma once

#define POS_PID_DRIVETRAIN 0, 0.5, 0.0, 0.0
#define V_PID_DRIVETRAIN 1, 3, 0.0, 0.0
#define PID_FLYWHEEL 2, 0.1, 0.05, 0.0

int PID(float current, float target, int mechanismIdentifier, float kP, float kI, float kD);
