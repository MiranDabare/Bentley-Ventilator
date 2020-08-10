void Alarms()
{

  MotorStarted ();
  MotorStopped ();
}


void MotorStarted ()
{

        if (StartButton==HIGH && OStartButton!=StartButton)
      {
            tft.fillRect(60,100, 350,70, WHITE);
  tft.fillRect(70,110, 330, 50, BLUE);

    tft.setTextColor(WHITE); tft.setTextSize(4); // set parameters for y axis labels
  tft.setCursor(85, 120); tft.print("MOTOR STARTED!");  // "0" at center of ya axis
  
        delay(1000);
        OStartButton=HIGH;
       OneTimeDisplay();
      }


  
}

void MotorStopped ()
{

         if (StartButton==LOW && OStartButton!=StartButton)
      {
            tft.fillRect(60,100, 350,70, WHITE);
  tft.fillRect(70,110, 330, 50, BLUE);

    tft.setTextColor(WHITE); tft.setTextSize(4); // set parameters for y axis labels
  tft.setCursor(85, 120); tft.print("MOTOR STOPPED!");  // "0" at center of ya axis
  
        delay(1000);
        OStartButton=LOW;
            OneTimeDisplay();
      }
  
}
