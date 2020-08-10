void tftDrawGraphObjects()
{
  //draw the graph objects


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
