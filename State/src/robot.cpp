/**
 * @file robot.cpp
 * @brief Implementation of the Robot class
 *
 * @author Josh Tenorio, ACP Robotics
 */
#include "main.h"

Robot::Robot(){
    Chassis chassis();
    Lift lift();
    Flipper flipper();
    Flywheel flywheel();
    Intake intake();

    modeToggle = -1;

}

void Robot::driver(okapi::Controller controller, okapi::ControllerButton buttonToggle){
    //change driver mode and update controller text
    /*
    if(buttonToggle.changedToPressed()){
        modeToggle *= -1;
        switch(modeToggle){
            case -1:
                controller.setText(0, 0, "flag mode");
                break;
            case 1:
                controller.setText(0, 0, "cap mode");
                break;
        }
    }
    */

   if(controller.getDigital(okapi::ControllerDigital::B)){
       modeToggle = 1;
       controller.setText(0, 0, "cap mode");
   }
   else if(controller.getDigital(okapi::ControllerDigital::Y)){
       modeToggle = -1;
       controller.setText(0, 0, "flag mode");
   }

    //control subsystems
    switch(modeToggle){
        case -1:
            chassis.driver(controller, modeToggle);
            flywheel.driver(controller);
            intake.driver(controller);
            //controller.setText(0, 0, "flag mode");
        break;
        case 1:
            chassis.driver(controller, modeToggle);
            lift.driver(controller);
            flipper.driver(controller);
            //controller.setText(0, 0, "cap mode");
        break;
    }

}


void Robot::autonRedFlag(){
    intake.setVelocity(0.8);
    pros::delay(400);
    intake.setVelocity(0.0);

    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{3.25_ft, 0_ft, 0_deg}
    }, "toBall");
    chassis.setTarget("toBall", true);
    chassis.waitUntilSettled();
    chassis.removePath("toBall");

    intake.setVelocity(0.8);
    pros::delay(1000);
    intake.setVelocity(0.0);

    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{3.5_ft, 0.5_ft, 60_deg},
    }, "backToTile");
    chassis.setTarget("backToTile", false);
    flywheel.setVelocity(200);
    chassis.waitUntilSettled();
    chassis.removePath("backToTile");

    chassis.turnAngle(-28_deg);

    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{1.0_ft, 0_ft, 0_deg}
    }, "adjust");
    chassis.setTarget("adjust", true);
    chassis.waitUntilSettled();
    chassis.removePath("adjust");

    intake.setVelocity(1.0);
    pros::delay(800);
    intake.setVelocity(0.0);

    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{1.75_ft, 0_ft, 0_deg}
    }, "moveToMidFlag");
    chassis.setTarget("moveToMidFlag", true);
    chassis.waitUntilSettled();
    chassis.removePath("moveToMidFlag");

    intake.setVelocity(1.0);
    pros::delay(1000);
    intake.setVelocity(0.0);

    flywheel.setVelocity(0);

    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{1.75_ft, -0.5_ft, 0_deg}
    }, "toggleLowFlag");
    chassis.setTarget("toggleLowFlag", true);
    chassis.waitUntilSettled();

    chassis.removePath("toggleLowFlag");
}

void Robot::autonBlueFlag(){
    intake.setVelocity(0.8);
    pros::delay(400);
    intake.setVelocity(0.0);

    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{3.25_ft, 0_ft, 0_deg}
    }, "toBall");
    chassis.setTarget("toBall", true);
    chassis.waitUntilSettled();
    chassis.removePath("toBall");

    intake.setVelocity(0.8);
    pros::delay(1000);
    intake.setVelocity(0.0);

    //////////////
    //Turns here//
    //////////////
    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{3.25_ft, -0.5_ft, -60_deg},
    }, "backToTile");
    chassis.setTarget("backToTile", false);
    flywheel.setVelocity(200);
    chassis.waitUntilSettled();
    chassis.removePath("backToTile");

    pros::delay(800);

    chassis.turnAngle(24_deg);
    /////////////
    //Turns end//
    /////////////
    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{1_ft, 0_ft, 0_deg}
    }, "adjust");
    chassis.setTarget("adjust", true);
    chassis.waitUntilSettled();
    chassis.removePath("adjust");

    intake.setVelocity(1.0);
    pros::delay(700);
    intake.setVelocity(0.0);

    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{2_ft, 0_ft, 0_deg}
    }, "moveToMidFlag");
    chassis.setTarget("moveToMidFlag", true);
    chassis.waitUntilSettled();
    chassis.removePath("moveToMidFlag");

    intake.setVelocity(1.0);
    pros::delay(1000);
    intake.setVelocity(0.0);

    flywheel.setVelocity(0);

    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{1.75_ft, 0.5_ft, 0_deg}
    }, "toggleLowFlag");
    chassis.setTarget("toggleLowFlag", true);
    chassis.waitUntilSettled();

    chassis.removePath("toggleLowFlag");
}

void Robot::autonRedBack(){
    /*
    intake.setVelocity(0.8);
    pros::delay(400);
    intake.setVelocity(0.0);

    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{3.25_ft, 0_ft, 0_deg}
    }, "toBall");
    chassis.setTarget("toBall", true);
    chassis.waitUntilSettled();
    chassis.removePath("toBall");

    intake.setVelocity(0.8);
    pros::delay(1000);
    intake.setVelocity(0.0);

    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{3.25_ft, 0_ft, 0_deg}
    }, "back");
    chassis.setTarget("back", false);
    chassis.waitUntilSettled();
    chassis.removePath("back");
    */
   intake.setVelocity(0.8);
    pros::delay(400);
    intake.setVelocity(0.0);

    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{3.25_ft, 0_ft, 0_deg}
    }, "toBall");
    chassis.setTarget("toBall", true);
    chassis.waitUntilSettled();
    chassis.removePath("toBall");

    intake.setVelocity(0.8);
    pros::delay(1000);
    intake.setVelocity(0.0);

    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{0.75_ft, -1.5_ft, 90_deg}
    }, "alignWithPlat");
    chassis.setTarget("alignWithPlat", false);
    chassis.removePath("alignWithPlat");

    
   
}

void Robot::autonBlueBack(){
    flywheel.setVelocity(168);
    pros::delay(7000);
    intake.setVelocity(0.8);
    pros::delay(2500);
    intake.setVelocity(0.0);

    chassis.turnAngle(-88_deg);

     chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{3.25_ft, 0_ft, 0_deg}
    }, "toBall");
    chassis.setTarget("toBall", true);
    chassis.waitUntilSettled();
    chassis.removePath("toBall");

    intake.setVelocity(0.8);
    pros::delay(1000);
    intake.setVelocity(0.0);

    chassis.generatePath({
        okapi::Point{0_ft, 0_ft, 0_deg},
        okapi::Point{0.75_ft, -1.5_ft, 90_deg}
    }, "alignWithPlat");
    chassis.setTarget("alignWithPlat", false);
    chassis.removePath("alignWithPlat");
}

void Robot::autonSkills(){
    
}
