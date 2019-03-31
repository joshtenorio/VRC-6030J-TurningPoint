/**
 * @file jesterOS.cpp
 * @brief Implementation of the JesterOS class
 *
 * @author Josh Tenorio, ACP Robotics
 */
#include "main.h"


lv_obj_t * autoDesc;
lv_obj_t * voltageDisplay;


JesterOS::JesterOS(){
    	

    tabview = lv_tabview_create(lv_scr_act(), NULL);
    lv_obj_align(tabview, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);

    tab1 = lv_tabview_add_tab(tabview, "Auton Selector");
    tab2 = lv_tabview_add_tab(tabview, "Debug Menu");


    main = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(main, "jesterOS v1.0.0");
    lv_obj_align(main, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);


    autoDesc = lv_label_create(tab1, NULL);
    lv_label_set_text(autoDesc, "no auto selected");

    lv_obj_align(autoDesc, NULL, LV_ALIGN_IN_RIGHT_MID, 0, 0);


    static const char * auto_map[] = {"RFLAG", "BFLAG", "\n", "RBACK", "BBACK", "\n", "NOAUTO", ""};


    btnmAuto = lv_btnm_create(tab1, NULL);
    lv_btnm_set_map(btnmAuto, auto_map);
    lv_btnm_set_action(btnmAuto, autonSelect);

    btnAutoRun = lv_btn_create(tab1, NULL);
    label = lv_label_create(btnAutoRun, NULL);
    lv_label_set_text(label, "Run Auton");
    lv_cont_set_fit(btnAutoRun, true, true);
    lv_obj_align(btnAutoRun, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 0, 50);
    lv_obj_set_free_num(btnAutoRun, 1);

    static const char * debug_map[] = {"L Chassis", "R Chassis", "\n", "Flywheel", "Ball Intake", "\n", "DR4B", "Cap Flipper", ""};
    btnmDebug = lv_btnm_create(tab2, NULL);
    lv_btnm_set_map(btnmDebug, debug_map);
    lv_btnm_set_action(btnmDebug, debugSelect);


}


lv_res_t JesterOS::autonSelect(lv_obj_t * btnm, const char *txt){
    if(txt == "RFLAG") autonIdentifier = AUTON_REDFLAG;
    else if(txt == "RBACK") autonIdentifier = AUTON_REDBACK;
    else if(txt == "BFLAG") autonIdentifier = AUTON_BLUEFLAG;
    else if(txt == "BBACK") autonIdentifier = AUTON_BLUEBACK;
    else autonIdentifier = AUTON_NONE;
    updateAuton();
    printf("auton identifer %d\n", autonIdentifier);
    return LV_RES_OK;
}

lv_res_t JesterOS::debugSelect(lv_obj_t *btnm, const char *txt){
    if(txt == "L Chassis") subsystemID = L_CHASSIS_ID;
    else if(txt == "R Chassis") subsystemID = R_CHASSIS_ID;
    else if(txt == "Flywheel") subsystemID = FLYWHEEL_ID;
    else if(txt == "Ball Intake") subsystemID = BALL_INTAKE_ID;
    else if(txt == "DR4B") subsystemID = DR4B_ID;
    else subsystemID = CAP_FLIPPER_ID;
    printf("subsystem id %d\n", subsystemID);
    return LV_RES_OK;
}

void JesterOS::updateAuton(){
    switch(autonIdentifier){
        case AUTON_NONE:
            lv_label_set_text(autoDesc, "no auto");
            break;
        case AUTON_REDFLAG:
            lv_label_set_text(autoDesc, "red flag");
            break;
        case AUTON_REDBACK:
            lv_label_set_text(autoDesc, "red back");
            break;
        case AUTON_BLUEFLAG:
            lv_label_set_text(autoDesc, "blue flag");
            break;
        case AUTON_BLUEBACK:
            lv_label_set_text(autoDesc, "blue back");
            break;
    }
}
