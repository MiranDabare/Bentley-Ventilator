void Grapher()
{
  for (x_pos = (11 + x_scale); x_pos <= 480; x_pos += x_scale) //go along every point on the x axis and do something, start over when finished

  {
    //numb = random(0,1023);
    ReadPots();
       y_pos_x = map(MotorSpeed,30,80,180,20);
     
     MotorSpeedDisp ();

       
    
TSPoint p = ts.getPoint(); //get touch point!
     pinMode(XM, OUTPUT);
     pinMode(YP, OUTPUT);
     p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.height()); //remap p.x and p.y to usable values
     p.y = map(p.y, TS_MINY, TS_MAXY, tft.width(), 0);

     if (p.z > MINPRESSURE && p.z < MAXPRESSURE) //if pressed enough
     {
       //!!!!!!!! X SCALE BUTTONS !!!!!!!!
       if ( (p.y >= 210 && p.y <= 230) && (p.x >= 0 && p.x <= 20) ) //if x "-" button pressed!
       {
         if (x_scale > 1) 
         {
           x_scale --; //decrement x scale
           delay(70);
           tft.fillRect(256, 21, 6, 8, BLACK); tft.setCursor(254, 21); tft.setTextSize(1); tft.setTextColor(WHITE); tft.print(x_scale); //print the current x scale value
           break; //restart 'for' loop
         }
       }
       if ( (p.y >= 239 && p.y <= 259) && (p.x >= 0 && p.x <= 20) ) //if x "+" button pressed!
       {
         if (x_scale < 6)
         {
           x_scale ++; //increment x scale
           delay(70);
           tft.fillRect(256, 21, 6, 8, BLACK); tft.setCursor(254, 21); tft.setTextSize(1); tft.setTextColor(WHITE); tft.print(x_scale); //print the current x scale value
           break; //restart 'for' loop
         }
       }
       //!!!!!!!! Y SCALE BUTTONS !!!!!!!!
       if ( (p.y >= 266 && p.y <= 286) && (p.x >= 0 && p.x <= 20) ) //if x "-" button pressed!
       {
         if (y_scale > 1) 
         {
           y_scale --; //decrement x scale
           delay(70);
           tft.fillRect(312, 21, 6, 8, BLACK); tft.setCursor(311, 21); tft.setTextSize(1); tft.setTextColor(WHITE); tft.print(y_scale); //print the current y scale value
           break; //restart 'for' loop
         }
       }
       if ( (p.y >= 295 && p.y <= 315) && (p.x >= 0 && p.x <= 20) ) //if x "+" button pressed!
       {
         if (y_scale < 8)
         {
           y_scale ++; //increment x scale
           delay(70);
           tft.fillRect(312, 21, 6, 8, BLACK); tft.setCursor(310, 21); tft.setTextSize(1); tft.setTextColor(WHITE); tft.print(y_scale); //print the current y scale value
           break; //restart 'for' loop
         }
       } 
      }

  
    //CODE FOR PLOTTING CONTINUOUS LINES!!!!!!!!!!!!
    //Plot "X" value
    tft.drawLine(x_pos - x_scale, y_pos_x_old, x_pos, y_pos_x, GREEN);
  

    
    //Draw preceding black 'boxes' to erase old plot lines, !!!WEIRD CODE TO COMPENSATE FOR BUTTONS AND COLOR KEY SO 'ERASER' DOESN'T ERASE BUTTONS AND COLOR KEY!!!
    if ((x_pos >= 198) && (x_pos <= 320)) //above x axis
    {
      tft.fillRect(x_pos+1, 28, 10, 92, BLACK); //compensate for buttons!
    }
    else
    {
      tft.fillRect(x_pos+1, 0, 10, 120, BLACK); //don't compensate for buttons!
    }
    if ((x_pos >= 254) && (x_pos <= 320)) //below x axis
    {
      tft.fillRect(x_pos+1, 121, 10, 88, BLACK);
    }
    else
    {
      tft.fillRect(x_pos+1, 121, 10, 119, BLACK);
    }
    
  
    
    if ( (y_pos_x == 0) )
    {
      tft.drawFastHLine(10, 120, 480, WHITE); // x axis
    }
     
    y_pos_x_old = y_pos_x; //set old y pos values to current y pos values 

    //tft.fillRect(230, 30, 50, 24, TFTLCD_BLACK); //clear displayed accel data from LCD
 

  
   
   //delay(10);
   
  }
  
  tft.fillRect(208, 0, 112, 28, BLACK); //erase XY buttons and any lines behind them
  tft.fillRect(254, 208, 66, 32, BLACK); //erase time and color key and any stray lines behind them
  
 // tftDrawXScaleButtons(); //redraw stuff
 // tftDrawYScaleButtons();
 // tftDrawColorKey();
  tftDrawGraphObjects();
  MotorSpeedDisp ();
  
  //Completely clear out old plot points/lines
  //tft.fillRect(21, 0, 299, 119, TFTLCD_BLACK); 
  //tft.fillRect(21, 111, 299, 119, TFTLCD_BLACK); 
  
}
