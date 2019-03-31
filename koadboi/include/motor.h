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

int min(int a, int b);
int max(int a, int b);


