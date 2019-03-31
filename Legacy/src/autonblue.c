/**
*  @file autonblue.c
*/
#include "main.h"

void autonBlueFlag() {
    autoSmartRobot(640, 64, 0, 0, 127, 1200);
    delay(4500);
    autoBallIndexer(127);
    delay(800);
    //autoTurnDriveTrain(40, 1500);
    autoSmartRobot(410, 64, 0, 0, 0, 900);
    autoRightDriveTrain(500, 127, 800);
    
}

void autonBlueBack() {
    autoManualFlyWheelControl(127);
    delay(6500);
    autoBallIndexer(127);
    delay(1500);
    autoSmartRobot(-300, 127, 0, 0, 0, 1000);
}