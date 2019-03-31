/**
 *  @file motor.c
 */
#include "main.h"

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}
//File-Global Variables
int slewTarget[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //Target speeds for motors

void slewControlTask(void * parameter){
  int slewTmp;
  
  while(1){
    if (isEnabled()) { //Only runs if competition switch is enabled
      for (int i = 0; i < 10; i++) { //Cycle through each motor port
        slewTmp = motorGet(i+1); //returns the last speed sent to the motor
        slewTmp += min(15, abs(slewTarget[i]-slewTmp)) * (slewTarget[i]-slewTmp)/abs(slewTarget[i]-slewTmp);
        motorSet(i+1, slewTmp);
      }
    }
    wait(20);
  }
}

void smartMotorSet(int motor, int cmd){
  slewTarget[motor-1] = cmd;
}

int smartMotorGet(int motor){
  return slewTarget[motor-1];
}
