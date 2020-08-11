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


   float speedval = 0;          // VARIABLE INITIALIZATION
   float volumeval = 0;        // VARIABLE INITIALIZATION
   float motorspeed = 0;       // VARIABLE INITIALIZATION

   float maxvolumepos = 400;  // INSERT THE PISTON BOTTOM MOST ANALOG VALUE
   float minvolumposL = 200;  // INSERT THE PISTON LEFT TOP ANALOG VALUE
   float minvolumposR = 600;  // INSERT THE PISTON RIGHT TOP ANALOG VALUE

   float maxvolume  = 1500;
   float minvolume  = 0;
   float volume     = 0;

   float mspeed     = 0;
   float maxspeed   = 80; //INSERT THE MAX RPM OF THE BELLOW

   float currentpos = 0;     // VARIABLE INITIALIZATION
   float lowpotval = 0;      // VARIABLE INITIALIZATION

   float inhaledelay = 500; // INSERT THE INHALATION DELAY
   float exhaledelay = 500; // INSERT THE EXHALATION DELAY


   int startbutton  = LOW;

    float highpos   = 0;
 float lowposL   = 0;
 float lowposR    = 0;


int pos = 0; 
   
void setup() {

/*
 * AT THE START OF THE CODE, THE CONTROLLER WILL FIND WHERE THE CRANK IS. AND THIS WILL MOVE THE CRANK SO THAT ITS VERTICAL. ie THE BELLOW IS FULL!
 */

 pinMode(startbutton, INPUT);

 speedval   = analogRead(speedpot); //READS THE SPEED POT VALUE
 volumeval  = analogRead(volumepot); //READS THE VOLUME POT VALUE
 currentpos = analogRead(currentpospot); //READS THE PISTON POSITION
 startbutton = digitalRead(startbuttonpin);

  
  
  Serial.begin(9600);

   motor.begin();   //starts the motor controller
     
   while (currentpos < maxvolumepos){ // this returns the piston to the middle max position from the LHS
      
     motor.rotate(50,CW);
     currentpos = analogRead(currentpospot);
     pos = 00;

      if (currentpos == maxvolumepos){
      motor.stop();// stop the motor
      break;      
     }
         
    }
    
   motor.stop();// stop the motor
   
    while (currentpos > maxvolumepos){ // this returns the piston to the middle max position from the RHS
      
     motor.rotate(50,CCW);
     currentpos = analogRead(currentpospot);
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

 mspeed   = analogRead(speedpot); //READS THE SPEED POT VALUE
 volumeval  = analogRead(volumepot); //READS THE VOLUME POT VALUE
 currentpos = analogRead(currentpospot); //READS THE PISTON POSITION

 startbutton = digitalRead(startbuttonpin);

//THIS WILL SET THE LEFT AND RIGHT LOW POT POSITION OF THE WANTED VOLUME




//BAG FILLING
 while (currentpos < lowposR && currentpos < highpos && startbutton == HIGH){

   
  motor.rotate(mspeed,CW);
       pos = 1;
  readpots();

  if (currentpos == highpos){
    motor.stop();
    delay(exhaledelay);
    break;
  }
 }
 
 

//INHALATION ONE
  while (currentpos < lowposR && currentpos > highpos && startbutton == HIGH){
  motor.rotate(mspeed,CW);
       pos = 2;
    readpots();

  if (currentpos == lowposR){
    motor.stop();
    delay(inhaledelay);
    break;
  }
 }


//BAG FILLING
 while (currentpos > lowposL && currentpos > highpos && startbutton == HIGH){
  motor.rotate(mspeed,CCW);
       pos = 3;
    readpots();

  if (currentpos == highpos){
    motor.stop();
    delay(exhaledelay);
    break;
  }
 }



//INHALATION TWO
  while (currentpos > lowposL && currentpos < highpos && startbutton == HIGH){
  motor.rotate(mspeed,CCW);
       pos = 4;
    readpots();

  if (currentpos == lowposL){
    motor.stop();
    delay(inhaledelay);
    break;
  }
 }
 

 
}// loop ends



//CALL THIS FUCTION WHEN EVER YOU WANT TO READ AND STORE THE LATEST POT READINGS AND DISPLAYS ON THE LCD
void readpots(){
 speedval   = analogRead(speedpot); //READS THE SPEED POT VALUE
 volumeval  = analogRead(volumepot); //READS THE VOLUME POT VALUE
 currentpos = analogRead(currentpospot); //READS THE PISTON POSITION
 startbutton = digitalRead(startbuttonpin);

     highpos   = maxvolumepos;
  lowposL   = highpos - (volumeval);
  lowposR    = highpos + (volumeval);
 
  volume = minvolume + ((maxvolume - minvolume)*(volumeval/1023));
  
 mspeed = ((speedval/1023)*maxspeed); // Gives the motor speed as a percentage for the pot value
 

  exhaledelay = analogRead(exdelaypin)*5;
  inhaledelay = analogRead(indelaypin)*5;
  
debugger ();

}

//THIS IS JUST TO PRINT THE ADC VALUES FOR DEBUGGING
void debugger (){
Serial.print ("S: ");
  Serial.print(mspeed); Serial.print (" ");
  Serial.print ("V: ");
  Serial.print(volumeval); Serial.print (" ");
  Serial.print ("Cur Pos: ");
  Serial.print(currentpos); Serial.print (" ");
    Serial.print ("Lmax Pos: ");
  Serial.print(lowposL); Serial.print (" ");
      Serial.print ("Rmax Pos: ");
  Serial.print(lowposR); Serial.print (" ");
        Serial.print ("High Pos: ");
  Serial.print(highpos); Serial.print (" ");
   Serial.print ("In: ");
    Serial.print(inhaledelay); Serial.print (" ");
       Serial.print ("Out: ");
      Serial.print(exhaledelay); Serial.print (" ");
      Serial.println(pos);
}
