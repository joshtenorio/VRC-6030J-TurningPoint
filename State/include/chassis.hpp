/**
 * @file chassis.hpp
 * @brief Contains prototypes for the Chassis class
 *
 * @author Josh Tenorio, ACP Robotics
 *
 * This file contains the prototype for the Chassis class.
 */
#pragma once
#include "okapi/api.hpp"

                 /* ikP, ikI, ikD*/
#define CHASSIS_PID 0.8, 0.0, 0.0

//Motor Ports
#define CHASSIS_MOTORPORT_LEFT_FRONT   15
#define CHASSIS_MOTORPORT_LEFT_BACK    20
#define CHASSIS_MOTORPORT_RIGHT_FRONT  7
#define CHASSIS_MOTORPORT_RIGHT_BACK   17

//Constants
#define ENCODER_UNITS_COUNTS okapi::AbstractMotor::encoderUnits::counts
#define GEARSET_GREEN okapi::AbstractMotor::gearset::green

/**
 * @brief represents a chassis subsystem
 * @author Josh Tenorio, ACP Robotics
 * 
 * The Chassis class is used to control the chassis subsystem. Currently,
 * it contains methods which can be used for both driver control and autonomous.
 */ 
class Chassis {
    private:
        /**
         * The okapi chassis controller used to control the chassis
         */
        okapi::ChassisControllerIntegrated chassis;

        /**
         *  The motion profile controller used to control the chassis
         *  in autonomous
         */
        okapi::AsyncMotionProfileController mpController;

    public:
        /**
         * @brief the constructor for the Chassis class
         *
         * Currently, the constructor takes no arguments. In future iterations,
         * we plan on adding parameters to the constructor to make this class
         * reusable between different robots. For now, "parameters" for the
         * constructor can be edited by simply editing the define statements
         * found at the top of the header file.
         */
        Chassis();

        /**
         * @brief controls the chassis subsystem with a controller
         *
         * Aside from just controlling the chassis subsystem, the "front" of the
         * robot according to the software can be reversed with the multiplier.
         * Such an ability makes it easier for the driver to focus on the shooting
         * mechanism or the cap mechanism - if the driveteam wants to focus on a
         * specific subsystem during a match, then the driver can reverse the chassis
         * as needed.
         *
         * The driver() method should be called in opcontrol(), or some sort of
         * super method (such as the driver() method in the Robot class) which is
         * then called in opcontrol().
         *
         * @param controller The okapi Controller object used to control subsystems
         * @param multiplier the variable used to change the "front" of the robot.
         */
        void driver(okapi::Controller controller, int multiplier);

        /**
         *  @brief Generates a new path from the current position to the target
         *
         *  This method does not save the path generated, and also blocks other
         *  methods from running until the robot has settled.
         *
         *  @param waypoints The list of points to hit on the path
         */
        void moveTo(std::initializer_list<okapi::Point> waypoints);

        /**
         *  @brief Generates a path and saves it to an ID for later use
         *
         * This method computes a trajectory hitting all of the specified points
         * and saves it. This method takes some time (usually less than a second)
         * to generate the aforementioned trajectory.
         *
         * @param iwaypoints The list of points to hit on the path
         * @param ipathID A unique identifier to save the path with
         */
        void generatePath(std::initializer_list<okapi::Point> iwaypoints, const std::string &ipathId);

        /**
         *  @brief Removes a computed path from memory
         *
         *  This method is used to delete a computed path to free up memory space
         *  the path used.
         *
         *  @param ipathID the unique identifier of the path to delete
         */
        void removePath(const std::string &ipathId);

        /**
         *  @brief Executes a generated path with the given path ID
         *
         *  @param ipathId the unique identifier of the path to run
         *  @param ibackwards If true, will follow the profile backwards
         */
        void setTarget(std::string ipathId, bool ibackwards);

        /**
         *  @brief Blocks code from running until motion profile settles
         */
        void waitUntilSettled();

        /**
         *  @brief Turns the robot at a specified angle
         *
         *  This function blocks code from running until the turn is completed.
         *
         *  @param theta The relative angle to turn to
         */
        void turnAngle(okapi::QAngle theta);

};
