/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

void autonomous() {
    /*
	autoSmartDriveTrain(1200, 1200);
    autoSmartDriveTrain(-500, 500);
    autoSmartDriveTrain(-600, -600);
    */

    if (analogRead(NOAUTO) < 100); //do nothing
    if (analogRead(REDULTRAFLAG) < 100) autonRedUltraFlag();
    else if (analogRead(REDFLAG) < 100) autonRedFlag();
    else if (analogRead(BLUEFLAG) < 100) autonBlueFlag();
    else if (analogRead(REDBACK) < 100) autonRedBack(); //implement this auton
    else if (analogRead(BLUEBACK) < 100) autonBlueBack(); //implement this auton
    /*LOLOLOLOLOLOLOLOL*/
    //autoTurnDriveTrain(-90);
    //autonRedFlagCapOnly();
    //autoSmartRobot(1800, 1800, 127, 0, 0);
    //autoSmartRobot(-1800, -1800, 127, 0, 0);

}
