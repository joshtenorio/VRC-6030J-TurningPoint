/** @file motor.h
*  @brief Provides slew control for motors.
*
*  This file contains functions designed to reduce stress on motors by gradually increasing
*  or decreasing voltage based on the target speed. By gradually increasing or decreasing
*  voltage, motors are more likely to not get damaged by a command that suddenly changes
*  the motor's voltage.
*
*/
#pragma once

/**
 * Slew rate control (run as task in init.c)
 * Works together with smartMotorSet() -- always use smartMotorSet()!
 */
void slewControlTask(void * parameter);

/**
 * [Requires slewControlTask() to be running in background]
 * Sets desired speed for a given motor
 * @param motor The motor whose desired speed to set
 * @param cmd Desired speed for that motor
 */
void smartMotorSet(int motor, int cmd);

/**
 * Returns the desired speed for a specific motor 
 * @param motor The motor whose desired speed to return
 */
int smartMotorGet (int motor);

/**
 *  Returns the smallest number of two integers.
 *  @param a The first number to compare
 *  @param b The second number to compare
 */
int min(int a, int b);

/**
 *  Returns the largest number of two integers.
 *  @param a The first number to compare
 *  @param b The second number to compare
 */
int max(int a, int b);


