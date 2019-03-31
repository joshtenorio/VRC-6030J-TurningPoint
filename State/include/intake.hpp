/**
 * @file intake.hpp
 * 
 * @brief Contains the prototype for the intake class
 * 
 * @author Josh Tenorio, ACP Robotics
 */
#pragma once
#include "okapi/api.hpp"

#define INTAKE_MOTORPORT 14

/**
 * @brief represents the ball intake subsystem
 * 
 * @author Josh Tenorio, ACP Robotics
 * 
 * The Intake class contains methods used for
 * controlling the intake subsystem.
 */
class Intake{
    private:
        /**
         * the motor object which represents the ball intake motor
         */
        okapi::Motor intakeMotor;
    public:
        /**
         * @brief the constructor for the intake class
         * 
         * The constructor should at some point
         * be called in initialize().
         */
        Intake();

        /**
         * @brief sets the ball intake's velocity
         * 
         * This method sets the ball intake's 
         * target velocity. The argument passed into
         * this method is remapped to fit the intake's
         * gearset.
         * 
         * @param percentage The speed to run the intake at in percent
         */
        void setVelocity(double percentage);

        /**
         * @brief controls the ball intake in driver control
         * 
         * The controls for the intake are simple, as it is
         * just two buttons. One button runs the intake inwards,
         * the other button runs it out.
         */
        void driver(okapi::Controller controller);

};