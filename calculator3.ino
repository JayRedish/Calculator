#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
#include <Wire.h>
#include "Adafruit_Trellis.h"
#define MOMENTARY 0
#define LATCHING 1
#define MODE MOMENTARY 
Adafruit_Trellis matrix0 = Adafruit_Trellis();
Adafruit_TrellisSet trellis =  Adafruit_TrellisSet(&matrix0);
#define NUMTRELLIS 1
#define numKeys (NUMTRELLIS * 16);
#define INTPIN A2
void setup() 
{
  Serial.begin(9600);
  Serial.println("Trellis Demo");
  pinMode(INTPIN, INPUT);
  digitalWrite(INTPIN, HIGH);
  trellis.begin(0x70);
  Serial.println("0");
  int i=0; 
  for (i==0; i<16; i++) 
  Serial.println("1");
  {
    trellis.setLED(i);
     Serial.println("8");
    trellis.writeDisplay(); 
     Serial.println("9");   
    delay(50);
  }
  Serial.println("2");
  for (i==0; i<16; i++) 
  {
    trellis.clrLED(i);
    trellis.writeDisplay();    
    delay(50);
   }
   Serial.println("3");
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() 
{
  delay(30);
  lcd.setCursor(0,1);
  lcd.print(millis()/1000);
  Serial.println("4");
  
  if (MODE == MOMENTARY) 
  {  Serial.println("5");

    if (trellis.readSwitches()) 
    {  Serial.println("6");
      int i=0;
      for (i==0; i<16; i++) 
      {
	if (trellis.justPressed(i)) 
        {
	  Serial.print("v"); Serial.println(i);
          lcd.print("Hello World");
          delay(1000);
          lcd.clear();
	  trellis.setLED(i);
	} 
	if (trellis.justReleased(i)) 
        {
	  Serial.print("^"); Serial.println(i);
	  trellis.clrLED(i);
	}
      }
      trellis.writeDisplay();
    }
  }
  //Dave's testing git
   if (MODE == LATCHING) 
   {
    if (trellis.readSwitches()) 
    {
      int i=0;
      for (i==0; i<16; i++) 
      {
	if (trellis.justPressed(i)) 
        {
	  Serial.print("v"); Serial.println(i);
	  if (trellis.isLED(i))
          {
	    trellis.clrLED(i);
          }
	  else
          {
	    trellis.setLED(i);
          }
        } 
      }
      trellis.writeDisplay();
    }
  }
}
