void loop()
{
Alarms();
 
 
 while (StartButton == HIGH)
 {
  Motor();

 }
Alarms();
  while(StartButton == LOW)
 {
 
  Pos=8;
 
 ReadPots();
 MotorReset();
  MotorSpeedDisp();
//  debugger ();
// Grid();


 }


 
// //I2C_Scanner();

}




void MotorReset(){
    while (CurrentVolPos < MinVolPos - 500){ // this returns the piston to the middle max position from the LHS
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
   
    while (CurrentVolPos > MinVolPos + 500){ // this returns the piston to the middle max position from the RHS\
   // break;
  

      ReadPots();

      
     motor.rotate(50,CCW);
            Pos = 15;

     if (CurrentVolPos >= MinVolPos -500 && CurrentVolPos <= MinVolPos +500){
      motor.stop();// stop the motor
      break;      
     }
         
    }
}
