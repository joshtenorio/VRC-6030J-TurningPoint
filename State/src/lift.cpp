/**
 * @file lift.cpp
 * @brief Implementation of the Lift class
 *
 * @author Josh Tenorio, ACP Robotics
 */
#include "main.h"

Lift::Lift(): liftMotor(LIFT_MOTORPORT),
        pidController(okapi::AsyncControllerFactory::posIntegrated(liftMotor, LIFT_PID_MAX_VELOCITY)){

    okapi::Motor liftMotor(LIFT_MOTORPORT);
    pidController = okapi::AsyncControllerFactory::posIntegrated(liftMotor, LIFT_PID_MAX_VELOCITY);
    liftMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
}

void Lift::setVelocity(double percentage){
    liftMotor.controllerSet(percentage);
}

void Lift::driver(okapi::Controller controller){
    double speed;
    if(controller.getDigital(okapi::ControllerDigital::L1)) speed = 0.35;
    else if(controller.getDigital(okapi::ControllerDigital::L2)) speed = -0.2;
    else speed = 0.0;

    setVelocity(speed);
}

int Lift::getVoltage(){ 
    return liftMotor.getVoltage();
}