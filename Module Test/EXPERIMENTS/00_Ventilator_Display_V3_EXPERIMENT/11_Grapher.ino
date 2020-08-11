void Grapher()
{
   //go along every point on the x axis and do something, start over when finished

  
    //numb = random(0,1023);
    ReadPots();



    
TSPoint p = ts.getPoint(); //get touch point!
     pinMode(XM, OUTPUT);
     pinMode(YP, OUTPUT);
     p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.height()); //remap p.x and p.y to usable values
     p.y = map(p.y, TS_MINY, TS_MAXY, tft.width(), 0);

     if (p.z > MINPRESSURE && p.z < MAXPRESSURE) //if pressed enough
     {
      Serial.print("p.x: ");Serial.print(p.x); 
      Serial.print("p.y: ");Serial.println(p.y); 
       //!!!!!!!! X SCALE BUTTONS !!!!!!!!
       if ( (p.y >= 110 && p.y <= 350) && (p.x >= 30 && p.x <= 75) ) //if x "-" button pressed!
       {
        delay(70);
         GraphMenu++;
         
         if (GraphMenu > 4)
         {
          GraphMenu = 1;
         }
       }
      }


    //CODE FOR PLOTTING CONTINUOUS LINES!!!!!!!!!!!!
    //Plot "X" value
    tft.drawLine(x_pos - x_scale, y_pos_x_old, x_pos, y_pos_x, GraphColour);
  

    
    //Draw preceding black 'boxes' to erase old plot lines, !!!WEIRD CODE TO COMPENSATE FOR BUTTONS AND COLOR KEY SO 'ERASER' DOESN'T ERASE BUTTONS AND COLOR KEY!!!
    if ((x_pos >= 10) && (x_pos <= 480)) //above x axis
    {
     
      tft.fillRect(x_pos+1, 39, 10, 240, BLACK); //don't compensate for buttons!
      tft.drawFastHLine(10, 270, 480, WHITE); // x axis
      
    }
    
    

    y_pos_x_old = y_pos_x; //set old y pos values to current y pos values 

    //tft.fillRect(230, 30, 50, 24, TFTLCD_BLACK); //clear displayed accel data from LCD
  
   //delay(10);
 
  if (x_pos > 0 && x_pos <10){
    
    tftDrawGraphObjects();
  }


if (GraphMenu == 1)
{
   y_pos_x = map(MotorSpeed,0,101,280,40);
   GraphColour = GREEN;
   GraphName = "Pressure";
}

if (GraphMenu == 2)
{
   y_pos_x = map(DispVol,200,1000,280,40);
   GraphColour = RED;
   GraphName = "Volume";
}

if (GraphMenu == 3)
{
   y_pos_x = map(InhaleDelay,200,5000,280,40);
     GraphColour = MAGENTA;
     GraphName = "Inhale Time";
}

if (GraphMenu == 4)
{
   y_pos_x = map(ExhaleDelay,200,10000,280,40);
   GraphColour = CYAN;
   GraphName = "Exhale Time";
}


  
  MotorSpeedDisp ();
  
  //Completely clear out old plot points/lines
  //tft.fillRect(21, 0, 299, 119, TFTLCD_BLACK); 
  //tft.fillRect(21, 111, 299, 119, TFTLCD_BLACK); 

  x_pos += x_scale;
if (x_pos > 475)
{
  x_pos = 5;
}
OMotorSpeed=MotorSpeed;
ODispVol=DispVol;
OInhaleDelay=InhaleDelay;
ORatio=Ratio;

OGraphMenu = GraphMenu;
}


  
