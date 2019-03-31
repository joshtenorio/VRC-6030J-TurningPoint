/**
 *  @file autonomous.cpp
 */
#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */


void autonomous() {
    switch(autonIdentifier){
        case AUTON_NONE: //no auton
            break;
        case AUTON_REDFLAG: //flag red auton
            woebot.autonRedFlag();
            break;
        case AUTON_REDBACK: //back red auton
            woebot.autonRedBack();
            break;
        case AUTON_BLUEFLAG: //flag blue auton
            woebot.autonBlueFlag();
            break;
        case AUTON_BLUEBACK: //back blue auton
            woebot.autonBlueBack();
            break;
    }
}
