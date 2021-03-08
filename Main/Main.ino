/*
  Project Name: TM1638
  File: TM1638plus_HELLOWORLD_TEST_Model1.ino
  Description: A demo file library for TM1638 module(LED & KEY). Works on Model 1 and 3
  Carries out series most basic test , "hello world" helo wrld
  Author: Gavin Lyons.
  Created: feb 2020
  URL: https://github.com/gavinlyonsrepo/TM1638plus
*/

#include <TM1638plus.h> //include the library

// GPIO I/O pins on the Arduino connected to strobe, clock, data,
//pick on any I/O you want.
#define  STROBE_TM 4 // strobe = GPIO connected to strobe line of module
#define  CLOCK_TM 2  // clock = GPIO connected to clock line of module
#define  DIO_TM 3 // data = GPIO connected to data line of module
bool high_freq = false; //default false, If using a high freq CPU > ~100 MHZ set to true. 
 
// Constructor object (GPIO STB , GPIO CLOCK , GPIO DIO, use high freq MCU)
TM1638plus tm(STROBE_TM, CLOCK_TM , DIO_TM, high_freq);

void setup()
{
  tm.displayBegin(); 
  
}

void loop()
{
  int temps_restant = changer_temps();
  uint8_t LED1 = 0;
  uint8_t LED2 = 7;
  
  while (temps_restant > 0){
    byte input  = tm.readButtons();
    if (LED1 > 3){
      tm.setLED(LED1, 0);
      LED1=0;
    }
    if (LED2 < 4){
      tm.setLED(LED2, 0);
      LED2=7;    
    }
    if (input == 32){
      temps_restant = changer_temps();
      }
    if (input == 2){
      tm.reset();
      tm.displayText("stop");
      tm.setLEDs(0xFF00);
      delay(50000);
      temps_restant = changer_temps();
      
      }
    temps_restant--;
    tm.displayIntNum(temps_restant, true);
    tm.setLED(LED1, 0);
    tm.setLED(LED2, 0);
    LED1++;
    LED2--;
    tm.setLED(LED1, 1);
    tm.setLED(LED2, 1);
    delay(1000);
    }
  tm.reset();
  tm.displayText("finish");
  delay(50000);
  temps_restant = changer_temps();
  

  
}

int changer_temps()
{
  tm.reset();
  int temps = 60;
  tm.displayIntNum(temps);
  byte button = tm.readButtons();
  int close_var = 0;
  while(close_var == 0 ){
    byte button = tm.readButtons();
    if(button == 128){
      temps++;
      tm.displayIntNum(temps);
      }
    if(button == 64 ){
      temps--;
      tm.displayIntNum(temps);
      }
    if(button == 1){
      close_var = 1;
      }
    }
  return temps;

delay(500000); 
}
