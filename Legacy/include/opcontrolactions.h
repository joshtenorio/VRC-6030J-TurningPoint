/** @file opcontrolactions.h
 *  @brief Provides high-level functionality for robot subsystems, specifically for driver control.
 *
 *  This file contains functions specifically designed for the driver control phase of the match. Specifically, each function controls a subsystem
 *  using the VEXnet joystick.
 */
#pragma once

/** 
 *  @brief Controls the drivetrain subsystem using tank drive control.
 *
 *  On both analog sticks, there are deadbands which keep the drivetrain motors from moving unless the analog sticks have moved past a certain
 *  point. 
 */
void opcontrolDriveTrain();

/**
 * @brief Controls the drivetrain subsystem using arcade control.
 * 
 * Instead of directly mapping an analog stick to a drivetrain side, arcade control uses one analog stick vertical axis to
 * move the robot forwards and backwards, and uses one analog stick horizontal axis control the turn. In arcade control, turns
 * work by adding or subtracting the analog stick's horizontal axis readings to/from the vertical axis reading.
 */
void opcontrolArcadeDrive();


/**
*  @brief Controls the flywheel subsystem with four settings.
*
*  The first setting will set the flywheel to 100% power, the second sets it to 75% power, the third sets it to 50% power,
*  and the fourth turns off the flywheel.
*/
void opcontrolFlyWheelRampControl();
/**
 *  @brief Controls the ball intake subsystem using two trigger buttons.
 *
 *  Ball intake control is fairly simple, as one button runs the ball intake motor at full power in one direction, and the other
 *  button runs the ball intake motor at full power in the other direction.
 */
void opcontrolBallIntake();

/**
 *  @brief Controls the ball indexer subsystem using two trigger buttons.
 *
 *  The ball indexer is mainly used to store balls from the ball intake. By storing balls into the indexer, this allows the driver
 *  to flip caps with the intake without losing balls.
 */
void opcontrolBallIndexer();

void opcontrolDebug();

/**
 * @brief Controls the descorer subsystem using two buttons.
 * 
 * The primary purpose of the descorer is to descore caps from the short posts. However, it also has a secondary function of 
 * flipping caps, either actively or passively.
 */
void opcontrolDescorer();