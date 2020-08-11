void MotorSpeedDisp ()
{
 // tft.fillRect(0, 280, 480, 40,WHITE);



  if (MotorSpeed != OMotorSpeed)
  {
  tft.fillRect(45, 280, 50, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(10, 285); tft.print("BMP"); tft.setTextSize(4);tft.setTextColor(RED);  tft.print(MotorSpeed); 
   tft.setCursor(10, 305); tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("b/min");
  }

  if (DispVol != ODispVol)
  {
     tft.fillRect(145, 280, 100, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(110, 285); tft.print("VOL");tft.setTextSize(4);tft.setTextColor(RED); tft.print(DispVol); 
  tft.setCursor(110, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print(" ml");
  }
  
  if (InhaleDelay!=OInhaleDelay)
  {
    tft.fillRect(285, 280, 100, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(250, 285); tft.print("INH");tft.setTextSize(4);tft.setTextColor(RED); tft.print(InhaleDelay);
  tft.setCursor(250, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("m.sec");
  }

  if (Ratio!=ORatio)
  {
    tft.fillRect(435, 280, 50, 40,WHITE);  
  tft.setTextColor(BLUE); tft.setTextSize(2);
  tft.setCursor(400, 285); tft.print("RTO");tft.setTextSize(4);tft.setTextColor(RED); tft.print(Ratio);
  tft.setCursor(400, 305);  tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("1:X");
  }

     if (GraphMenu != OGraphMenu)
     {
     tft.fillRect(140, 10, 180, 25, WHITE);
     tft.setCursor(150, 15); 
   tft.setTextColor(BLACK); tft.setTextSize(2); // set parameters for y axis labels
tft.print(GraphName);  // "0" at center of ya axis
     }
}
