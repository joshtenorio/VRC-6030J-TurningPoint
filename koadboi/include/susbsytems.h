#pragma once

#define DRIVE_LEFT 2
#define DRIVE_RIGHT 9
#define GYRO_PORT 2
#define ACCELEROMETER_X 3
#define ACCELEROMETER_Y 4
#define ENCODER_LEFT_TOP 2
#define ENCODER_LEFT_BOT 3
#define ENCODER_RIGHT_TOP 4
#define ENCODER_RIGHT_BOT 5

Gyro gyro;
Encoder encoderLeft;
Encoder encoderRight;

void driveTrain(int speedLeft, int speedRight);
void autoDriveTrain(int targetLeft, int targetRight);
void autoStraightDriveTrain(int targetLeft, int targetRight);
void autoSmartDriveTrain(int targetLeft, int targetRight);
void autoTurnDriveTrain(int degree);