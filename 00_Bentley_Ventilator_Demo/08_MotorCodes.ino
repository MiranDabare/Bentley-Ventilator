void Motor()
{
 
   //////////////////////////////////////////////////////////////
 StartTime = millis();
 StartButton = digitalRead(StartButtonPin);
 Pos=11;

 //debugger ();
 ReadPots();
 


//THIS WILL SET THE LEFT AND RIGHT LOW POT POSITION OF THE WANTED VOLUME

//BAG FILLING MOTOR TURNING RIGHT CW
  
 // LoopTime =0.0;
   


  while (LoopTime >= 0 && LoopTime <= InhaleTime)
{
  MotorInhale ();
}



while (LoopTime > InhaleTime && LoopTime <= CycleTime) //EXHALING TIME
{
  ReadPots();
  MotorReset();
 
    Pos =4;
   
  }


  if (LoopTime >= CycleTime  )
{
  LoopTime = 0.0;
 
}

}



void MotorInhale ()
{
  
  
 motor.rotate(MotorSpeed,CW); //FILL THE BELLOW
  
  Pos=3;
 ReadPots();
   
//  while (CurrentVolPos >= SetVolL - 500 && CurrentVolPos <= SetVolL + 500)
while (CurrentVolPos >= SetVolL)
  {
    motor.stop();
     Pos = 55;
      ReadPots();

    if (LoopTime > InhaleTime){
      motor.stop();
      break;
    }
     
  }

}

void MotorExhale ()
{
   Pos = 66;
   ReadPots();
  motor.rotate(40,CCW);
  
 while (CurrentVolPos <= MinVolPos + 500 && CurrentVolPos >= MinVolPos - 500)
  {
    ReadPots();
    motor.stop();
  }
  
}
