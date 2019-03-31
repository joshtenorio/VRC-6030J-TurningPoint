/**
*  @file autonred.c
*/
#include "main.h"

void autonRedFlag() {
    autoSmartRobot(780, 64, 0, 0, 127, 1200);
    delay(4500);
    autoBallIndexer(127);
    delay(800);
    autoTurnDriveTrain(-25, 1500);
    autoSmartRobot(750, 64, 0, 0, 0, 900);
}

void autonRedFlagCapOnly() {

}

void autonRedUltraFlag() {
    autoSmartRobot(1750, 64, 127, 0, 127, 1500);
    delay(200);
    autoSmartRobot(-1650, 64, 127, 0, 127, 1250);
    autoTurnDriveTrain(-69, 2500);
    autoSmartDriveTrain(-500, 48, 900);
    //descorerSetSpeed(-127);
    delay(1300);
    descorerSetSpeed(0);
    autoBallIntake(0);
    autoBallIndexer(127);
    delay(800);
    autoSmartRobot(800, 64, 127, 0, 96, 1000);
    autoBallIndexer(127);
    delay(800);
    autoSmartRobot(800, 64, 0, 0, 0, 800);
}

void autonRedBack() {
    autoSmartRobot(160, 64, 127, 0, 0, 1000);
}