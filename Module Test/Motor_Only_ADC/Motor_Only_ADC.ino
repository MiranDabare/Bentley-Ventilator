///////////////////////////////////////////////////////////////////////////////////////
//////////////////////// VENTILATOR CONTROLLER CODE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
//  DATE CREATED  : 30 MARCH 2020
//  VERSION       : 3
//  PROGRAMMER    : MIRAN DABARE
///////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////   NOTES   /////////////////////////////////////////////
// * THIS CODE USES THE ON BOARD ADC
// * GET THE BTS760 LIBRARY FROM https://robojax.com/learn/arduino/?vid=robojax_BTS7960_motor_driver 
// * THIS CODE ADDS SUPPORT FOR 20X4 LCD DISPLAY AND 2 POTS TO CONTROL THE INHALE AND EXHALE DELAYS
// * ALSO INCLUDES ADS 1015 ADC
// * BMP180 PRESSURE SENSOR SUPPORT



// THESE ARE MOTOR CONTROLLER LIBRARY HEADERS
#include <Wire.h>
#include <Adafruit_ADS1015.h>

 Adafruit_ADS1115 ads(0x48);  /* Use this for the 16-bit version */
  Adafruit_ADS1115 ads2(0x49); 
 
#define RPWM          3 // define pin 3 for RPWM pin (output)
#define R_EN          4 // define pin 2 for R_EN pin (input)
#define R_IS          5 // define pin 5 for R_IS pin (output)

#define LPWM          6 // define pin 6 for LPWM pin (output)
#define L_EN          7 // define pin 7 for L_EN pin (input)
#define L_IS          8 // define pin 8 for L_IS pin (output)

#define CW            1 //do not change
#define CCW           0 //do not change
#define debug         0 //change to 0 to hide serial monitor debugging infornmation or set to 1 to view

#define speedpot      A0       //PIN FOR SPEED POT
#define volumepot     A1      //PIN FOR VOLUME POT
#define currentpospot A8  //PIN FOR PISTON POT
#define indelaypin    A2
#define exdelaypin    A3

#define startbuttonpin  9

#include <RobojaxBTS7960.h>
RobojaxBTS7960 motor(R_EN,RPWM,R_IS, L_EN,LPWM,L_IS,debug);


   int16_t speedval = 0;          // VARIABLE INITIALIZATION
   int16_t volumeval = 0;        // VARIABLE INITIALIZATION
   int16_t MotorSpeed = 0;       // VARIABLE INITIALIZATION
   int16_t Ratio  = 0;

   float maxvolumepos = 400;  // INSERT THE PISTON BOTTOM MOST ANALOG VALUE
   float minvolumposL = 200;  // INSERT THE PISTON LEFT TOP ANALOG VALUE
   float minvolumposR = 600;  // INSERT THE PISTON RIGHT TOP ANALOG VALUE
   int ADCScale =26830;       // INSERT THE MAX ADC VALUE
   float MaxSpeed   = 80; //INSERT THE MAX RPM OF THE BELLOW
   int16_t InhaleDelay = 500; // INSERT THE INHALATION DELAY
   int16_t ExhaleDelay = 500; // INSERT THE EXHALATION DELAY

   float maxvolume  = 1500;
   float minvolume  = 0;
   float volume     = 0;

   int16_t mspeed     = 0;

   float currentpos = 0;     // VARIABLE INITIALIZATION
   float lowpotval = 0;      // VARIABLE INITIALIZATION

   int startbutton  = LOW;
   int pos = 0; 
   int DispVol = 0;

    float highpos   = 0;
    float lowposL   = 0;
    float lowposR    = 0;
   
   
void setup() {

/*
 * AT THE START OF THE CODE, THE CONTROLLER WILL FIND WHERE THE CRANK IS. AND THIS WILL MOVE THE CRANK SO THAT ITS VERTICAL. ie THE BELLOW IS FULL!
 */

 pinMode(startbutton, INPUT);
 startbutton = digitalRead(startbuttonpin);
  
  
  Serial.begin(9600);

   motor.begin();   //starts the motor controller
   ads.begin();
   ReadPots();
       
   while (currentpos < maxvolumepos){ // this returns the piston to the middle max position from the LHS
      
     motor.rotate(50,CW);
     ReadPots();
     pos = 00;

      if (currentpos == maxvolumepos){
      motor.stop();// stop the motor
      break;      
     }
         
    }
    
   motor.stop();// stop the motor
   
    while (currentpos > maxvolumepos){ // this returns the piston to the middle max position from the RHS

      ReadPots();
      
     motor.rotate(50,CCW);
            pos = 11;

     if (currentpos == maxvolumepos){
      motor.stop();// stop the motor
      break;      
     }
         
    }
    
    motor.stop();// stop the motor
    delay(5000);// run for 5 seconds

     
}

void loop() {

unsigned long starttime = millis();

 //////////////////////////////////////////////////////////////


 startbutton = digitalRead(startbuttonpin);
 
 ReadPots();
  
//THIS WILL SET THE LEFT AND RIGHT LOW POT POSITION OF THE WANTED VOLUME



//BAG FILLING
 while (currentpos < lowposR && currentpos < highpos && startbutton == HIGH){
  motor.rotate(MotorSpeed,CW);
  pos = 1;
  ReadPots();

  if (currentpos == highpos){
    motor.stop();
    delay(ExhaleDelay);
    break;
  }
 }
 
 

//INHALATION ONE
  while (currentpos < lowposR && currentpos > highpos && startbutton == HIGH){
    motor.rotate(MotorSpeed,CW);
    pos = 2;
    ReadPots();

  if (currentpos == lowposR){
    motor.stop();
    delay(InhaleDelay);
    break;
  }
 }


//BAG FILLING
 while (currentpos > lowposL && currentpos > highpos && startbutton == HIGH){
    motor.rotate(MotorSpeed,CCW);
    pos = 3;
    ReadPots();

  if (currentpos == highpos){
    motor.stop();
    delay(ExhaleDelay);
    break;
  }
 }



//INHALATION TWO
  while (currentpos > lowposL && currentpos < highpos && startbutton == HIGH){
    motor.rotate(MotorSpeed,CCW);
    pos = 4;
    ReadPots();

  if (currentpos == lowposL){
    motor.stop();
    delay(InhaleDelay);
    break;
  }
 }
 

 
}// loop ends



//CALL THIS FUCTION WHEN EVER YOU WANT TO READ AND STORE THE LATEST POT READINGS AND DISPLAYS ON THE LCD
void ReadPots(){
  
  mspeed                  = ads.readADC_SingleEnded(0);
  volumeval               = ads.readADC_SingleEnded(1);
  int16_t RatioRaw        = ads.readADC_SingleEnded(2);
  int16_t InhaleDelayRaw  = ads.readADC_SingleEnded(3);
  
  currentpos              = ads2.readADC_SingleEnded(0);

  highpos   = maxvolumepos;
  lowposL   = highpos - (volumeval);
  lowposR    = highpos + (volumeval);
 
  volume = minvolume + ((maxvolume - minvolume)*(volumeval/ADCScale));
  
 MotorSpeed = map(mspeed, 0, ADCScale, 0, MaxSpeed); // Gives the motor speed as a percentage for the pot value

 Ratio = map(RatioRaw, 0, ADCScale, 1, 4);
 

  ExhaleDelay = (InhaleDelay * Ratio);
  InhaleDelay = map(InhaleDelayRaw ,0 ,ADCScale ,500 , 5000);

  DispVol = map(volumeval, 0, ADCScale, 0, 1500);
  
debugger ();

}

//THIS IS JUST TO PRINT THE ADC VALUES FOR DEBUGGING
void debugger (){
  Serial.print ("S: ");       Serial.print(mspeed);     Serial.print (" ");
  Serial.print ("V: ");       Serial.print(volumeval);  Serial.print (" ");
  Serial.print ("Cur Pos: "); Serial.print(currentpos); Serial.print (" ");
  
  Serial.print ("Lmax Pos: ");Serial.print(lowposL);    Serial.print (" ");
  Serial.print ("Rmax Pos: ");Serial.print(lowposR);    Serial.print (" ");
  Serial.print ("High Pos: ");Serial.print(highpos);    Serial.print (" ");
  
  Serial.print ("In: ");      Serial.print(InhaleDelay);  Serial.print (" ");
  Serial.print ("Out: ");     Serial.print(ExhaleDelay);  Serial.print (" ");
  Serial.print ("Ratio: ");     Serial.print(Ratio);      Serial.print (" ");   

  Serial.print ("DVol: ");     Serial.print(DispVol);      Serial.print (" ");
  Serial.print ("DSpd: ");     Serial.print(MotorSpeed);   Serial.println (" ");

      
}
