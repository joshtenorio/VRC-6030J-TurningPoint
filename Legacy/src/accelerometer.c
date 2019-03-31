/**
 *  @file accelerometer.c
 */
#include "main.h"
/*
Accelerometer accelerometerInit(unsigned char xAxisPort, unsigned char yAxisPort, unsigned char zAxisPort) {
    Accelerometer a;
    a.xPort = xAxisPort;
    a.yPort = yAxisPort;
    a.zPort = zAxisPort;

    long calibration = 0;
    for (int i = 0; i < 100; i++) {
        calibration += analogRead(xAxisPort);
        calibration += analogRead(yAxisPort);
        delay(5);
    }
    /*
    to do:
    add another average thing (for loop) to get a super zero'd accelerometer
    */
/*
    a.accelZero = calibration / 200;
    calibration = 0;
    for (int i = 0; i < 100; i++) {
        calibration += (analogRead(zAxisPort) - a.accelZero);
        delay(5);
    }
    a.accelMultiplier = (calibration / 100) / 9.8; //changed this from 100 -> 1000
    calibration = 0;
    for (int i = 0; i < 100; i++) {
        calibration += (analogRead(xAxisPort) - a.accelZero);
        calibration += (analogRead(yAxisPort) - a.accelZero);
    }
    a.superAccelZero = calibration / 200;
    return a;
}

int accelerometerGetX(Accelerometer accel) {
    accel.x = ((analogRead(accel.xPort) - accel.accelZero)) - accel.superAccelZero; // *accel.accelMultiplier;
    return accel.x;
}
*/