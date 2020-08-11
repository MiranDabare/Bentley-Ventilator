void setup()
{
  
     Serial.begin(9600);
    uint16_t ID = tft.readID();
    Serial.print("TFT ID = 0x");
    Serial.println(ID, HEX);
    Serial.println("Calibrate for your Touch Panel");
    if (ID == 0xD3D3) ID = 0x9486; // write-only shield
    tft.begin(ID);
    tft.setRotation(3);            //PORTRAIT
    tft.fillScreen(BLACK);

  

  tftDrawGraphObjects(); //draw graph objects
  //tftDrawColorKey();

//------------------- MOTOR SETUP-------------------------------\\


/*
 * AT THE START OF THE CODE, THE CONTROLLER WILL FIND WHERE THE CRANK IS. AND THIS WILL MOVE THE CRANK SO THAT ITS VERTICAL. ie THE BELLOW IS FULL!
 */

 pinMode(startbutton, INPUT);
 startbutton = digitalRead(startbuttonpin);
  
  
 
   motor.begin();   //starts the motor controller
   ads.begin();
   ReadPots();
       
  /*  while (currentpos < maxvolumepos){ // this returns the piston to the middle max position from the LHS
      break;
     motor.rotate(50,CW);
     ReadPots();
     pos = 00;

      if (currentpos == maxvolumepos){
      motor.stop();// stop the motor
      break;      
     }
         
    }
    
   motor.stop();// stop the motor
   
    while (currentpos > maxvolumepos){ // this returns the piston to the middle max position from the RHS\
    break;
  

      ReadPots();
      
     motor.rotate(50,CCW);
            pos = 11;

     if (currentpos == maxvolumepos){
      motor.stop();// stop the motor
      break;      
     }
         
    }
     */
    motor.stop();// stop the motor
    //delay(5000);// run for 5 seconds

  Serial.println("Setup Done");
  
}
