void MotorSpeedDisp ()
{

  if (PlotMenu == 1)
  {
 
  if (BPM != OBPM)
  {
  tft.fillRect(45, 280, 50, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(10, 285); tft.print("BMP"); tft.setTextSize(4);tft.setTextColor(RED);  tft.print(BPM); 
  tft.setCursor(10, 305); tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("b/min");
  }

  if (DispVol != ODispVol)
  {
  tft.fillRect(145, 280, 100, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(110, 285); tft.print("VOL");tft.setTextSize(4);tft.setTextColor(RED); tft.print(DispVol); 
  tft.setCursor(110, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print(" ml");
  }
  /*
  if (InhaleTime!=OInhaleTime)
  {
    int DispInhaleTime = InhaleTime;
  tft.fillRect(285, 280, 100, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(250, 285); tft.print("INH");tft.setTextSize(4);tft.setTextColor(RED); tft.print(DispInhaleTime);
  tft.setCursor(250, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("m.sec");
  }
*/
    if (FlowRate!=OFlowRate)
  {
    int DispFlowRate = FlowRate;
  tft.fillRect(285, 280, 100, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(250, 285); tft.print("FLW");tft.setTextSize(4);tft.setTextColor(RED); tft.print(DispFlowRate);
  tft.setCursor(250, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("ml/sec");
  }

  if (Ratio!=ORatio)
  {
    int DispRatio = Ratio;
  tft.fillRect(435, 280, 50, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(400, 285); tft.print("RTO");tft.setTextSize(4);tft.setTextColor(RED); tft.print(DispRatio);
  tft.setCursor(400, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("1:X");
  }

   if (GraphMenu != OGraphMenu)
   {
   tft.fillRect(140, 10, 190, 25, WHITE);
   tft.setCursor(150, 15); 
   tft.setTextColor(BLACK); tft.setTextSize(2); // set parameters for y axis labels
   tft.print(GraphName);  
   }
   
   tft.fillRect(400, 30, 50, 40, WHITE);  
   tft.setTextColor(BLUE); tft.setTextSize(2);
   tft.setCursor(405, 35); tft.print(LoopTime);
   

  for (int f = 40; f < 280; f=f+48) //FOR PLOTTING HORIZONTAL GRIDS
  {
    tft.drawFastHLine(30, f, 480, GRAY); 
  }

  for (int j = 78; j < 480; j = j+48)//FOR PLOTTING VERTICAL GRIDS
  {
    tft.drawFastVLine(j, 40, 240, GRAY); 
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
  /*
  if (InhaleTime!=OInhaleTime)
  {
    int DispInhaleTime = InhaleTime;
  tft.fillRect(285, 280, 100, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(250, 285); tft.print("INH");tft.setTextSize(4);tft.setTextColor(RED); tft.print(DispInhaleTime);
  tft.setCursor(250, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("m.sec");
  }
*/
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
   
   tft.fillRect(400, 30, 50, 40, WHITE);  
   tft.setTextColor(BLUE); tft.setTextSize(2);
   tft.setCursor(405, 35); tft.print(LoopTime);
   

  for (int f = 40; f < 280; f=f+48) //FOR PLOTTING HORIZONTAL GRIDS
  {
    tft.drawFastHLine(30, f, 480, GRAY); 
  }

  for (int j = 78; j < 480; j = j+48)//FOR PLOTTING VERTICAL GRIDS
  {
    tft.drawFastVLine(j, 40, 240, GRAY); 
  }


}

}
