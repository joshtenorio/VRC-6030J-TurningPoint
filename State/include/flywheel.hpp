/**
 * @file flywheel.hpp
 * 
 * @brief Contains the flywheel class prototype
 * 
 * @author Josh Tenorio, ACP Robotics
 */
#pragma once
#include "okapi/api.hpp"

#define FLYWHEEL_MOTORPORT 13

/**
 * @brief represents a flywheel subsystem
 * 
 * @author Josh Tenorio, ACP Robotics
 * 
 * This class contains methods used to control the
 * flywheel subsystem.
 */
class Flywheel{
    private:
        /**
         * the flywheel motor object
         */
        okapi::Motor flywheelMotor;
    
    public:
        /**
         * @brief the flywheel constructor
         * 
         * The constructor should either be called by
         * itself in initialize(), or as part of a
         * "super class" in their constructor, which in
         * turn should be called in initialize().
         */
        Flywheel();

        /**
         * @brief sets the flywheel's velocity
         * 
         * This method sets the flywheel's velocity target,
         * in revolutions per meter (RPM).
         * 
         * @param rpm The target velocity to run the flywheel at
         */
        void setVelocity(int rpm);

        /**
         * @brief controls the flywheel subsystem wtih a controller
         * 
         * This method is responsible for controlling the flywheel 
         * subsystem in driver control. There are four velocity targets,
         * which can be selected by pressing one of four buttons.
         * 
         * @param controller the okapi controller object used to control the robot
         */
        void driver(okapi::Controller controller);


};