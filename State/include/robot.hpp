/**
 * @file robot.hpp
 * @brief Contains prototypes and documentation for the Robot class
 * 
 * @author Josh Tenorio, ACP Robotics
 * 
 * This file contains the Robot class prototype.
 * 
 */ 
#pragma once
#include "main.h"

/**
 * @brief represents the robot.
 * @author Josh Tenorio, ACP Robotics
 * 
 * The Robot class combines robot subsystems for use in opcontrol
 * and autonomous. This allows for controlling multiple subsystems
 * synchronously, which is very useful for creating autonomous
 * routines and driver presets.
 */
class Robot{
    private:
        /**
         *  The variable used to keep track of the selected driver mode.
         *  when modeToggle is 1, the controller is in cap mode; when
         *  modeToggle is -1, the controller is in flag mode.
         */
        int modeToggle;

        /**
         * The chassis object to control
         */
        Chassis chassis;

        /**
         * The lift object to control
         */
        Lift lift;

        /**
         * The flipper object to control
         */
        Flipper flipper;

        /**
         * The flywheel object to control
         */
        Flywheel flywheel;

        /**
         * The intake object to control
         */
        Intake intake;

        
    public:
        /**
         * @brief the constructor for the Robot class
         * 
         * The constructor should be called in initialize(). In order for the robot object 
         * to be used, it should also be initialized outside of initialize.cpp outside of 
         * any function, and also defined as an extern in a header file.
         */
        Robot();

        /**
         * @brief the driver method for the robot
         * 
         * This method combines all of the driver() methods from each subsystem object. As such,
         * this driver() should be called in opcontrol(). The controls for this robot are divided
         * into a cap mode and a flag mode; the modes can be toggled through by pressing the toggle
         * button.
         * 
         * @param controller the controller to use
         * @param buttonToggle the controller button to set for the toggle button
         */
        void driver(okapi::Controller controller, okapi::ControllerButton buttonToggle);

        /**
         * @brief a red side autonomous in the flag tile
         * 
         * This autonomous program grabs the ball from the tilted cap scoring it in the process,
         * then shoots both the aforementioned ball and the preload ball at the blue flags, toggling
         * both high flags and then driving forward to toggle the low flag. In total, this autonomous
         * scores 6 points.
         */
        void autonRedFlag();

        void autonBlueFlag();

        void autonRedBack();
        
        void autonBlueBack();

        void autonSkills();
};