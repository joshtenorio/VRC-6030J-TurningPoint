/**
*  @file subsystems.c
*/
#include "main.h"

void flyWheelSetSpeed(int speed) {

    smartMotorSet(TOP_FLYW_PORT, speed);
    //smartMotorSet(BOT_FLYW_PORT, speed);
}

void descorerSetSpeed(int speed){
    smartMotorSet(DESCORER_PORT, speed);
}

void driveTrainSetSpeed(int leftSpeed, int rightSpeed) {
    smartMotorSet(LF_DRIVE_PORT, leftSpeed);
    smartMotorSet(LB_DRIVE_PORT, leftSpeed);
    smartMotorSet(RF_DRIVE_PORT, rightSpeed);
    smartMotorSet(RB_DRIVE_PORT, rightSpeed);
}

void ballIntakeSetSpeed(int speed) {
    smartMotorSet(BALL_INTAKE_PORT, speed);
}

void ballIndexerSetSpeed(int speed) {
    smartMotorSet(BALL_INDEXER_PORT, speed);
}

int flyWheelGetMotor() {
    return smartMotorGet(TOP_FLYW_PORT);
}

int driveTrainGetLeftMotor() {
    return smartMotorGet(LF_DRIVE_PORT);
}

int driveTrainGetRightMotor() {
    return smartMotorGet(RF_DRIVE_PORT);
}

int ballIntakeGetMotor() {
    return smartMotorGet(BALL_INTAKE_PORT);
}

int fvelocity = 0;
int flyWheelGetVelocity() {
    fvelocity = -encoderGet(flyWheelEncoder) * 15;
    //int rpm = (fvelocity * 1000 * 60) / (20 * 360);
    encoderReset(flyWheelEncoder);
    return fvelocity;
}