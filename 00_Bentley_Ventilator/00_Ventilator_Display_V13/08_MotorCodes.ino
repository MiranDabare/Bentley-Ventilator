void Motor()
{
 
   //////////////////////////////////////////////////////////////
 StartTime = millis();
 StartButton = digitalRead(StartButtonPin);
 Pos=11;
// Grapher();
 //debugger ();
 ReadPots();
   //PressureSensors();


//THIS WILL SET THE LEFT AND RIGHT LOW POT POSITION OF THE WANTED VOLUME

//BAG FILLING MOTOR TURNING RIGHT CW
  
 // LoopTime =0.0;
   






while (LoopTime >= 0 && LoopTime <= InhaleTime)
{
   digitalWrite(ExhaustSolenoidPin, HIGH); // CLOSE THE EXHUAST VAVLE

   
 motor.rotate(50,CCW);
    Pos =4;
     ReadPots();
  while (CurrentVolPos <= MinVolPos + 500 && CurrentVolPos >= MinVolPos - 500)
  {
    motor.stop();
   // delay(1000);
    Pos = 66;
    ReadPots();

    if (LoopTime > InhaleTime){
      break;
    }
  }

    
    
   // Grapher();
   if (StartButton == LOW){
    break;
   }
}


while (LoopTime > InhaleTime && LoopTime <= CycleTime) //EXHALING TIME
{
  motor.rotate(MotorSpeed,CW); //FILL THE BELLOW
  digitalWrite(ExhaustSolenoidPin, LOW); //OPEN THE EXHAUST VALVE TO BREATH OUT

  Pos=3;
   ReadPots();
  
 // Grapher();

  while (CurrentVolPos >= SetVolL - 500 && CurrentVolPos <= SetVolL + 500)
  {
    motor.stop();
     Pos = 55;
      ReadPots();

    if (LoopTime > CycleTime){
      break;
    }
  }

  if (LoopTime >= CycleTime || AirwayPressure < TrigPressure  )
{
  LoopTime = 0.0;
 
}

if (StartButton == LOW){
    break;
   }

}

}
