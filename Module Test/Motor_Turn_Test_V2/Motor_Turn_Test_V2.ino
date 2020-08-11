/*
* This is the Arduino code BTS7960 DC motor Driver 
Using this code you can control a motor to rotate in both direction Clockwise(CW) 
and Counter-clockwise(CCW)
 
// Written by Ahmad Shamshiri for Robojax.com on 
// on June 22, 2019 at 14:08 in Ajax, Ontario, Canada

If you found this tutorial helpful, please support me so I can continue creating content like this. You can support me on Patreon (
http://bit.ly/2ZnITLz

or make donation using PayPal http://bit.ly/rj-paypal

* BTS7960B
 * Code is available at http://robojax.com/learn/arduino

 * This code is "AS IS" without warranty or liability. Free to be used as long as you keep this note intact.* 
 * This code has been download from Robojax.com
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>. 

*/

// 
/*
#define RPWM 12 // define pin 3 for RPWM pin (output)
#define R_EN 23 // define pin 2 for R_EN pin (input)
#define R_IS 25 // define pin 5 for R_IS pin (output)

#define LPWM 13 // define pin 6 for LPWM pin (output)
#define L_EN 27 // define pin 7 for L_EN pin (input)
#define L_IS 29 // define pin 8 for L_IS pin (output)

*/

#define RPWM 12 // define pin 3 for RPWM pin (output)
#define R_EN 23 // define pin 2 for R_EN pin (input)
#define R_IS 25 // define pin 5 for R_IS pin (output)

#define LPWM 13 // define pin 6 for LPWM pin (output)
#define L_EN 27 // define pin 7 for L_EN pin (input)
#define L_IS 29 // define pin 8 for L_IS pin (output)

#define CW 1 //do not change
#define CCW 0 //do not change
#define debug 0 //change to 0 to hide serial monitor debugging infornmation or set to 1 to view


#define speedpot      A0       //PIN FOR SPEED POT

#include <RobojaxBTS7960.h>

#include <Wire.h>
#include <Adafruit_ADS1015.h>

 Adafruit_ADS1115 ads(0x48);  /* Use this for the 16-bit version */
 Adafruit_ADS1115 ads2(0x49); 

RobojaxBTS7960 motor(R_EN,RPWM,R_IS, L_EN,LPWM,L_IS,debug);


   int speedval = 0;          // VARIABLE INITIALIZAT

void setup() {
  // BTS7960 Motor Control Code by Robojax.com 20190622
  Serial.begin(9600);// setup Serial Monitor to display information

 ads.begin();
  ads2.begin();
   motor.begin();
   
    // BTS7960 Motor Control Code by Robojax.com 20190622 
}

void loop() {
    int16_t adc0, adc1, adc2, adc3;

  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads2.readADC_SingleEnded(0);
//  adc2 = ads.readADC_SingleEnded(2);
//  adc3 = ads.readADC_SingleEnded(3);


  
   // BTS7960 Motor Control Code by Robojax.com 20190622 

  // float val = analogRead(speedpot);

   if (adc0 > 13415){
    
    adc0 = ads.readADC_SingleEnded(0);
   
     speedval = map(adc0,13415,26830,0,50) ;
     
        motor.rotate(speedval,CCW);

        
    Serial.print(speedval);
    Serial.print(" ");
        Serial.print("CCW");
    Serial.print(" ");
      Serial.print (adc0);
      Serial.print(" ");
      Serial.println (adc1);
   }

   if (adc0 < 13415){
    
    adc0 = ads.readADC_SingleEnded(0);
   
     speedval = map(adc0,13415,0,0,50) ;
     
        motor.rotate(speedval,CW);

        
    Serial.print(speedval);
    Serial.print(" ");
            Serial.print("CW");
    Serial.print(" ");
      Serial.print (adc0);
      Serial.print(" ");
      Serial.print (adc1);Serial.println(" ");
   }
   

  
   

//    Serial.print(speedval);
//    Serial.print(" ");
//      Serial.print (adc0);
//      Serial.print(" ");
//      Serial.println (adc1);
//     
 // BTS7960 Motor Control Code by Robojax.com 20190622  
}// loop ends
