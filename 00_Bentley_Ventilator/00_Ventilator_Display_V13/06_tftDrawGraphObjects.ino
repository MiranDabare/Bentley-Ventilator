void tftDrawGraphObjects()
{
  //draw the graph objects

  tft.drawFastVLine(30, 15, 320, WHITE); // y axis
  tft.drawFastHLine(30, 278, 480, WHITE); // x axis
  tft.setTextColor(YELLOW); tft.setTextSize(1); // set parameters for y axis labels

    tft.fillRect(0, 280, 480, 40, WHITE);

 
  tft.setTextColor(YELLOW); tft.setTextSize(2); // set parameters for y axis labels
  tft.fillRect(0, 40, 30, 240, BLACK);

  for (int f = 40; f < 280; f=f+48) //FOR PLOTTING HORIZONTAL GRIDS
{
  tft.drawFastHLine(30, f, 480, GRAY); 

   if (GraphMenu ==1)
  { 
    
  tft.setCursor(3, f); tft.print((50 - (10*(f-40)/48)),1);  // "0" at center of ya axis
  }

  if (GraphMenu ==2)
  { 
       
    tft.setTextSize(2);
  tft.setCursor(3, f); tft.print((10 - (2*(f-40)/48)));  // "0" at center of ya axis
  tft.setTextSize(1); tft.print("00");
  }

}

tft.setTextSize(2); tft.setCursor(3, 265); tft.print("0");

  for (int j = 78; j < 480; j = j+48)//FOR PLOTTING VERTICAL GRIDS
  {
    tft.drawFastVLine(j, 40, 240, GRAY); 
        
  }

if (PlotMenu == 1)
{
  tft.fillRect(45, 280, 50, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(10, 285); tft.print("BMP"); tft.setTextSize(4); tft.setTextColor(RED);  tft.print(BPM); 
  tft.setCursor(10, 305); tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("b/min");
  

 
  tft.fillRect(145, 280, 100, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(110, 285); tft.print("VOL");tft.setTextSize(4);tft.setTextColor(RED); tft.print(DispVol); 
  tft.setCursor(110, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print(" ml");

 int DispFlowRate = FlowRate;
  tft.fillRect(285, 280, 100, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(250, 285); tft.print("FLW");tft.setTextSize(4);tft.setTextColor(RED); tft.print(DispFlowRate);
  tft.setCursor(250, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("ml/sec");
  
  int DispRatio = Ratio;
  tft.fillRect(435, 280, 50, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(400, 285); tft.print("RTO");tft.setTextSize(4);tft.setTextColor(RED); tft.print(DispRatio);
  tft.setCursor(400, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("1:X");

 }

if (PlotMenu == 2)
{

  int DisSetPEEPPressure = SetPEEPPressure;
  
  tft.fillRect(45, 280, 50, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(10, 285); tft.print("PEEP"); tft.setTextSize(4);tft.setTextColor(RED);  tft.print(DisSetPEEPPressure); 
  tft.setCursor(10, 305); tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("cmH2O");
  

 
  tft.fillRect(145, 280, 100, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(110, 285); tft.print("Press");tft.setTextSize(4); tft.setTextColor(RED); tft.print(AirwayPressure); 
  tft.setCursor(110, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print(" ml");

 
  tft.fillRect(285, 280, 100, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(250, 285); tft.print("QWR");tft.setTextSize(4);
  tft.setCursor(250, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("ml/sec");
  
 
  tft.fillRect(435, 280, 50, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(400, 285); tft.print("WTF");tft.setTextSize(4);
  tft.setCursor(400, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("1:X");
 
}
 
}
