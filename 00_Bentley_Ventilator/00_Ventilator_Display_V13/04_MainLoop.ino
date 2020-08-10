void loop()
{

 while (StartButton == HIGH)
 {
  Motor();
 }

  while(StartButton == LOW)
 {
  Pos=8;
 // Grapher();
 ReadPots();
 MotorReset();
   PressureSensors();
 }


 //PressureSensors();
 //I2C_Scanner();

}




void MotorReset(){
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
}
