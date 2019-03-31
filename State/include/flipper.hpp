/**
 * @file flipper.hpp
 * 
 * @brief contains the prototype for the Flipper class
 * 
 * @author Josh Tenorio, ACP Robotics
 */
#pragma once
#include "okapi/api.hpp"

#define CAP_FLIPPER_MOTORPORT 3

/**
 * @brief represents a cap flipper subsystem
 * 
 * This class contains methods used to control the 
 * cap flipper, primarily in driver control.
 */
class Flipper{
    private:
        /**
         * The motor object for the cap flipper motor
         */
        okapi::Motor flipperMotor;

        /**
         * A boolean variable used to represent the current
         * state of the cap flipper - flipped or not flipped.
         */
        bool flipped;

        /**
         * A boolean variable used to detect a button press
         */
        bool pressed;
    public:
        /**
         * @brief the constructor for the Flipper class
         * 
         * The constructor should be called in initialize(),
         * or as part of a larger class with a collection of
         * subsystems.
         */
        Flipper();

        /**
         * @brief sets the speed of the cap flipper
         * 
         * Although the cap flipper could run at max
         * speed (around 200 RPM), it is recommended
         * to run at around half speed so the cap does
         * not fly out. However, if the flipper is ran
         * too slow the cap may slip out. The argument
         * for this method will be scaled to the motor's
         * gearset.
         * 
         * @param the velocity to run the flipper at, from [-1, 1]
         */
        void setVelocity(double percentage);

        /**
         * @brief controls the cap flipper subsystem in driver control
         * 
         * The control scheme for the flipper is just one button - a
         * button press will flip the flipper one way, and the subsequent
         * press will flip it the other way.
         */
        void driver(okapi::Controller controller);
};
