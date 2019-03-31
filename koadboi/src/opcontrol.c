/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include <math.h>

void driveTrain(int speedLeft, int speedRight) {
    smartMotorSet(DRIVE_LEFT, speedLeft);
    smartMotorSet(DRIVE_RIGHT, speedRight);
}

void autoDriveTrain(int targetLeft, int targetRight) {
    int currentLeft = encoderGet(encoderLeft);
    int currentRight = encoderGet(encoderRight);

    int speedLeft = PID(currentLeft, targetLeft, POS_PID_DRIVETRAIN);
    int speedRight = PID(currentRight, targetRight, POS_PID_DRIVETRAIN);

    driveTrain(speedLeft, speedRight);
}

void autoStraightDriveTrain(int targetLeft, int targetRight) {
    int leftCurrent = encoderGet(encoderLeft);
    int rightCurrent = encoderGet(encoderRight);
    int robotHeading = gyroGet(gyro);
   // int encoderDiff = leftCurrent - rightCurrent;

    int leftSpeed = PID(leftCurrent, targetLeft, POS_PID_DRIVETRAIN);
    int rightSpeed = PID(rightCurrent, targetRight, POS_PID_DRIVETRAIN);

    if (leftSpeed < 0) leftSpeed = max(-127, leftSpeed);
    else leftSpeed = min(127, leftSpeed);

    if (rightSpeed < 0) rightSpeed = max(-127, rightSpeed);
    else rightSpeed = min(127, rightSpeed);

    leftSpeed = leftSpeed + (robotHeading * 64);
    rightSpeed = rightSpeed + (robotHeading * 64);
    //leftSpeed = leftSpeed - encoderDiff;
    //rightSpeed = rightSpeed + encoderDiff;

    driveTrain(leftSpeed, rightSpeed);
}

void autoSmartDriveTrain(int targetLeft, int targetRight) {
    gyroReset(gyro);
    encoderReset(encoderLeft);
    encoderReset(encoderRight);
    
    int threshold = 180;
    int diffLeft = targetLeft - encoderGet(encoderLeft);
    int diffRight = targetRight - encoderGet(encoderRight);
    while (abs(diffLeft) > threshold && abs(diffRight) > threshold) {
        autoStraightDriveTrain(targetLeft, targetRight);
        diffLeft = targetLeft - encoderGet(encoderLeft);
        diffRight = targetRight - encoderGet(encoderRight);
        printf("gyro %d: left %d: right %d: left %d: right %d\n:", gyroGet(gyro), smartMotorGet(DRIVE_LEFT), smartMotorGet(DRIVE_RIGHT));
        delay(20);
    }
    driveTrain(0, 0);
}

void autoTurnDriveTrain(int degree) {
    gyroReset(gyro);
    int curr = gyroGet(gyro);
    int diff = degree - curr;
    
    int speedLeft = PID(curr, degree, 6030, 1.5, 0.0, 0.0);
    int speedRight = -PID(curr, degree, 6030, 1.5, 0.0, 0.0);

    while (diff > 3) {
        driveTrain(speedLeft, speedRight);
        curr = gyroGet(gyro);
        speedLeft = PID(curr, degree, 6030, 0.5, 0.0, 0.0);
        speedRight = -PID(curr, degree, 6030, 0.5, 0.0, 0.0);
        diff = degree - abs(curr);
        printf("boop b00p %d\n", diff);
        delay(20);
    }
}

void operatorControl() {
	while (1) {
        driveTrain(abs(joystickGetAnalog(1, 3))>20 ? joystickGetAnalog(1, 3) : 0,
            abs(joystickGetAnalog(1, 2))>20 ? joystickGetAnalog(1, 2) : 0);

        if (joystickGetDigital(1, 7, JOY_UP)) {
            encoderReset(encoderLeft);
            encoderReset(encoderRight);
        }

        printf("gyro: %d\n", gyroGet(gyro));
	delay(20);
	}

}