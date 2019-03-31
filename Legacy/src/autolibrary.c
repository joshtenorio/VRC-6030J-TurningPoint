/**
 *  @file autolibrary.c
 */
#include "main.h"

void autoDriveTrain(int leftTarget, int rightTarget, int limit) {
    //create "current" variables for PIDs
    int leftCurrent = encoderGet(leftDriveEncoder);
    int rightCurrent = encoderGet(rightDriveEncoder);
    
    //int set initial speed for drivetrain subsystem using a PID controller
    int leftSpeed = positionPID(leftCurrent, leftTarget, POS_PID_DRIVETRAIN_L);
    int rightSpeed = positionPID(rightCurrent, rightTarget, POS_PID_DRIVETRAIN_R);

    //limit drivetrain speed to fit within limit set by parameter
    leftSpeed = min(limit, max(-limit, leftSpeed));
    rightSpeed = min(limit, max(-limit, rightSpeed));
    
    //set drivetrain motors speeds
    driveTrainSetSpeed(leftSpeed, rightSpeed);
}

void autoStraightDriveTrain(int target, int limit) {
    //create "current" variables for PIDs
    int leftCurrent = encoderGet(leftDriveEncoder);
    int rightCurrent = encoderGet(rightDriveEncoder);
    int robotHeading = gyroGet(gyro);

    //set initial speed for drivetrain subsystem using a PID controller
    int leftSpeed = positionPID(leftCurrent, target, POS_PID_DRIVETRAIN_L);
    int rightSpeed = positionPID(rightCurrent, target, POS_PID_DRIVETRAIN_R);

    //limit drivetrain speed to fit within limit set by parameter
    leftSpeed = min(limit, max(-limit, leftSpeed));
    rightSpeed = min(limit, max(-limit, rightSpeed));

    //adjust drivetrain speed based off of robot drift
    if (target > 0) {
        leftSpeed += robotHeading * 10;
        rightSpeed -= robotHeading * 10;
    }
    else if (target < 0) {
        leftSpeed += robotHeading * 3;
        rightSpeed -= robotHeading * 3;
    }

    //set drivetrain motors speeds
    driveTrainSetSpeed(leftSpeed, rightSpeed);
}

void autoTurnDriveTrain(int degree, long sentinel) {
    //reset gyro, initialize PID variables and exit condition
    gyroReset(gyro);
    int curr = gyroGet(gyro);
    int diff = abs(degree) - abs(curr);

    //initialize timer for checking timeout condition
    const long startTime = millis();
    delay(5);
    long timer = millis() - startTime;

    //initialize drivetrain motor speeds
    int speedLeft = positionPID(curr, degree, PID_GYRO);
    int speedRight = -positionPID(curr, degree, PID_GYRO);

    while (abs(diff) > 6) {
        //set drivetrain motor speeds
        driveTrainSetSpeed(speedLeft, speedRight);

        //update PID variables and algorithm exit condition
        curr = gyroGet(gyro);
        speedLeft = positionPID(curr, degree, PID_GYRO);
        speedRight = -positionPID(curr, degree, PID_GYRO);
        diff = abs(degree) - abs(curr);

        //if algorithm timeout, terminate loop
        timer = millis() - startTime;
        if (timer > sentinel) break;

        delay(20);
    }
    //turn drivetrain motors off
    driveTrainSetSpeed(0, 0);
}

void autoRightDriveTrain(int target, int limit, long sentinel) {
    //reset encoder, initialize PID variables and exit condition
    encoderReset(rightDriveEncoder);
    const int threshold = 180;
    int diff = target - encoderGet(rightDriveEncoder);

    //initialize algorithm timeout condition
    const long timeStart = millis();
    long timer = millis() - timeStart;
    
    while (abs(diff) > threshold) {
        //run right drivetrain motors
        autoDriveTrain(0, target, limit);

        //update update exit condition variable
        diff = target - encoderGet(rightDriveEncoder);

        //if algorithm timeout, terminate loop
        timer = millis() - timeStart;
        if (timer > sentinel) break;

        delay(20);
    }
    //turn drvetrain motors off
    driveTrainSetSpeed(0, 0);
}

void autoLeftDriveTrain(int target, int limit, long sentinel) {
    //reset encoder, initialize PID variables and exit condition
    encoderReset(leftDriveEncoder);
    const int threshold = 180;
    int diff = target - encoderGet(leftDriveEncoder);

    //initialize algorithm timeout condition
    const long timeStart = millis();
    long timer = millis() - timeStart;

    while (abs(diff) > threshold) {
        //run left drivetrain motors
        autoDriveTrain(target, 0, limit);

        //update update exit condition variable
        diff = target - encoderGet(leftDriveEncoder);

        //if algorithm timeout, terminate loop
        timer = millis() - timeStart;
        if (timer > sentinel) break;

        delay(20);
    }
    //turn drvetrain motors off
    driveTrainSetSpeed(0, 0);
}

void autoSmartDriveTrain(int target, int limit, long sentinel) {
    //reset encoders and gyro, then initialize exit condition
    encoderReset(leftDriveEncoder);
    encoderReset(rightDriveEncoder);
    gyroReset(gyro);
    const int threshold = 180;
    int leftDiff = target - encoderGet(leftDriveEncoder);
    int rightDiff = target - encoderGet(rightDriveEncoder);

    //initialize timeout condition
    const long timeStart = millis();
    long timer = millis() - timeStart;

    while (abs(leftDiff) > threshold && abs(rightDiff) > threshold) {
        //set drivetrain motors speeds
        autoDriveTrain(target, target, limit);

        //update exit condition variables
        leftDiff = target - encoderGet(leftDriveEncoder);
        rightDiff = target - encoderGet(rightDriveEncoder);

        //check if algorithm reached timeout condition, if so then exit loop
        timer = millis() - timeStart;
        if (timer > sentinel) break;

        delay(20);
    }
    //turn drivetrain motors off
    driveTrainSetSpeed(0, 0);
}

void autoVelocityFlyWheelControl(int targetVelocity) {
    int currVelocity = flyWheelGetVelocity();

    int speed = velocityPID(currVelocity, targetVelocity, PID_FLYWHEEL);
    flyWheelSetSpeed(speed);
}

void autoManualFlyWheelControl(int mtrPwr) {
    flyWheelSetSpeed(mtrPwr);
}

void autoBallIntake(int mtrPwr) {
    ballIntakeSetSpeed(mtrPwr);
}

void autoBallIndexer(int mtrPwr) {
    ballIndexerSetSpeed(mtrPwr);
}

void autoSmartRobot(int driveTarget, int limit, int ballIntake, int ballIndexer, int flyWheelRPM, long sentinel) {
    //reset encoders and gyros, then initializes exit conditions
    encoderReset(leftDriveEncoder);
    encoderReset(rightDriveEncoder);
    const int threshold = 180;
    gyroReset(gyro);
    delay(50);
    int leftDiff = driveTarget - encoderGet(leftDriveEncoder);
    int rightDiff = driveTarget - encoderGet(rightDriveEncoder);

    //initialize timeout condition
    const long timeStart = millis();
    long timer = millis() - timeStart;

    while (abs(leftDiff) > threshold && abs(rightDiff) > threshold) {
        //set drivetrain, ball intake, indexer, and flywheel motors speeds
        autoStraightDriveTrain(driveTarget, limit);
        autoBallIntake(ballIntake);
        autoBallIndexer(ballIndexer);
        autoManualFlyWheelControl(flyWheelRPM);

        //update exit condition variables
        leftDiff = driveTarget - encoderGet(leftDriveEncoder);
        rightDiff = driveTarget - encoderGet(rightDriveEncoder);
        printf("leftDiff %d current %d, timer %ld\n", leftDiff, encoderGet(leftDriveEncoder), timer);
        //check if algorithm reached timeout condition, terminate loop if true
        timer = millis() - timeStart;
        if (timer > sentinel) break;

        delay(20);
    }
    //turn off drivetrain motors
    driveTrainSetSpeed(0, 0);
}