/**
 * @file intake.cpp
 * @brief Implementation of the Intake class
 *
 * @author Josh Tenorio, ACP Robotics
 */
#include "main.h"

Intake::Intake(): intakeMotor(INTAKE_MOTORPORT){
    okapi::Motor intakeMotor(INTAKE_MOTORPORT);
}

void Intake::setVelocity(double percentage){
    intakeMotor.controllerSet(-percentage);
}

void Intake::driver(okapi::Controller controller){
    double speed;
    if(controller.getDigital(okapi::ControllerDigital::L1)) speed = 0.95;
    else if(controller.getDigital(okapi::ControllerDigital::L2)) speed = -0.95;
    else speed = 0.0;
    setVelocity(speed);
}