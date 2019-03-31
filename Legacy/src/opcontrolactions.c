/**
 *  @file opcontrolactions.c
 */
#include "main.h"   


void opcontrolDriveTrain() {
    driveTrainSetSpeed(abs(joystickGetAnalog(1, 3))>30 ? joystickGetAnalog(1, 3) : 0,
    abs(joystickGetAnalog(1, 2))>30 ? joystickGetAnalog(1, 2) : 0);
}

/*
//reworked drivetrain
int leftDrivePwr = 0;
int rightDrivePwr = 0;
int gyroReading = 0;
void opcontrolDriveTrain(){
    //update drive power values based on joystick and gyro reading
    if(abs(joystickGetAnalog(1, 3)) > 25) leftDrivePwr = joystickGetAnalog(1, 3);
    else leftDrivePwr = 0;
    if(abs(joystickGetAnalog(1, 2)) > 25) rightDrivePwr = joystickGetAnalog(1, 2);
    else rightDrivePwr = 0;
    gyroReading = gyroGet(gyro);
    
    //check if driver intends to go straight forwards or backwards
    if(leftDrivePwr/rightDrivePwr > 0){

        leftSpeed += gyroReading * 10;
        rightSpeed -= gyroReading * 10;
    }

    //set drivetrain
    driveTrainSetSpeed(leftDrivePwr, rightDrivePwr);
}

*/

int power = 0;
int turn = 0;
void opcontrolArcadeDrive() {
    power = (abs(joystickGetAnalog(1, 3)) > 30 ? joystickGetAnalog(1, 3) : 0);
    turn = (abs(joystickGetAnalog(1, 1)) > 30 ? joystickGetAnalog(1, 1) : 0);
    int left = power + turn;
    int right = power - turn;

    driveTrainSetSpeed(left, right);
}

void opcontrolFlyWheel() {
    if (abs(joystickGetAnalog(2, 3) > 20)) flyWheelSetSpeed(joystickGetAnalog(2, 3));
    else flyWheelSetSpeed(0);
}

int flyWheelConfig;
void opcontrolFlyWheelRampControl() {

    int flyWheelCmd;
    if (joystickGetDigital(1, 7, JOY_LEFT)) flyWheelConfig = 1;
    else if (joystickGetDigital(1, 7, JOY_RIGHT)) flyWheelConfig = 2;
    else if (PANIC_BUTTON) flyWheelConfig = 0;
    else if (joystickGetDigital(1, 7, JOY_DOWN)) flyWheelConfig = 3;
    else if (joystickGetDigital(1, 8, JOY_LEFT)) flyWheelConfig = 4;

    if (flyWheelConfig == 1) {
        flyWheelCmd = 96;
    }
    else if (flyWheelConfig == 2) flyWheelCmd = 127;
    else if (flyWheelConfig == 3) flyWheelCmd = 64;
    else if (flyWheelConfig == 4);
    else flyWheelCmd = 0;

    flyWheelSetSpeed(flyWheelCmd);
}

void opcontrolBallIntake() {
    int speed;
    if (joystickGetDigital(1, 5, JOY_DOWN)) speed = -127;
    else if (joystickGetDigital(1, 5, JOY_UP)) speed = 127;
    else speed = 0;
    ballIntakeSetSpeed(speed);
}

void opcontrolBallIndexer() {
    int speed;
    if (joystickGetDigital(1, 6, JOY_DOWN)) speed = -76;
    else if (joystickGetDigital(1, 6, JOY_UP)) speed = 76;
    else speed = 0;
    ballIndexerSetSpeed(speed);
}


void opcontrolDebug() {
    if (PANIC_BUTTON) {
        encoderReset(leftDriveEncoder);
        encoderReset(rightDriveEncoder);
        gyroReset(gyro);
    }
    if (joystickGetDigital(1, 8, JOY_UP)) {

    }

}

void opcontrolDescorer(){
    int speed;
    if(joystickGetDigital(1, 8, JOY_DOWN)) speed = 127;
    else if(joystickGetDigital(1, 8, JOY_UP)) speed = -127;
    else speed = 0;
    descorerSetSpeed(speed);
}
