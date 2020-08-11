void Motor()
{
  unsigned long starttime = millis();

 //////////////////////////////////////////////////////////////

 startbutton = digitalRead(startbuttonpin);
  ReadPots();
  
//THIS WILL SET THE LEFT AND RIGHT LOW POT POSITION OF THE WANTED VOLUME



//BAG FILLING
 while (currentpos < lowposR && currentpos < highpos && startbutton == HIGH){
  motor.rotate(MotorSpeed,CW);
  pos = 1;
  
   Grapher();


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
     Grapher();


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
    Grapher();


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
   Grapher();


  if (currentpos == lowposL){
    motor.stop();
    delay(InhaleDelay);
    break;
  }
 }

 

}
