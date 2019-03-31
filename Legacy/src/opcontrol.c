/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include <math.h>

void operatorControl() {

	while (1) {
      
        opcontrolDriveTrain();
        //pcontrolArcadeDrive();
        opcontrolFlyWheelRampControl();
        opcontrolBallIntake();
        opcontrolBallIndexer();
        opcontrolDescorer();
        opcontrolDebug();

        //printf("left enc %d, right enc %d\n", encoderGet(leftDriveEncoder), encoderGet(rightDriveEncoder));
        printf("descorer motor %d\n", smartMotorGet(DESCORER_PORT));
        delay(20);
	}

}