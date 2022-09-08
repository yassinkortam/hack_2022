//Alien Years | Yassin Kortam
#include <Arduino.h>
#include <SPI.h>
#include "BluetoothSerial.h"
#include <ESP32Servo.h>

#include "const.h"
#include "control.h"

BluetoothSerial SerialBT;
Servo sr;
Servo sl;

void setup() {

  Serial.begin(11520); //Start serial 
  SerialBT.begin("rover"); //Start bluetooth 

  //drive motor pins
  pinMode(M1L, OUTPUT);
  pinMode(M1R, OUTPUT);
  pinMode(M2R, OUTPUT);
  pinMode(M2L, OUTPUT);
  pinMode(ER, OUTPUT);
  pinMode(EL, OUTPUT);

  //servo motor pins
  sr.setPeriodHertz(50);
  sl.setPeriodHertz(50);

  sr.attach(SR);
  sl.attach(SL);

}

void troubleshoot(int cmd){ //shows input values etc
    SerialBT.println(cmd);
    SerialBT.print(v);
    SerialBT.print("<");
    SerialBT.print(rad);
    SerialBT.println();
    SerialBT.print("---->");
    SerialBT.print("vr: ");
    SerialBT.print(vr);
    SerialBT.print(", vl: ");
    SerialBT.print(vl);
    SerialBT.print(", t: ");
    SerialBT.print(t);
}

//arrays demonstrate program capability of following a vector path
int velocities[8] = {V_DANCE, -V_DANCE, V_DANCE, -V_DANCE, V_DANCE, -V_DANCE, V_DANCE, -V_DANCE};
double phases[8] = {R_DANCE, 0, R_DANCE, 0, R_DANCE, 0, R_DANCE, 0};
int s_r; //servo arm angle

void dance(){
    v = 0;
    rad = 0;
    control(); //stop the robot

    for (int i=0; i<8; i++){
        if (i%2 == 0){
            s_r = S_MAX;
        }else{
            s_r = 0;
        }
        sr.write(s_r);
        sl.write(s_r);
        delay(100);
        v = velocities[i];
        rad = phases[i];
        control();
        delay(1000);
    }
    v = 0;
    rad = 50;
    control();
    v = 0;
    rad = 0;
    control(); //stop the robot
}

void loop() {

  int cmd = SerialBT.read(); //Read user input

  if (cmd == 119){ //W
      v += V_INC;
      control();
      troubleshoot(cmd);
  }
  if (cmd == 97){ //A
      rad += R_INC;
      troubleshoot(cmd);
      control();
  }
  if (cmd == 115){ //S
      v -= V_INC;
      control();
      troubleshoot(cmd);
  }
  if (cmd == 100){ //D
      rad -= R_INC;
      troubleshoot(cmd);
      control();
  }
  if (cmd == 112){ //P
      rad_sr += S_INC;
      initialize();
      sr.write(rad_sr);
      delay(S_TRANS);
  }
  if (cmd == 108){ //L
      rad_sr -= S_INC;
      initialize();
      sr.write(rad_sr);
      delay(S_TRANS);
  }
  if (cmd == 111){ //O
      rad_sl -= S_INC;
      initialize();
      sl.write(rad_sl);
      delay(S_TRANS);
  }
  if (cmd == 107){ //K
      rad_sl += S_INC;
      initialize();
      sl.write(rad_sl);
      delay(S_TRANS);
  }
  if (cmd == 109){//M
    dance();
  }
}
