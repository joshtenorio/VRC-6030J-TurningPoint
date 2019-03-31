#pragma once
/** @file autonred.h
*  @brief Our autonomi for the red side 
*
*  This file contains the autonomi used for the autonomous period, specifically for the
*  red side. Once we have a dedicated autonomous for programming skills, that autonomous
*  will be placed here.
*
*/

/**
 *  @brief a 3 point autonomous on the flag side
 *
 *  The robot will first run the flywheel, shooting the top flag. Then, it will go forward
 *  and toggle the low flag.
 */
void autonRedFlag();

/**
 *  @brief a 4 point autonomous on the flag side
 *
 *  The robot will go towards the tilted red cap, knock the ball (low scoring the cap in
 *  the process) and go towards the low flag, and toggle it for red. Then, it will go
 *  towards the blue cap and flip it, then toggle the middle flag. [DEPRECATED]
 */
void autonRedFlagCapOnly();

/**
 * @brief a 2 point autonomous on the far side
 * 
 * The robot will run the flywheel, and shoot the top flag.
 */
void autonRedBack();

/**
 * @brief a 6 point autonomous on the flag side
 * 
 * The robot will start the flywheel, then grab the ball from the tilted cap and go backwards.
 * Next, it will shoot the top flag, then go forward and shoot the middle flag, and toggle the
 * low flag.
 */
void autonRedUltraFlag();