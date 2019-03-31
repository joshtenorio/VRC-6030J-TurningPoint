/**
 * @file chassis.cpp
 * @brief Implementation of the Chassis class
 *
 * @author Josh Tenorio, ACP Robotics
 */
#include "main.h"

Chassis::Chassis(): chassis(okapi::ChassisControllerFactory::create({CHASSIS_MOTORPORT_LEFT_FRONT,
                                                    -CHASSIS_MOTORPORT_LEFT_BACK},
                                                    {-CHASSIS_MOTORPORT_RIGHT_FRONT,
                                                    CHASSIS_MOTORPORT_RIGHT_BACK},
                                                    GEARSET_GREEN,
                                                    {4_in, 17.25_in})),
                    mpController(okapi::AsyncControllerFactory::motionProfile(
                                    0.609, 1.5, 5.0, chassis)){

    auto chassis = okapi::ChassisControllerFactory::create({CHASSIS_MOTORPORT_LEFT_FRONT,
                                                        -CHASSIS_MOTORPORT_LEFT_BACK},
                                                        {-CHASSIS_MOTORPORT_RIGHT_FRONT,
                                                        CHASSIS_MOTORPORT_RIGHT_BACK},
                                                        GEARSET_GREEN,
                                                        {4_in, 17.25_in});

    auto mpController = okapi::AsyncControllerFactory::motionProfile(0.609, 1.5, 5.0, chassis);

}

void Chassis::driver(okapi::Controller controller, int multiplier){
    double left;
    double right;
    switch(multiplier){
        case -1:
            left = -controller.getAnalog(okapi::ControllerAnalog::rightY);
            right = -controller.getAnalog(okapi::ControllerAnalog::leftY);
            break;
        case 1:
            left = controller.getAnalog(okapi::ControllerAnalog::leftY);
            right = controller.getAnalog(okapi::ControllerAnalog::rightY);
            break;
    }
    chassis.tank(left, right, 0.05);
}

void Chassis::moveTo(std::initializer_list<okapi::Point> waypoints){
    mpController.moveTo(waypoints);
}

void Chassis::generatePath(std::initializer_list<okapi::Point> iwaypoints, const std::string &ipathId){
  printf("auton identifer %d\n", autonIdentifier);
  mpController.generatePath(iwaypoints, ipathId);
}

void Chassis::removePath(const std::string &ipathId){
  mpController.removePath(ipathId);
}

void Chassis::setTarget(std::string ipathId, bool ibackwards){
  mpController.setTarget(ipathId, ibackwards);
}

void Chassis::waitUntilSettled(){
  mpController.waitUntilSettled();
}

void Chassis::turnAngle(okapi::QAngle theta){
  chassis.turnAngle(theta);
}
