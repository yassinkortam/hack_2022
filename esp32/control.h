//Alien Years | Yassin Kortam
#ifndef ARDUINO_H
#define ARDUINO_H
#include <Arduino.h>
#endif
#ifndef INITIALIZE_H
#define INITIALIZE_H
#include "initialize.h"
#endif
#ifndef CONST_H
#define CONST_H
#include "const.h"
#endif

void control(); //determines motor output
void turn(); //sets motor output to turn
void forward(); //sets motor output to drive forward 
void reverse(); //sets motor output to drive in reverse
void stop(); //stops motors

void control(){
    initialize(); //update the direction rover should go given latest user inputs
    turn();
    forward();
    reverse();
    stop();
}

void turn(){
    if (rad > 0){
        digitalWrite(M1R, HIGH);
        digitalWrite(M2R, LOW);
        digitalWrite(M1L, LOW);
        digitalWrite(M2L, HIGH);
        analogWrite(ER, V_TURN);
        analogWrite(EL, V_TURN);
        delay(t);
        rad = 0;
    }
    if (rad < 0){
        digitalWrite(M1R, LOW);
        digitalWrite(M2R, HIGH);
        digitalWrite(M1L, HIGH);
        digitalWrite(M2L, LOW);
        analogWrite(ER, V_TURN);
        analogWrite(EL, V_TURN);
        delay(t);
        rad = 0;
    }
}

void forward(){
    if (v > 0){
        digitalWrite(M1R, HIGH);
        digitalWrite(M2R, LOW);
        digitalWrite(M1L, HIGH);
        digitalWrite(M2L, LOW);
        analogWrite(ER, abs(v));
        analogWrite(EL, abs(v));
    }
}

void reverse(){
    if (v < 0){
        digitalWrite(M1R, LOW);
        digitalWrite(M2R, HIGH);
        digitalWrite(M1L, LOW);
        digitalWrite(M2L, HIGH);
        analogWrite(ER, abs(v));
        analogWrite(EL, abs(v));
    }
}

void stop(){
    if (v == 0){
        digitalWrite(M1R, LOW);
        digitalWrite(M2R, LOW);
        digitalWrite(M1L, LOW);
        digitalWrite(M2L, LOW);
        analogWrite(ER, 0);
        analogWrite(EL, 0);
    }
}
