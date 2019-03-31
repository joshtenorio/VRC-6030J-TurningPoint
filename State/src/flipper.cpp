/**
 * @file flipper.cpp
 * @brief Implementation of the Flipper class
 *
 * @author Josh Tenorio, ACP Robotics
 */
#include "main.h"

Flipper::Flipper(): flipperMotor(CAP_FLIPPER_MOTORPORT){
    okapi::Motor flipperMotor(CAP_FLIPPER_MOTORPORT);

    flipped = false;
    pressed = false;
}

void Flipper::setVelocity(double percentage){
    flipperMotor.controllerSet(percentage);
}

void Flipper::driver(okapi::Controller controller){
  /*
    //double speed;
    if(controller.getDigital(okapi::ControllerDigital::R1)) flipperMotor.moveAbsolute(200, 120);
    else if(controller.getDigital(okapi::ControllerDigital::R2)) flipperMotor.moveAbsolute(-200, 120);
    else if(controller.getDigital(okapi::ControllerDigital::Y)) setVelocity(0.6);
    else if(controller.getDigital(okapi::ControllerDigital::X)) setVelocity(-0.6);
    else setVelocity(0.0);
    //else speed = 0.0;
    //setVelocity(speed);+
    */

    if(controller.getDigital(okapi::ControllerDigital::X)){
      if(!pressed){
        if(flipped){
          flipperMotor.moveRelative(-180, 120);
          flipped = false;
        }
        else{
          flipperMotor.moveRelative(180, 120);
          flipped = true;
        }
      }
      pressed = true;
    }
    else{
      pressed = false;
    }

    if(controller.getDigital(okapi::ControllerDigital::R1)){
      if(!pressed){
        if(flipped){
          flipperMotor.moveRelative(-30, 120);
          flipped = false;
        }
        else{
          flipperMotor.moveRelative(30, 120);
          flipped = true;
        }
      }
      pressed = true;
    }
    else{
      pressed = false;
    }    
}
