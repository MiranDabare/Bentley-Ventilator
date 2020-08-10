//THIS IS JUST TO PRINT THE ADC VALUES FOR DEBUGGING
void debugger (){
//  Serial.print ("BPM: ");       Serial.print(BPM);     Serial.print (" ");
//  Serial.print ("Ratio: ");     Serial.print(Ratio);      Serial.print (" ");  
    
 // Serial.print ("DisVol: ");       Serial.print(DispVol);  Serial.print (" ");
  Serial.print ("Cur Pos: "); Serial.print(CurrentVolPos); Serial.print (" ");
  //Serial.print ("SetVolR: ");      Serial.print(SetVolR);  Serial.print (" ");
  Serial.print ("SetVolL: ");     Serial.print(SetVolL);  Serial.print (" ");
  
 // Serial.print ("Lmax Pos: ");Serial.print(lowposL);    Serial.print (" ");
 // Serial.print ("Rmax Pos: ");Serial.print(lowposR);    Serial.print (" ");
 // Serial.print ("High Pos: ");Serial.print(highpos);    Serial.print (" ");
  
//  Serial.print ("InTim: ");      Serial.print(InhaleTime);  Serial.print (" ");
//  Serial.print ("Out: ");     Serial.print(ExhaleTime);  Serial.print (" ");
// 
 Serial.print ("DSpd: ");     Serial.print(MotorSpeed);   Serial.print (" ");
// Serial.print ("FlowRate: ");     Serial.print(FlowRate);   Serial.print (" ");
//  
//   Serial.print ("Pressure: ");     Serial.print( AirwayPressure);      Serial.print (" ");
// 
   Serial.print ("Cycle Time: ");     Serial.print(CycleTime);      Serial.print (" ");
   Serial.print ("Loop Time: ");     Serial.print(LoopTime);      Serial.print (" ");
   Serial.print ("Inhale Time: ");     Serial.print(InhaleTime);      Serial.print (" ");
  
//  Serial.print ("Swtch: ");     Serial.print(StartButton);   Serial.print (" ");
  Serial.print ("Code Pos: ");     Serial.print(Pos);   Serial.println (" ");

      
}
    
