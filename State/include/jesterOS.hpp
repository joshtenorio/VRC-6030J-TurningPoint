/**
 *  @file jesterOS.hpp
 *  @brief Contains prototypes for the JesterOS class
 * 
 * @author Josh Tenorio, ACP Robotics
 * 
 */
#pragma once
#include "main.h"
#include "pros/apix.h"

/**
 * @brief controls the jesterOS utilities
 * @author Josh Tenorio, ACP Robotics
 * 
 * the JesterOS class, built using LVGL, is an autonomous
 * selector and debug menu. In the autonomous selctor,
 * there is a "Run Auton" button to test autonomous in
 * driver control if the competition switch is currently in-
 * use by another team. In the debug menu, the data collected
 * from each subsystem includes data that is not found on the
 * debug screen found in "Devices" that VexOS provides.
 * 
 * DISCLAIMER: This isn't actually a real OS, just a GUI :)
 * 
 * JesterOS is used by calling the constructor in initialize(),
 * and just doing that should suffice. Future plans for JesterOS
 * include rewriting the code to be reusable and adding relevant
 * diagrams and images.
 */
class JesterOS{
    private:
        /**
         * The LVGL tabview object representing jesterOS
         */
        lv_obj_t *tabview;

        /**
         * a LVGL tab object, which is the parent object for autonomous
         * selection
         */
        lv_obj_t *tab1;

        /**
         * a LVGL tab object, which is the parent object for the WIP debug
         * menu
         */
        lv_obj_t *tab2;
        
        /**
         * a LVGL label object, used as a header to display the version number
         * of jesterOS
         */
        lv_obj_t * main;

        /**
         * a LVGL label object, used to describe the Run Auton button
         */
        lv_obj_t * label;
        
        /**
         * a map used to fill the button matrix with autonomous programs to run
         */
        static const char * auto_map[];

        /**
         * the LVGL button matrix used to contain autonomous programs to run
         */
        lv_obj_t * btnmAuto;

        /**
         * the LVGL button used to run autonomous in driver control, useful for
         * testing autonomous when a competition switch isn't available. WIP
         */
        lv_obj_t * btnAutoRun;

        /**
         * a map used to fill the button matrix with a list of subsystems
         */
        static const char * debug_map[];

        /**
         * the LVGL button matrix used to contain a list of subsystems
         */
        lv_obj_t * btnmDebug;

        /**
         * a LVGL label object, will be used for displaying voltage in the debug
         * menu. WIP
         */
        lv_obj_t * labelVolt;
        
    public:

        /**
         * @brief the callback function for selecting an autonomous program to run
         * 
         * This function is used to set the autonIdentifier variable to the
         * selected autonomous program.
         * 
         * @param btnm the pressed button's button matrix
         * @param txt the pressed button's text
         * 
         * @return LV_RES_OK
         */
        static lv_res_t autonSelect(lv_obj_t * btnm, const char *txt);

        /**
         * @brief the callback function for selecting a subsystem to debug
         * 
         * This function is used to set subsystemID to the selected subsystem.
         * 
         * @param btnm the pressed button's button matrix
         * @param txt the pressed button's text
         * 
         * @return LV_RES_OK
         */
        static lv_res_t debugSelect(lv_obj_t *btnm, const char *txt);

        /**
         * @brief the constructor for the JesterOS class
         * 
         * The constructor should be called in initialize().
         */
        JesterOS();

        /**
         * @brief updates the selected autonomous text
         * 
         * This function updates the selected autonomous text, which is
         * displayed to the driveteam.
         */
        static void updateAuton();
    
};