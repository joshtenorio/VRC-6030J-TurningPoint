/**
 * @file library.hpp
 *
 * @brief Collection of global methods, variables, and objects
 *
 * @author Josh Tenorio, ACP Robotics
 */

#include "main.h"

/////////////////////
//Auton Identifiers//
/////////////////////
#define AUTON_NONE 0
#define AUTON_REDFLAG 1
#define AUTON_REDBACK 2
#define AUTON_BLUEFLAG 3
#define AUTON_BLUEBACK 4

/////////////////////////
//Subsystem Identifiers//
/////////////////////////
#define L_CHASSIS_ID 0
#define R_CHASSIS_ID 1
#define FLYWHEEL_ID 2
#define BALL_INTAKE_ID 3
#define DR4B_ID 4
#define CAP_FLIPPER_ID 5

/**
 *  The robot object which interacts with opcontrol() and autonomous()
 */
extern Robot woebot;

/**
 *  The variable used to keep track of the selected autonomous program
 */
extern int autonIdentifier;

/**
 *  The LVGL label object used to indicate selected autonomous program
 */
extern lv_obj_t * autoDesc;

/**
 *  The variable used to identify a subsystem, will be used in debug menu
 */
extern int subsystemID;

/**
 *  The main joystick used to control the robot in driver control period
 */
extern okapi::Controller controller;
