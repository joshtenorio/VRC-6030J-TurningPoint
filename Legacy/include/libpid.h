/** @file libpid.h
 *  @brief Provides PID functions for use by robot subsystems.
 *
 *  This file contains a generic position PID function that can be used by any robot subsystem
 *  with a valid sensor attached (eg: encoder, potentiometer, gyro, etc). In addition to the
 *  position PID function, this file also includes a velocity PID function that is best utilised
 *  by the drivetrain and flywheel. Last but not least, this file declares constants for each
 *  subsystem.
 */
#pragma once

#define POS_PID_DRIVETRAIN_L 0, 0.3, 0.000, 0.0
#define POS_PID_DRIVETRAIN_R 1, 0.3, 0.000, 0.0
#define V_PID_DRIVETRAIN     2, 3.0, 0.000, 0.0
#define PID_FLYWHEEL         4, 0.1, 0.000, 0.0
#define PID_GYRO             5, 0.3, 0.002, 0.5


/**
 *  @brief Uses a PID controller to calculate the motor speed to achieve/maintain a
 *  target sensor reading
 *  
 *  This function takes a target value, and aims to reach that target value within a
 *  reasonable time with limited overshoot. 
 *
 *  @param current The current reading of a sensor
 *  @param target The desired reading from the same sensor
 *  @param subsystemIdentifier A unique ID to identify the subsystem
 *  @param kP The constant for the P term
 *  @param kI The constant for the I term
 *  @param kD The constant for the D term
 *
 *  @return The motor speed at which to run the subsystem
 */
int positionPID(float current, float target, int subsystemIdentifier, float kP, float kI, float kD);

/**
 *  @brief Uses a PID controller to calculate the change in motor speed needed to achieve/maintain a
 *  target velocity
 *
 *  In order to calculate the change in motor speed, the current ,target and PID constants parameters
 *  are fed into a position PID controller. The output of the position PID is then added to the motor's current
 *  speed.
 *
 *  @param current The current reading of a sensor
 *  @param target The desired reading from the same sensor
 *  @param subsystemIdentifier A unique ID to identify the subsystem
 *  @param kP The constant for the P term
 *  @param kI The constant for the I term
 *  @param kD The constant for the D term
 *
 *  @return The motor speed at which to run the subsystem
 */
int velocityPID(float current, float target, int subsystemIdentifier, float kP, float kI, float kD);