void ReadPots(){
  
  mspeed                  = ads.readADC_SingleEnded(0);
  volumeval               = ads.readADC_SingleEnded(1);
  int16_t RatioRaw        = ads.readADC_SingleEnded(3);
  int16_t InhaleDelayRaw  = ads.readADC_SingleEnded(2);
  
  currentpos              = ads2.readADC_SingleEnded(0);

  highpos   = maxvolumepos;
  lowposL   = highpos - (volumeval);
  lowposR    = highpos + (volumeval);
 
  volume = minvolume + ((maxvolume - minvolume)*(volumeval/ADCScale));
  
 MotorSpeed = map(mspeed, 0, ADCScale, 0, MaxSpeed); // Gives the motor speed as a percentage for the pot value

 Ratio = map(RatioRaw, 0, ADCScale, 1, 4);
 

  ExhaleDelay = (InhaleDelay * Ratio);
  InhaleDelay = map(InhaleDelayRaw ,0 ,ADCScale ,500 , 5000);

  DispVol = map(volumeval, 0, ADCScale, minvolume, maxvolume);
  
debugger ();

}
