/** @file subsystems.h
* @brief Provides high-level functionality for robot subsystems.
*
* This file contains functions that can be used for both driver control and autonomous, though drivercontrol-specific and
* autonomous-specific functions can be found in their own files.
*
*/
#pragma once

////////////////
//Sensor ports//
////////////////

//Analog ports
#define GYRO_PORT 2


//jumper clip ports, in analog ports:
#define NOAUTO 3
#define REDULTRAFLAG 4
#define REDFLAG 5
#define REDBACK 6
#define BLUEFLAG 7
#define BLUEBACK 8


//Digital ports
#define RIGHT_DRIVE_ENCODER_TOP 6
#define RIGHT_DRIVE_ENCODER_BOT 7
#define LEFT_DRIVE_ENCODER_TOP 4
#define LEFT_DRIVE_ENCODER_BOT 5
#define BACK_DRIVE_ENCODER_TOP 12
#define BACK_DRIVE_ENCODER_BOT 11
#define FLYWHEEL_ENCODER_TOP 2
#define FLYWHEEL_ENCODER_BOT 3
Encoder rightDriveEncoder;
Encoder leftDriveEncoder;
Encoder backDriveEncoder;
Encoder flyWheelEncoder;
Encoder ballIntakeEncoder;
Gyro gyro;



///////////////
//Motor ports//
///////////////


#define TOP_FLYW_PORT 9 //pOWER eXPANDUR //reverse
#define DESCORER_PORT 8 
#define LF_DRIVE_PORT 7
#define RF_DRIVE_PORT 2
#define LB_DRIVE_PORT 6
#define RB_DRIVE_PORT 3
#define BALL_INTAKE_PORT 5
#define BALL_INDEXER_PORT 4

/////////////////////
//Controller macros//
/////////////////////
#define PANIC_BUTTON joystickGetDigital(1, 7, JOY_UP)

////////////////////////
//Function definitions//
////////////////////////

/**
 *  @brief Controls the flywheel subsystem speed.
 *  @param speed The speed to run the flywheel subsystem at
 */
void flyWheelSetSpeed(int speed);

/**
 *  @brief Controls the drivetrain subsystem speed.
 *  @param leftSpeed The speed to set the left wheels of the drivetrain to
 *  @param rightSpeed The speed to set the right wheels of the drivetrain to
 */
void driveTrainSetSpeed(int leftSpeed, int rightSpeed);

/**
 *  @brief Controls the ball intake subsystem speed.
 *  @param speed The speed to run the ball intake at
 */
void ballIntakeSetSpeed(int speed);

/**
 *  @brief Controls the ball indexer subsystem speed.
 *  @param speed The spped to run the ball indexer at
 */
void ballIndexerSetSpeed(int speed);
/**
 *  @brief Gets the velocity of the flywheel subsystem.
 *
 *  It gets the flywheel's RPM by getting the current flywheel encoder reading and
 *  doing unit analysis to convert the reading (in deg/20 ms) to RPM (revolutions/minute)
 *
 *  @return The flywheel's current RPM
 */
int flyWheelGetVelocity();

/**
 *  @brief Gets the flywheel motors' speed.
 */
int flyWheelGetMotor();

/**
 *  @brief Gets the left drivetrain motors' speed.
 */
int driveTrainGetLeftMotor();

/**
 *  @brief Gets the right drivetrain motors' speed.
 */
int driveTrainGetRightMotor();

/**
 *  @brief Gets the ball intake motor's speed.
 */
int ballIntakeGetMotor();

/**
 * @brief Sets the descorer's speed.
 * 
 * @param speed The speed at which to run the descorer at.
 */
void descorerSetSpeed(int speed);
