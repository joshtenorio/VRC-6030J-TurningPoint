/**
 * @file lift.hpp
 * @brief Contains prototypes for Lift class
 * 
 * @author Josh Tenorio, ACP Robotics
 * 
 * This file contains the prototype for the Lift class.
 * 
 */
#pragma once
#include "okapi/api.hpp"

#define LIFT_MOTORPORT 4
#define LIFT_PID 0.2, 0.001, 0.2
#define LIFT_PID_MAX_VELOCITY 60

/**
 * @brief represents the lift class
 * @author Josh Tenorio, ACP Robotics
 * 
 * The Lift class includes methods to control the lift subsystem.
 */
class Lift{
    private:
        /**
         * The motor used to control the lift subsystem
         */
        okapi::Motor liftMotor;

        /**
         * The PID controller used to set position targets for the lift
         * subsystem
         */
        okapi::AsyncPosIntegratedController pidController;
        
    public:
        /**
         * @brief the constructor for a Lift object
         * 
         * Currently, like every other class constructors, this takes
         * no parameters - the parameters for lift class can be
         * changed by modifying the define macros. In the future,
         * proper parameters will be implemented.
         */ 
        Lift();

        /**
         * @brief sets the velocity of the lift
         * 
         * This method sets the velocity of the lift. Although the
         * lift can run at a maximum of 200 RPM, it is highly recommended
         * to NOT run at 200 RPM - maximum controllable speed is around 70 RPM.
         * The parameter, percentage, is multiplied by the lift's gearset, so 
         * passing a 1 into this method will run the lift at 200 RPM, passing 0.5
         * will run the lift at 100 RPM, and so on.
         * 
         * @param percentage The lift's velocity, in a range from [-1, 1]
         */ 
        void setVelocity(double percentage);
        
        /**
         * @brief controls the lift subsystem with a controller
         * 
         * This method should be called in opcontrol(), or in another method
         * which is then called in opcontrol(). The controls for the lift are
         * the two left trigger buttons, and have plans for some preset heights.
         * 
         * @param controller The controller to use
         */ 
        void driver(okapi::Controller controller);

        /**
         * @brief gets the voltage delivered to the motor
         * 
         * gets the voltage delivered to the motor, in millivolts. This method is planned
         * to be used as the testbed for jesterOS' debug menu.
         * 
         * @return The motor's voltage in mV
         */
        int getVoltage();
};