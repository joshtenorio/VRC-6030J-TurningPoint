#include "main.h"

static float errorIntegral[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float errorPrevious = 0;
int PID(float current, float target, int mechanismIdentifier, float kP, float kI, float kD) {
    float errorCurrent = target - current;
    errorIntegral[mechanismIdentifier] += errorCurrent;
    float derivative = errorCurrent - errorPrevious;
    errorPrevious = errorCurrent;

    float pTerm = kP * errorCurrent;
    float iTerm = kI * errorIntegral[mechanismIdentifier];
    float dTerm = kD * derivative;
    int motorSpeed = pTerm + iTerm + dTerm;
    
    return motorSpeed;
}

