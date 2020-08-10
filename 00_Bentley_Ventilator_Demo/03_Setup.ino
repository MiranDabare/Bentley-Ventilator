 
void setup()
{
  
     Serial.begin(9600);

    //delay(5000);// run for 5 seconds
    
    uint16_t ID = tft.readID();
    Serial.print("TFT ID = 0x");
    Serial.println(ID, HEX);
    Serial.println("Calibrate for your Touch Panel");
    if (ID == 0xD3D3) ID = 0x9486; // write-only shield
    tft.begin(ID);
    tft.setRotation(1);            //PORTRAIT
    tft.fillScreen(BLACK);

    tft.fillRect(0, 280, 480, 40,WHITE);
    tft.fillRect(140, 10, 190, 25, WHITE);
    tft.setCursor(150, 15); 
    tft.setTextColor(BLACK); tft.setTextSize(2); // set parameters for y axis labels
    tft.print("Controller");  // "0" at center of ya axis

    tft.fillRect(0, 0, 5, 280, BLACK);

  

  tftDrawGraphObjects(); //draw graph objects

  InitialCalculations();

//------------------- MOTOR SETUP-------------------------------\\


/*
 * AT THE START OF THE CODE, THE CONTROLLER WILL FIND WHERE THE CRANK IS. AND THIS WILL MOVE THE CRANK SO THAT ITS VERTICAL. ie THE BELLOW IS FULL!
 */

 

 pinMode(StartButtonPin,  INPUT);
 pinMode(GreenLED,       OUTPUT);
 pinMode(RedLED,     OUTPUT);
 pinMode(ExhaustSolenoidPin, OUTPUT);
 pinMode(Buzzer,     OUTPUT); 
 
 StartButton = digitalRead(StartButtonPin);
  
  
 
   motor.begin();   //starts the motor controller
   ads.begin();
   ReadPots();
   
  // MotorSetup();


  Serial.println("Setup Done");
  
}

void MotorSetup()
{
	while (CurrentVolPos < MinVolPos){ // this returns the piston to the middle max position from the LHS
    //  break;
     motor.rotate(50,CW);
     ReadPots();
     Pos = 99;

      if (CurrentVolPos >= MinVolPos -500 && CurrentVolPos <= MinVolPos +500){
      motor.stop();// stop the motor
      break;      
     }
         
    }
    
   motor.stop();// stop the motor
   
    while (CurrentVolPos > MinVolPos){ // this returns the piston to the middle max position from the RHS\
   // break;
  

      ReadPots();
      
     motor.rotate(50,CCW);
            Pos = 11;

     if (CurrentVolPos >= MinVolPos -500 && CurrentVolPos <= MinVolPos +500){
      motor.stop();// stop the motor
      break;      
     }
         
    }
        motor.stop();// stop the motor
     
}
