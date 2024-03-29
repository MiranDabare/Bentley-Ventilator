void ReadPots(){


   int ADCScale = 26000;    
   
  StartButton = digitalRead(StartButtonPin);

  BPMRaw                  = ads.readADC_SingleEnded(2);
  SetVolRaw               = ads.readADC_SingleEnded(1);
  int16_t RatioRaw        = ads.readADC_SingleEnded(3);
  int16_t SetFlowRateRaw  = ads.readADC_SingleEnded(0);

  
  CurrentVolPos             = ads2.readADC_SingleEnded(0);


  SetVolR = map(SetVolRaw, 0, ADCScale,  MaxVolPosR, MinVolPos);
  SetVolL = map(SetVolRaw, 0, ADCScale, MinVolPos, MaxVolPosL);



//--------MAPPING ------------\\

  BPM         = map(BPMRaw,         0, ADCScale, 5 ,         15);                           // BREATHS PER MINUTE SETTING
  Ratio       = map(RatioRaw,       0, ADCScale,  1,          3);                       // EXHALE RATIO
  FlowRate    = map(SetFlowRateRaw, 0, ADCScale, 0, MaxMotorFlowRate); //FLOWRATE IN ML/S


 CycleTime = (60.0/BPM)*1000;
  

   InhaleTime = CycleTime/(1+Ratio);
         
  DispVol     = map(SetVolRaw,      0, ADCScale,  0, BellowCapacity); //(X, 0, 26000, 0ml, 1000ml)// SET VOLUME IN MILLITERS
  ExhaleTime = (InhaleTime * Ratio);
  
 // FlowRate    = (DispVol/InhaleTime)*1000; //FLOWRATE IN ML/S

  MotorSpeed  = map(FlowRate,  0, MaxMotorFlowRate,      30,        100);   // THIS WILL GET THE MOTOR PERCENTAGE (0 RPM -> 0 ml/s, 80 RPM -> 2666.66ml/s) Calculated for 1000ml bellow
   
  


if (StartButton == HIGH)
{
  digitalWrite(GreenLED, HIGH);
}

if (StartButton == LOW)
{
   digitalWrite(GreenLED, LOW);
}

//debugger ();

   LoopTime = (millis() - StartTime);

   
}

void ReadPositionOnly()
{
  StartButton = digitalRead(StartButtonPin);
  CurrentVolPos             = ads2.readADC_SingleEnded(0);
  
   LoopTime = (millis() - StartTime);
   debugger ();
}




 
