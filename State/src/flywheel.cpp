/**
 * @file flywheel.cpp
 * @brief Implementation of the Flywheel class
 *
 * @author Josh Tenorio, ACP Robotics
 */
#include "main.h"

Flywheel::Flywheel(): flywheelMotor(FLYWHEEL_MOTORPORT){
    okapi::Motor flywheelMotor(FLYWHEEL_MOTORPORT);
}

void Flywheel::setVelocity(int rpm){
    flywheelMotor.moveVelocity(-rpm);
}
int speed = 0;
void Flywheel::driver(okapi::Controller controller){
    
    if(controller.getDigital(okapi::ControllerDigital::up)) speed = 150;
    else if(controller.getDigital(okapi::ControllerDigital::down)) speed = 50;
    else if(controller.getDigital(okapi::ControllerDigital::left)) speed = 0;
    else if(controller.getDigital(okapi::ControllerDigital::right)) speed = 200;

    setVelocity(speed);

}