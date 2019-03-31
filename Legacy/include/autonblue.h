
/** @file autonblue.h
*  @brief Our autonomi for the blue side
*
*  This file contains the autonomi used for the autonomous period, specifically for the
*  blue side. 
*
*/
#pragma once
/**
*  @brief a 3 point autonomous on the flag side
*
*  The robot will run the flywheel, shooting the top flag, then drive forward and toggle
*  the low flag.
*/
void autonBlueFlag();

/**
 * @brief a 2 point autonomous on the far side
 * 
 * The robot will run the flywheel, and shoot the top flag.
 */
void autonBlueBack();


