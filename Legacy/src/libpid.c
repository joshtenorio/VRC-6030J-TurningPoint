/**
 *  @file libpid.c
 */
#include "main.h"

static float positionErrorIntegral[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float errorPrevious = 0;
int positionPID(float current, float target, int subsystemIdentifier, float kP, float kI, float kD) {
    float errorCurrent = target - current;
    positionErrorIntegral[subsystemIdentifier] += errorCurrent;
    float derivative = errorCurrent - errorPrevious;
    errorPrevious = errorCurrent;

    float pTerm = kP * errorCurrent;
    float iTerm = kI * positionErrorIntegral[subsystemIdentifier];
    float dTerm = kD * derivative;
    int motorSpeed = pTerm + iTerm + dTerm;
    
    return motorSpeed;
}

int velocityPID(float current, float target, int subsystemIdentifier, float kP, float kI, float kD){
    int changeOfMotorSpeed = min(127, max(-127, positionPID(current, target, subsystemIdentifier, kP, kI, kD)));
    int currentMotorSpeed = 0;
    if (subsystemIdentifier == 0) currentMotorSpeed = driveTrainGetLeftMotor();
    else if (subsystemIdentifier == 1) currentMotorSpeed = driveTrainGetRightMotor();
    else if (subsystemIdentifier == 4) currentMotorSpeed = flyWheelGetMotor();
    
    int motorSpeed = currentMotorSpeed + changeOfMotorSpeed;
    //printf("current %d change %d", currentMotorSpeed, changeOfMotorSpeed);
    return motorSpeed; 
}



