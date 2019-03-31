 /**
 *  @file libtracking.c
 */
#include "main.h"

State stateInit(float x, float y, float heading) {
    State state;
    state.xPos = x;
    state.yPos = y;
    state.orientation = heading;

    state.leftTotalDistTravelled = 0.0;
    state.rightTotalDistTravelled = 0.0;
    state.backTotalDistTravelled = 0.0;

    state.leftEncoderCount = 0;
    state.rightEncoderCount = 0;
    state.backEncoderCount = 0;
}

APSTracker trackerInit(Encoder left, Encoder right, Encoder back, float wheelSize, State initial, float leftDist, float rightDist, float backDist) {
    //initializing constants
    APSTracker tracker;
    tracker.leftEncoder = left;
    tracker.rightEncoder = right;
    tracker.backEncoder = back;
    tracker.wheelDiameter = wheelSize;
    tracker.leftDistFromCenter = leftDist;
    tracker.rightDistFromCenter = rightDist;
    tracker.backDistFromCenter = backDist;

    //calculate circumference of tracking wheel
    int wheelRadius = wheelSize / 2;
    tracker.wheelCircumference = 2 * wheelRadius * MATH_PI;

    //initializing robot state
    tracker.current = initial;
    tracker.previous = initial;

    return tracker;
}

void trackerUpdateState(APSTracker tracker) {
    tracker.previous = tracker.current;

    //store encoder counts
    tracker.current.leftEncoderCount = encoderGet(tracker.leftEncoder);
    tracker.current.rightEncoderCount = encoderGet(tracker.rightEncoder);
    tracker.current.backEncoderCount = encoderGet(tracker.backEncoder);

    //determine change in encoder counts using data from 20 ms ago
    int deltaLeftEncoderCount = tracker.current.leftEncoderCount - tracker.previous.leftEncoderCount;
    int deltaRightEncoderCount = tracker.current.rightEncoderCount - tracker.previous.rightEncoderCount;
    int deltaBackEncoderCount = tracker.current.backEncoderCount - tracker.previous.backEncoderCount;
    
    //convert encoder counts to inches
    float leftDistTravelled = ((float)deltaLeftEncoderCount / (float)360) * tracker.wheelCircumference;
    float rightDistTravelled = ((float)deltaRightEncoderCount / (float)360) * tracker.wheelCircumference;
    float backDistTravelled = ((float)deltaBackEncoderCount / (float)360) * tracker.wheelCircumference;

    //calculate new robot orientation
    float deltaOrientation = (leftDistTravelled - rightDistTravelled) / (tracker.leftDistFromCenter - tracker.rightDistFromCenter);
    tracker.current.orientation = tracker.previous.orientation + deltaOrientation;


    
}