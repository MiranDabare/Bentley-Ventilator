void Grapher()
{
   //go along every point on the x axis and do something, start over when finished

   float stime = millis();
  //double cmH2O; 
    
   ReadPots();
   PressureSensors();


    
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
       if ( (p.y >= 120 && p.y <= 350) && (p.x >= 260 && p.x <= 290) ) //if x "-" button pressed!
       {
        delay(70);
         GraphMenu++;
        
         
         if (GraphMenu > 2)
         {
          GraphMenu = 1;
         }

          tftDrawGraphObjects();
       }

       if ( (p.y >= -30 && p.y <= 490) && (p.x >= 22 && p.x <= 55) ) //if x "-" button pressed!
       {
        delay(70);
         PlotMenu++;
        
         
         if (PlotMenu > 2)
         {
          PlotMenu = 1;
         }

          tftDrawGraphObjects();
       }


       
      }


    //CODE FOR PLOTTING CONTINUOUS LINES!!!!!!!!!!!!
    //Plot "X" value
    tft.drawLine(x_pos - x_scale, y_pos_old, x_pos, y_pos, GraphColour);
   
  

    
    //Draw preceding black 'boxes' to erase old plot lines, !!!WEIRD CODE TO COMPENSATE FOR BUTTONS AND COLOR KEY SO 'ERASER' DOESN'T ERASE BUTTONS AND COLOR KEY!!!
    if ((x_pos >= 30) && (x_pos <= 480)) //above x axis
    {
     
      tft.fillRect(x_pos+1, 39, 10, 239, BLACK); //don't compensate for buttons!
           
    }
    
    y_pos_old = y_pos; //set old y pos values to current y pos values 
      
   //delay(10);
 
  if (x_pos > 0 && x_pos <10){
    
    tftDrawGraphObjects();
  }


if (GraphMenu == 1)
{
   y_pos = map(AirwayPressure,0,50,280,40);
   GraphColour = GREEN;
   GraphName = "Pressure(cmH2O)";
}

if (GraphMenu == 2)
{
   y_pos = map(CurrentVolPos, MinVolPos, MaxVolPosR, 280, 40);
   GraphColour = RED;
   GraphName = "Volume(ml)";

}

if (GraphMenu == 3)
{
   y_pos = map(InhaleTime,200,5000,280,40);
     GraphColour = MAGENTA;
     GraphName = "Inhale Time";
}

if (GraphMenu == 4)
{
   y_pos = map(ExhaleTime,200,10000,280,40);
   GraphColour = CYAN;
   GraphName = "Exhale Time";
}
  
  MotorSpeedDisp ();
  
  x_pos += x_scale;
  
if (x_pos >= 480)
{
  x_pos = 25;
    tft.fillRect(0, 30, 30, 239, BLACK);
    tftDrawGraphObjects();
}
OMotorSpeed=MotorSpeed;
ODispVol=DispVol;
OInhaleTime=InhaleTime;
ORatio=Ratio;
OBPM=BPM;
OFlowRate=FlowRate;

OGraphMenu = GraphMenu;
OPlotMenu =PlotMenu;


  Serial.println(1000/(millis() - stime));
  Serial.println(PlotMenu);
}


  
