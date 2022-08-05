//Alien Years | Yassin Kortam
#ifndef ARDUINO_H
#define ARDUINO_H
#include <Arduino.h>
#endif
#ifndef CONST_H
#define CONST_H
#include "const.h"
#endif

int v=0; //user input for analog output forward velocity
double rad=0; //user input for turn angle radians 

int vl; //analog output for left velocity
int vr; //analog output for right velocity
int t; //turn time millis

int rad_sr; //right servo angle
int rad_sl; //left servo angle

void initialize(){
    if (abs(v) > 240){
        if (v > 0){
            v = V_MAX;
        }
        else{
            v = -V_MAX;
        }
    }
    t = abs(rad/W)*1000;

    if (rad_sr > S_MAX){
        rad_sr = S_MAX;
    }
    if (rad_sr < 0){
        rad_sr = 0;
    }
    if (rad_sl > S_MAX){
        rad_sl = S_MAX;
    }
    if (rad_sl < 0){
        rad_sl = 0;
    }
} 
    

   
