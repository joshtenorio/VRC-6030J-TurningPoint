    /** @file libtracking.h
 *  @brief Provides an Absolute Position System (APS) for tracking the robot's absolute
 *  position in the field.
 *
 *  The APS algorithm, when completed, will be able to accurately track the robot's
 *  absolute position relative to a Cartesian plane using three tracking wheels.
 *
 */
#pragma once

#define MATH_PI 3.14159265358979323846

typedef struct {
    float xPos;
    float yPos;
    float orientation;

    float leftTotalDistTravelled;
    float rightTotalDistTravelled;
    float backTotalDistTravelled;

    int leftEncoderCount;
    int rightEncoderCount;
    int backEncoderCount;
} State;

typedef struct {
    //drivetrain encoders to collect data from
    Encoder leftEncoder;
    Encoder rightEncoder;
    Encoder backEncoder;
    
    float wheelDiameter; //diameter of tracking wheel
    float wheelCircumference; //circumference of tracking wheel

    //current and previous robot states
    State current;
    State previous;

    float leftDistFromCenter; //distance between tracking center and left tracking wheel
    float rightDistFromCenter; //distance between tracking center and right tracking wheel
    float backDistFromCenter; //distance between tracking center and back tracking wheel

    float initPosX; //starting point of tracking center on the x axis
    float initPosY; //starting point of tracking center on the y axis
    float initOrientation; //starting orientation of robot
} APSTracker;

/**
 *  @brief Initializes a robot state for use by an APS Tracker.
 *
 *  @param x The robot's initial x position, in inches
 *  @param y The robot's inital y position, in inches
 *  @param heading The robot's inital global orientation, in radians
 *
 */
State stateInit(float x, float y, float heading);

/**
 *  @brief Initializes an APS Tracker to track the robot's absolute position.
 *
 *  trackerInit() should be run in init.c and is used in a similar fashion to
 *  encoderInit().
 *
 *  @param left The left encoder to track
 *  @param right The right encoder to track
 *  @param back The back encoder to track
 *  @param wheelSize The diameter of the tracking wheel
 *  @param inital The robot's initial position
 *  @param leftDist The distance between the left tracking wheel and the tracking center
 *  @param rightDist The distance between the right tracking wheel and the tracking center
 *  @param backDistFromCenter The distance between the back tracking wheel and the tracking center
 *
 *  @return Returns an initialized APS Tracker 
 */
APSTracker trackerInit(Encoder left, Encoder right, Encoder back, float wheelSize, State initial, float leftDist, float rightDist, float backDistFromCenter);

/**
 *  @brief Updates an APS Tracker's current state.
 *  
 *  The APS tracker models the robot's movement as an arc. To determine the robot's updated state
 *  the tracker measures the straight-line distance between the previous and current robot states
 *  and utilises trigonometry to calculate change-in-position. This is then added to the previous
 *  robot state in order to determine the robot's new state.
 *
 *  @param APSTracker the tracker to update state for.
 */
void trackerUpdateState(APSTracker);
