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
    
