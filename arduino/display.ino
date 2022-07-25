//Alien Years | James
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
//const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int a1state = 0;

//big eyes

int blink_delay = 500;
int blink2blink = 7000;
int cnt = 1;

byte top_l[8] ={B00011,B00111,B01111,B01111,B11111,B11111,B11111,B11111};

byte top_r[8] = {B11000,B11100,B11110,B11110,B11111,B11111,B11111,B11111};

byte straight_smile[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11111};

byte smirkr_smile[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00001,B11110};

byte smirkl_smile[8] = {B00000,B00000,B00000,B00000,B00000,B10000,B01000,B00111};

byte happyr_smile[8] = {B00000,B00000,B00001,B00001,B00001,B00001,B00010,B11100};

byte happyl_smile[8] = {B00000,B00000,B10000,B10000,B10000,B10000,B01000,B00111};
  
byte bottom_l[8] = {B11111,B11111,B11111,B11111,B11111,B01111,B00111,B00011};

byte bottom_r[8] = {B11111,B11111,B11111,B11111,B11111,B11110,B11100,B11000};


//blink

byte bottoml_b[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B11111,B11111};

//byte bottomr_b = byte bottom_l

byte *neutral_eyes[]{top_l,top_r,bottom_l,bottom_r,straight_smile,straight_smile,bottoml_b,bottoml_b};

byte *happy_eyes[]{top_l,top_r,bottom_l,bottom_r,smirkl_smile,smirkr_smile,bottoml_b,bottoml_b};

byte *smirk_eyes[]{top_l,top_r,bottom_l,bottom_r,happyl_smile,happyr_smile,bottoml_b,bottoml_b};



//////////////////////////////////expressions////////////////////////////////////////////////////

void setup()
      {
              pinMode(A1,INPUT);
              lcd.begin(16, 2);
              lcd.home();
              Serial.begin(9600);
            }

int counter = 0;
void loop() ////code for image
       {
        while(counter<4){
       
              int x = 0;
              a1state = digitalRead(A1);Serial.println(a1state);
  


              ///normal eyes///
              for(int i=0;i<6;i++)
              {
                if(i<2){lcd.createChar(i,neutral_eyes[i]);lcd.setCursor(i+5,0);lcd.write(i);}
                else if(i>1&&i<6){lcd.createChar(i,neutral_eyes[i]);lcd.setCursor(i+3,1);lcd.write(i);}
              }
              for(int i=0;i<6;i++)
              {
                if(i<2){lcd.createChar(i,neutral_eyes[i]);lcd.setCursor(i+9,0);lcd.write(i);}
                else if(i>1&&i<4){lcd.createChar(i,neutral_eyes[i]);lcd.setCursor(i+7,1);lcd.write(i);}
              }

              ///blink///
              delay(blink2blink); lcd.clear();
          for(int i=4;i<6;i++)
              {
                if(i>3){lcd.createChar(i,neutral_eyes[i]);lcd.setCursor(i+3,1);lcd.write(i);}

              }
              for(int i=6;i<8;i++)
              {
                if(i>5){lcd.createChar(i,neutral_eyes[i]);lcd.setCursor(i-1,1);lcd.write(i);}

              }
          for(int i=6;i<8;i++)
              {
                if(i>5){lcd.createChar(i,neutral_eyes[i]);lcd.setCursor(i+3,1);lcd.write(i);}
                       
              }
            
          delay(blink_delay);lcd.clear();counter+=cnt; Serial.println(counter);
                
           
          }   




           while(counter<8){
       
              int x = 0;
              a1state = digitalRead(A1);Serial.println(a1state);
  


              ///normal eyes///
              for(int i=0;i<6;i++)
              {
                if(i<2){lcd.createChar(i,happy_eyes[i]);lcd.setCursor(i+5,0);lcd.write(i);}
                else if(i>1&&i<6){lcd.createChar(i,happy_eyes[i]);lcd.setCursor(i+3,1);lcd.write(i);}
              }
              for(int i=0;i<6;i++)
              {
                if(i<2){lcd.createChar(i,happy_eyes[i]);lcd.setCursor(i+9,0);lcd.write(i);}
                else if(i>1&&i<4){lcd.createChar(i,happy_eyes[i]);lcd.setCursor(i+7,1);lcd.write(i);}
              }

              ///blink///
              delay(blink2blink); lcd.clear();
          for(int i=4;i<6;i++)
              {
                if(i>3){lcd.createChar(i,happy_eyes[i]);lcd.setCursor(i+3,1);lcd.write(i);}

              }
              for(int i=6;i<8;i++)
              {
                if(i>5){lcd.createChar(i,happy_eyes[i]);lcd.setCursor(i-1,1);lcd.write(i);}

              }
          for(int i=6;i<8;i++)
              {
                if(i>5){lcd.createChar(i,happy_eyes[i]);lcd.setCursor(i+3,1);lcd.write(i);}
                        
              }
            
          delay(blink_delay);lcd.clear(); counter+=cnt;
                
            //else if(a1state==LOW){lcd.clear();}  <<else statement for commented code above, clears code
          }   



          
           while(counter<12){
       
              int x = 0;
              a1state = digitalRead(A1);Serial.println(a1state);
  


              ///normal eyes///
              for(int i=0;i<6;i++)
              {
                if(i<2){lcd.createChar(i,smirk_eyes[i]);lcd.setCursor(i+5,0);lcd.write(i);}
                else if(i>1&&i<6){lcd.createChar(i,smirk_eyes[i]);lcd.setCursor(i+3,1);lcd.write(i);}
              }
              for(int i=0;i<6;i++)
              {
                if(i<2){lcd.createChar(i,smirk_eyes[i]);lcd.setCursor(i+9,0);lcd.write(i);}
                else if(i>1&&i<4){lcd.createChar(i,smirk_eyes[i]);lcd.setCursor(i+7,1);lcd.write(i);}
              }

              ///blink///
              delay(blink2blink); lcd.clear();
          for(int i=4;i<6;i++)
              {
                if(i>3){lcd.createChar(i,smirk_eyes[i]);lcd.setCursor(i+3,1);lcd.write(i);}

              }
              for(int i=6;i<8;i++)
              {
                if(i>5){lcd.createChar(i,smirk_eyes[i]);lcd.setCursor(i-1,1);lcd.write(i);}

              }
          for(int i=6;i<8;i++)
              {
                if(i>5){lcd.createChar(i,smirk_eyes[i]);lcd.setCursor(i+3,1);lcd.write(i);}
                        
              }
            
          delay(blink_delay);lcd.clear(); counter+=cnt;
                
            //else if(a1state==LOW){lcd.clear();}  <<else statement for commented code above, clears code
          }
          counter=0;   
       }
