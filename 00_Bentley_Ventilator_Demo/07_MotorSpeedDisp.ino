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
  tft.fillRect(80, 110, 180, 60,WHITE);  
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

   if (BPM != OBPM)
  {
  tft.fillRect(80 + XGap, 40, 100, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10 + XGap, 50); tft.print("BMP:"); tft.setTextSize(NumberSize);tft.setTextColor(RED);  tft.print(BPM); 
  tft.setCursor(10 + XGap, 90); tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("b/min");
  }

  if (DispVol != ODispVol)
  {
  tft.fillRect(80 + XGap, 110, 180, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10 + XGap, 120); tft.print("VOL:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispVol); 
  tft.setCursor(10 + XGap, 160);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print(" ml");
  }

    if (FlowRate!=OFlowRate)
  {
    int DispFlowRate = FlowRate;

  tft.fillRect(80 + XGap, 190, 180, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10 + XGap, 190); tft.print("FLW:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispFlowRate);
  tft.setCursor(10 + XGap, 230);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("ml/sec");
  }

  if (Ratio!=ORatio)
  {
    int DispRatio = Ratio;

  tft.fillRect(80 + XGap, 260, 60, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10 + XGap, 260); tft.print("RTO:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispRatio);
  tft.setCursor(10 + XGap, 300);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("1:X");
  }


   

}

  if (PlotMenu == 2)
  {
 
  if (BPM != OBPM)
  {
  tft.fillRect(45, 280, 50, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(10, 285); tft.print("   "); tft.setTextSize(4);tft.setTextColor(RED);  tft.print(SetPEEPPressure); 
  tft.setCursor(10, 305); tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("b/min");
  }

  if (DispVol != ODispVol)
  {
  tft.fillRect(145, 280, 100, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(110, 285); tft.print("   ");tft.setTextSize(4);tft.setTextColor(RED); tft.print(AirwayPressure); 
  tft.setCursor(110, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print(" ml");
  }

    if (FlowRate!=OFlowRate)
  {
    int DispFlowRate = FlowRate;
  tft.fillRect(285, 280, 100, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(250, 285); tft.print("   ");tft.setTextSize(4);tft.setTextColor(RED); tft.print(DispFlowRate);
  tft.setCursor(250, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("ml/sec");
  }

  if (Ratio!=ORatio)
  {
    int DispRatio = Ratio;
  tft.fillRect(435, 280, 50, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(400, 285); tft.print("   ");tft.setTextSize(4);tft.setTextColor(RED); tft.print(DispRatio);
  tft.setCursor(400, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("1:X");
  }

   if (GraphMenu != OGraphMenu)
   {
   tft.fillRect(140, 10, 190, 25, WHITE);
   tft.setCursor(150, 15); 
   tft.setTextColor(BLACK); tft.setTextSize(2); // set parameters for y axis labels
   tft.print(GraphName);  
   }
   
//   tft.fillRect(400, 30, 50, 40, WHITE);  
//   tft.setTextColor(BLUE); tft.setTextSize(2);
//   tft.setCursor(405, 35); tft.print(LoopTime);
//   

}

    OMotorSpeed=MotorSpeed;
ODispVol=DispVol;
OInhaleTime=InhaleTime;
ORatio=Ratio;
OBPM=BPM;
OFlowRate=FlowRate;

OGraphMenu = GraphMenu;
OPlotMenu =PlotMenu;

}

void OneTimeDisplay()
{
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


  tft.fillRect(80 + XGap, 40, 100, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10 + XGap, 50); tft.print("CYL:"); tft.setTextSize(NumberSize);tft.setTextColor(RED);  tft.print(BPM); 
  tft.setCursor(10 + XGap, 90); tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("b/min");
 
  tft.fillRect(80 + XGap, 110, 180, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10 + XGap, 120); tft.print("VOL:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispVol); 
  tft.setCursor(10 + XGap, 160);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print(" ml");

   

  tft.fillRect(80 + XGap, 190, 180, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10 + XGap, 190); tft.print("FLW:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispFlowRate);
  tft.setCursor(10 + XGap, 230);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("ml/sec");

   

  tft.fillRect(80 + XGap, 260, 60, 60,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(TextSize);
  tft.setCursor(10 + XGap, 260); tft.print("RTO:");tft.setTextSize(NumberSize);tft.setTextColor(RED); tft.print(DispRatio);
  tft.setCursor(10 + XGap, 300);  tft.setTextSize(2); tft.setTextColor(BLUE); tft.print("1:X");
 
   tft.fillRect(140 + XGap, 10, 190, 25, WHITE);
   tft.setCursor(150 + XGap, 15); 
  

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
