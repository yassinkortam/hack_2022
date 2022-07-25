//Alien Years | James
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int a1state = 0;

//big eyes

byte top_l[8] ={B00011,B00111,B01111,B01111,B11111,B11111,B11111,B11111};

byte top_r[8] = {B11000,B11100,B11110,B11110,B11111,B11111,B11111,B11111};

byte straight_smile[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11111};

byte bottom_l[8] = {B11111,B11111,B11111,B11111,B11111,B01111,B00111,B00011};

byte bottom_r[8] = {B11111,B11111,B11111,B11111,B11111,B11110,B11100,B11000};


//blink

byte bottoml_b[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B11111,B11111};

//byte bottomr_b = byte bottom_l

byte *neutral_eyes[]{top_l,top_r,bottom_l,bottom_r,straight_smile,straight_smile,bottoml_b,bottoml_b};



//////////////////////////////////expressions////////////////////////////////////////////////////

void setup()
			{
              pinMode(A1,INPUT);
              lcd.begin(16, 2);
              lcd.home();
              Serial.begin(9600);
            }


void loop() ////code for image
		   {
              int x = 0;
              a1state = digitalRead(A1);Serial.println(a1state);
  
  			  /*////////////////////////////////////////////////
              if(a1state==HIGH)
  		      {  <<this makes the image pop up upon button press
              */////////////////////////////////////////////////

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
              delay(2000); lcd.clear();
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
            
  			  delay(100);lcd.clear();
                
            //else if(a1state==LOW){lcd.clear();}  <<else statement for commented code above, clears code
                
            }
