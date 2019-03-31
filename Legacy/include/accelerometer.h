/**
 *  @file accelerometer.h
 *
 *  @brief Provides a library to easily use VEX accelerometers
 *
 *  This library, when fully implemented, will contain functions to help utilise
 *  the VEX accelerometer.
 */
#pragma once

typedef struct {
    int xPort;
    int yPort;
    int zPort;

    int x;
    int y;
    int z;

    int accelZero;
    int superAccelZero;
    float accelMultiplier;
} Accelerometer;

/**
 *  @brief Initializes and enables an accelerometer on three analog ports.
 *
 *  accelerometerInit() should be run in init.c and is used in the same way as 
 *  encoderGet().
 *
 *  @param xAxisPort The analog port for the x-axis
 *  @param yAxisPort The analog port for the y-axis
 *  @param zAxisPort The analog port for the z-axis
 *
 *  @return Returns an initialized accelerometer ready for use
 */
Accelerometer accelerometerInit(unsigned char xAxisPort, unsigned char yAxisPort, unsigned char zAxisPort);

/**
 *  @brief Reads the accelerometer's x axis.
 *
 *  @return Returns the accelerometer's acceleration on the x axis in m/s^2.
 */
int accelerometerGetX(Accelerometer accel);