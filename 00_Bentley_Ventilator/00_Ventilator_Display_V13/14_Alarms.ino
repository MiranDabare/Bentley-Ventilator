void Alarms(){

  HighPressureError();
  LowPressureError();
  MotorStarted ();
  MotorStopped ();

         if ((cleared == 2 && AirwayPressureO > LowPressureWarn)||(cleared == 1 && AirwayPressure < HighPressureWarn))
        {        
          tft.fillRect(60,100, 350,70, BLACK);
          cleared = 0;
        
        }


  
}


void HighPressureError()
{

if (AirwayPressure > HighPressureWarn)
  {
    digitalWrite(RedLED, HIGH);
    digitalWrite(Buzzer, HIGH);
     tft.fillRect(60,100, 350,70, YELLOW);
  tft.fillRect(70,110, 330, 50, RED);

    tft.setTextColor(WHITE); tft.setTextSize(4); // set parameters for y axis labels
  tft.setCursor(85, 120); tft.print("HIGH PRESSURE!");  // "0" at center of ya axis

  digitalWrite(RedLED, LOW);
  
    cleared = 1;
    
      }
      else
      {
        digitalWrite(RedLED, LOW);
        digitalWrite(Buzzer, LOW);
       
      }
      
}

void LowPressureError()
{

if (AirwayPressure < LowPressureWarn)
  {
    digitalWrite(RedLED, HIGH);
    digitalWrite(Buzzer, HIGH);
    
      tft.fillRect(60,100, 350,70, YELLOW);
  tft.fillRect(70,110, 330, 50, RED);

    tft.setTextColor(WHITE); tft.setTextSize(4); // set parameters for y axis labels
  tft.setCursor(85, 120); tft.print("LOW PRESSURE!");  // "0" at center of ya axis
  
digitalWrite(RedLED, LOW);

    cleared = 2;
    
      }
      else
      {
        digitalWrite(RedLED, LOW);
        digitalWrite(Buzzer, LOW);
       
      }


  

  
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
        tft.fillRect(60,100, 350,70, BLACK);
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
         tft.fillRect(60,100, 350,70, BLACK);
      }
  
}

void PEEPPressureWarn()
{
  if (AirwayPressure < SetPEEPPressure)
  {
    
  }
}
