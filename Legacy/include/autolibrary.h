/** @file autolibrary.h
 *  @brief Provides high-level functionality for autonomously controlling robot subsystems.
 *
 *  This file contains functions specifically designed for the autonomous period, as well as for programminng skills. 
 *  Our autonomi code can be found in files autonblue.c and autonred.c, and documentation for both can be found in their
 *  respective header files.
 *
 */

#pragma once

/** 
*  @brief Controls the drivetrain subsystem speed using position PID targeting and encoders

*  @param leftTarget The target encoder value of the left drivetrain encoder
*  @param rightTarget The target encoder value of the right drivetrain encoder
*  @param limit The maximum power the drivetrain motors can be set to
*/
void autoDriveTrain(int leftTarget, int rightTarget, int limit);

/**
*  @brief Controls the drivetrain subsystem with position PID, and utilises a gyro to maintain a straight path

*  @param target The target encoder value of both drivetrain encoders
*  @param limit The maximum power the drivetrain motors can be set to
*/
void autoStraightDriveTrain(int target, int limit);

/**
*  @brief Controls the drivetrain subsystem's turn through gyro values

*  @param degree The target gyro value for turn
*  @param sentinel How long the algorithm is allowed to run, in milliseconds
*/
void autoTurnDriveTrain(int degree, long sentinel);

/**
*   @brief Only controls the right drivetrain motors
*
*   This algorithm will only control the right side of the drivetrain subsystem. This is uniquely
*   useful for moving the robot along a small arc.
*
*   @param target The target encoder value of the right drivetrain encoder
*   @param limit The fastest speed the drivetrain motors are allowed to run at
*   @param sentinel How long the algorithm is allowed to run, in milliseconds
*/
void autoRightDriveTrain(int target, int limit, long sentinel);

/**
*   @brief Only controls the left drivetrain motors
*
*   This algorithm will only control the left side of the drivetrain subsystem. This is uniquely
*   useful for moving the robot along a small arc.
*
*   @param target The target encoder value of the left drivetrain encoder
*   @param limit The fastest speed the drivetrain motors are allowed to run at
*   @param sentinel How long the algorithm is allowed to run, in milliseconds
*/
void autoLeftDriveTrain(int target, int limit, long sentinel);

/**
*  @brief Controls autoDriveTrain by continuously updating encoder values until reaching target values

*  @param target The target encoder value of the drivetrain encoders
*  @param limit The maximum power the drivetrain motors can be set to
*  @param sentinel How long the algorithm is allowed to run, in milliseconds
*/
void autoSmartDriveTrain(int target, int limit, long sentinel);

void autoVelocityFlyWheelControl(int targetVelocity);

void autoManualFlyWheelControl(int mtrPwr);

/**
 *  @brief Controls the ball intake subsystem directly
 *  
 *  @param mtrPwr The motor power to set the ball intake to
 */
void autoBallIntake(int mtrPwr);    

void autoBallIndexer(int mtrPwr);

/**
 *  @brief Controls all robot subsystems during the duration of the robot's drive time.

 *  @param driveTarget The target encoder value for the drivetrain encoders
 *  @param limit The maximum value the drivetrain motors can be set to
 *  @param ballIntake The motor power to set the ball intake subsystem to
 *  @param ballIndexer The motor power to set the ball indexer subsystem to
 *  @param flyWheelRPM The target RPM of the flywheel; currently is used to manually set flywheel power
 *  @param sentinel How long the algorithm is allowed to run, in milliseconds
 */
void autoSmartRobot(int driveTarget, int limit, int ballIntake, int ballIndexer, int flyWheelRPM, long sentinel);