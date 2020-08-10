// Serial.println("Im here");
int XGap = 230;
int TextSize = 3;
int NumberSize = 6;

void MotorSpeedDisp()
{


  if (PlotMenu == 1)
  {
    
// tft.fillRect(140, 10, 190, 25, WHITE);
       tft.setCursor(150, 15); 
    tft.setTextColor(MAGENTA); tft.setTextSize(2); // set parameters for y axis labels
    tft.print("VENTILATOR CONTROLLER");  // "0" at center of ya axis
 
  if (BPM != OBPM)
  {
  tft.fillRect(80, 40, 100, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10, 50); tft.print("BMP:"); tft.setTextSize(NumberSize);tft.setTextColor(RED);  tft.print(BPM); 
  tft.setCursor(10, 90); tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("b/min");
  }

  if (DispVol != ODispVol)
  {
  tft.fillRect(80, 110, 150, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10, 120); tft.print("VOL:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispVol); 
  tft.setCursor(10, 160);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print(" ml");
  }

    if (FlowRate!=OFlowRate)
  {
    int DispFlowRate = FlowRate;

  tft.fillRect(80, 190, 180, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10, 190); tft.print("FLW:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispFlowRate);
  tft.setCursor(10, 230);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("ml/sec");
  }

  if (Ratio!=ORatio)
  {
    int DispRatio = Ratio;

  tft.fillRect(80, 260, 60, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10, 260); tft.print("RTO:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispRatio);
  tft.setCursor(10, 300);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("1:X");
  }



   //===================== 2ND COLUMN ============

   if (CycleTime != OCycleTime)
  {
  tft.fillRect(80 + XGap, 40, 200, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10 + XGap, 50); tft.print("CYL:"); tft.setTextSize(5);tft.setTextColor(RED);  tft.print(CycleTime); 
  tft.setCursor(10 + XGap, 90); tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("ms");
  }

  if (MotorSpeed != OMotorSpeed)
  {

   int MPWR = MotorSpeed;
   
  tft.fillRect(80 + XGap, 110, 180, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10 + XGap, 120); tft.print("MPWR:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(MPWR); 
  tft.setCursor(10 + XGap, 160);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("%");
  }
//
//    if (FlowRate!=OFlowRate)
//  {
//    int DispFlowRate = FlowRate;
//
//  tft.fillRect(80 + XGap, 190, 180, 60,WHITE);  
//  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
//  tft.setCursor(10 + XGap, 190); tft.print("FLW:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispFlowRate);
//  tft.setCursor(10 + XGap, 230);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("ml/sec");
//  }
//
//  if (Ratio!=ORatio)
//  {
//    int DispRatio = Ratio;
//
//  tft.fillRect(80 + XGap, 260, 60, 60,WHITE);  
//  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
//  tft.setCursor(10 + XGap, 260); tft.print("RTO:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispRatio);
//  tft.setCursor(10 + XGap, 300);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("1:X");
//  }


   

}


OMotorSpeed=MotorSpeed;
ODispVol=DispVol;
OInhaleTime=InhaleTime;
ORatio=Ratio;
OBPM=BPM;
OFlowRate=FlowRate;

OCycleTime=CycleTime;
OMotorSpeed = MotorSpeed;

OGraphMenu = GraphMenu;
OPlotMenu =PlotMenu;

}

void OneTimeDisplay()
{

   ReadPots();
   tft.fillScreen(WHITE);

   
  tft.fillRect(80, 40, 100, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10, 50); tft.print("BMP:"); tft.setTextSize(NumberSize);tft.setTextColor(RED);  tft.print(BPM); 
  tft.setCursor(10, 90); tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("b/min");
 

  tft.fillRect(80, 110, 180, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10, 120); tft.print("VOL:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispVol); 
  tft.setCursor(10, 160);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print(" ml");

    int DispFlowRate = FlowRate;

  tft.fillRect(80, 190, 180, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10, 190); tft.print("FLW:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispFlowRate);
  tft.setCursor(10, 230);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("ml/sec");

    int DispRatio = Ratio;

  tft.fillRect(80, 260, 60, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10, 260); tft.print("RTO:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispRatio);
  tft.setCursor(10, 300);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("1:X");
  

  
   tft.fillRect(140, 10, 190, 25, WHITE);
   tft.setCursor(150, 15); 
   tft.setTextColor(GREEN); tft.setTextSize(2); // set parameters for y axis labels
   tft.print("VENTILATOR CONTROLLER");  


   //===================== 2ND COLUMN ============

 
  tft.fillRect(80 + XGap, 40, 200, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10 + XGap, 50); tft.print("CYL:"); tft.setTextSize(5);tft.setTextColor(RED);  tft.print(CycleTime); 
  tft.setCursor(10 + XGap, 90); tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("ms");
 
  int MPWR = MotorSpeed;
   
  tft.fillRect(80 + XGap, 110, 180, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10 + XGap, 120); tft.print("MPWR:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(MPWR); 
  tft.setCursor(10 + XGap, 160);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("%");


//  tft.fillRect(80 + XGap, 190, 180, 60,WHITE);  
//  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
//  tft.setCursor(10 + XGap, 190); tft.print("FLW:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispFlowRate);
//  tft.setCursor(10 + XGap, 230);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("ml/sec");
//
//   
//
//  tft.fillRect(80 + XGap, 260, 60, 60,WHITE);  
//  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
//  tft.setCursor(10 + XGap, 260); tft.print("RTO:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispRatio);
//  tft.setCursor(10 + XGap, 300);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("1:X");
// 
//   tft.fillRect(140 + XGap, 10, 190, 25, WHITE);
//   tft.setCursor(150 + XGap, 15); 
//  

}



void Grid()
{
   for (int y = 0; y <= 320; y=y+10) //FOR PLOTTING HORIZONTAL GRIDS
{
  tft.drawFastHLine(0, y, 480, BLACK); 
}

   for (int y = 0; y <= 480; y=y+10) //FOR PLOTTING HORIZONTAL GRIDS
{
  tft.drawFastVLine(y, 0, 480, BLACK); 
}
}
