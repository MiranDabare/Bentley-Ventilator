//----------Touchscreen Controller Accel XYZ Graphing Program----------\\
//----------------Hyder Hasnain; Started July 27, 2013-----------------\\
//------------------Also records data on microSD card------------------\\
//-------------!!!CODE FOR SD CARD TAKES UP A LOT OF SPACE...----------\\
//-------------...SO IT IS COMMENTED-OUT IN THIS VERSION...------------\\
//---------------...TO MAKE ROOM FOR TOUCHSCREEN CODE!!!---------------\\
//--------!!!IF YOU WANT SD LOGGING, REMOVE TOUCHSCREEN CODE!!!--------\\

//--------ALL THE EXTRA COMMENTED CODE IS EXTRA, IF YOU WANT IT--------\\

//--------------------------------LIBRARIES----------------------------\\


#include <Adafruit_GFX.h> 
#include <TouchScreen.h>



#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <TouchScreen.h>
#define MINPRESSURE 200
#define MAXPRESSURE 1000

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

const int XP = 6, XM = A2, YP = A1, YM = 7; //ID=0x9341
const int TS_LEFT = 907, TS_RT = 136, TS_TOP = 942, TS_BOT = 139;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

Adafruit_GFX_Button on_btn, off_btn;


#define TS_MINX 115 //min/max values for touchscreen
#define TS_MINY 124 //!!!THIS IS UNIQUE FOR EVERY TOUCHSCREEN!!!
#define TS_MAXX 914 
#define TS_MAXY 934

#define MINPRESSURE 10 //min/max pressure for touchscreen
#define MAXPRESSURE 1000


// ---------------- MOTOR HEADERS-------------------------//
// THESE ARE MOTOR CONTROLLER LIBRARY HEADERS
#include <Wire.h>
#include <Adafruit_ADS1015.h>

 Adafruit_ADS1115 ads(0x48);  /* Use this for the 16-bit version */
  Adafruit_ADS1115 ads2(0x49); 
 
#define RPWM          12 // define pin 3 for RPWM pin (output)
#define R_EN          23 // define pin 2 for R_EN pin (input)
#define R_IS          25 // define pin 5 for R_IS pin (output)

#define LPWM          13 // define pin 6 for LPWM pin (output)
#define L_EN          27 // define pin 7 for L_EN pin (input)
#define L_IS          29 // define pin 8 for L_IS pin (output)

#define CW            1 //do not change
#define CCW           0 //do not change
#define debug         0 //change to 0 to hide serial monitor debugging infornmation or set to 1 to view



#define startbuttonpin  26

#include <RobojaxBTS7960.h>
RobojaxBTS7960 motor(R_EN,RPWM,R_IS, L_EN,LPWM,L_IS,debug);


//-------------------------------VARIABLES-----------------------------\\

int x_pos; //position along the graph x axis
//float y_pos_x; //current graph y axis position of X value
float y_pos_x_old = 120; //old y axis position of X value

byte x_scale = 1; //scale of graph x axis, controlled by touchscreen buttons
byte y_scale = 1;
int accel_x; //the XYZ values stored on the SD card

 int y_pos_x = 0;
 
 int numb = 0;

byte SD_CS = 10; //SPI CS pin for SD card

//---------------------------- MOTOR VARIABLES-----------------------------\\

   int16_t speedval = 0;          // VARIABLE INITIALIZATION
   int16_t volumeval = 0;        // VARIABLE INITIALIZATION
   int16_t MotorSpeed = 0;       // VARIABLE INITIALIZATION
   int16_t Ratio  = 0;

   float maxvolumepos = 400;  // INSERT THE PISTON BOTTOM MOST ANALOG VALUE
   float minvolumposL = 200;  // INSERT THE PISTON LEFT TOP ANALOG VALUE
   float minvolumposR = 600;  // INSERT THE PISTON RIGHT TOP ANALOG VALUE
   int ADCScale =26830;       // INSERT THE MAX ADC VALUE
   float MaxSpeed   = 100; //INSERT THE MAX RPM OF THE BELLOW
   int16_t InhaleDelay = 500; // INSERT THE INHALATION DELAY
   int16_t ExhaleDelay = 500; // INSERT THE EXHALATION DELAY

   float maxvolume  = 1500;
   float minvolume  = 0;
   float volume     = 0;

   int16_t mspeed     = 0;

   float currentpos = 0;     // VARIABLE INITIALIZATION
   float lowpotval = 0;      // VARIABLE INITIALIZATION

   int startbutton  = LOW;
   int pos = 0; 
   int DispVol = 0;

    float highpos   = 0;
    float lowposL   = 0;
    float lowposR    = 0;
   
   

//---------------------------------SETUP-------------------------------\\

void setup()
{
  
     Serial.begin(9600);
    uint16_t ID = tft.readID();
    Serial.print("TFT ID = 0x");
    Serial.println(ID, HEX);
    Serial.println("Calibrate for your Touch Panel");
    if (ID == 0xD3D3) ID = 0x9486; // write-only shield
    tft.begin(ID);
    tft.setRotation(3);            //PORTRAIT
    tft.fillScreen(BLACK);

  

  tftDrawGraphObjects(); //draw graph objects
  //tftDrawColorKey();

//------------------- MOTOR SETUP-------------------------------\\


/*
 * AT THE START OF THE CODE, THE CONTROLLER WILL FIND WHERE THE CRANK IS. AND THIS WILL MOVE THE CRANK SO THAT ITS VERTICAL. ie THE BELLOW IS FULL!
 */

 pinMode(startbutton, INPUT);
 startbutton = digitalRead(startbuttonpin);
  
  
 
   motor.begin();   //starts the motor controller
   ads.begin();
   ReadPots();
       
  /*  while (currentpos < maxvolumepos){ // this returns the piston to the middle max position from the LHS
      break;
     motor.rotate(50,CW);
     ReadPots();
     pos = 00;

      if (currentpos == maxvolumepos){
      motor.stop();// stop the motor
      break;      
     }
         
    }
    
   motor.stop();// stop the motor
   
    while (currentpos > maxvolumepos){ // this returns the piston to the middle max position from the RHS\
		break;
	

      ReadPots();
      
     motor.rotate(50,CCW);
            pos = 11;

     if (currentpos == maxvolumepos){
      motor.stop();// stop the motor
      break;      
     }
         
    }
     */
    motor.stop();// stop the motor
    //delay(5000);// run for 5 seconds

  Serial.println("Setup Done");
  
}

//------------------------------MAIN PROGRAM--------------------------\\

void loop()
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

//-------------------------------FUNCTIONS---------------------------\\

void printDigits(int digits)  // utility function for digital clock display: prints preceding colon and leading 0
{
  tft.print(":");
  if(digits < 10)
  tft.print('0');
  tft.print(digits);
}



void tftDrawGraphObjects()
{
  //draw the graph objects
  tft.fillRect(11, 5, x_scale+1, 120,BLACK);
  tft.fillRect(11, 121, x_scale+1, 119, BLACK);
  tft.drawFastVLine(10, 5, 320, WHITE); // y axis
  tft.drawFastHLine(10, 160, 480, WHITE); // x axis
  tft.setTextColor(YELLOW); tft.setTextSize(1); // set parameters for y axis labels
  tft.setCursor(3, 116); tft.print("0");  // "0" at center of ya axis
  tft.setCursor(3, 6); tft.print("1023"); // "+' at top of y axis
  tft.setCursor(3, 228); tft.print("-"); // "-" at bottom of y axis

}

void MotorSpeedDisp ()
{
	tft.fillRect(0, 280, 480, 40,WHITE);
	tft.setTextColor(BLUE); tft.setTextSize(2);
	tft.setCursor(10, 285); tft.print("BMP"); tft.setTextSize(4);tft.setTextColor(RED);  tft.print(MotorSpeed); 
	tft.setCursor(10, 305);	tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("b/min");
	tft.setTextColor(BLUE); tft.setTextSize(2);
	tft.setCursor(110, 285); tft.print("VOL");tft.setTextSize(4);tft.setTextColor(RED); tft.print(DispVol); 
	tft.setCursor(110, 305);	tft.setTextSize(1); tft.setTextColor(BLUE); tft.print(" ml");
	tft.setTextColor(BLUE); tft.setTextSize(2);
	tft.setCursor(250, 285); tft.print("INH");tft.setTextSize(4);tft.setTextColor(RED); tft.print(InhaleDelay);
	tft.setCursor(250, 305);	tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("m.sec");
	tft.setTextColor(BLUE); tft.setTextSize(2);
	tft.setCursor(400, 285); tft.print("RTO");tft.setTextSize(4);tft.setTextColor(RED); tft.print(Ratio);
	tft.setCursor(400, 305);	tft.setTextSize(1); tft.setTextColor(BLUE); tft.print("1:X");
}

void Motor()
{
	unsigned long starttime = millis();

 //////////////////////////////////////////////////////////////

 startbutton = digitalRead(startbuttonpin);
  ReadPots();
  
//THIS WILL SET THE LEFT AND RIGHT LOW POT POSITION OF THE WANTED VOLUME



//BAG FILLING
 while (currentpos < lowposR && currentpos < highpos && startbutton == HIGH){
  motor.rotate(MotorSpeed,CW);
  pos = 1;
  ReadPots();

  if (currentpos == highpos){
    motor.stop();
    delay(ExhaleDelay);
    break;
  }
 }
 
 

//INHALATION ONE
  while (currentpos < lowposR && currentpos > highpos && startbutton == HIGH){
    motor.rotate(MotorSpeed,CW);
    pos = 2;
    ReadPots();

  if (currentpos == lowposR){
    motor.stop();
    delay(InhaleDelay);
    break;
  }
 }


//BAG FILLING
 while (currentpos > lowposL && currentpos > highpos && startbutton == HIGH){
    motor.rotate(MotorSpeed,CCW);
    pos = 3;
    ReadPots();

  if (currentpos == highpos){
    motor.stop();
    delay(ExhaleDelay);
    break;
  }
 }



//INHALATION TWO
  while (currentpos > lowposL && currentpos < highpos && startbutton == HIGH){
    motor.rotate(MotorSpeed,CCW);
    pos = 4;
    ReadPots();

  if (currentpos == lowposL){
    motor.stop();
    delay(InhaleDelay);
    break;
  }
 }
 

}


//CALL THIS FUCTION WHEN EVER YOU WANT TO READ AND STORE THE LATEST POT READINGS AND DISPLAYS ON THE LCD
void ReadPots(){
  
  mspeed                  = ads.readADC_SingleEnded(0);
  volumeval               = ads.readADC_SingleEnded(1);
  int16_t RatioRaw        = ads.readADC_SingleEnded(3);
  int16_t InhaleDelayRaw  = ads.readADC_SingleEnded(2);
  
  currentpos              = ads2.readADC_SingleEnded(0);

  highpos   = maxvolumepos;
  lowposL   = highpos - (volumeval);
  lowposR    = highpos + (volumeval);
 
  volume = minvolume + ((maxvolume - minvolume)*(volumeval/ADCScale));
  
 MotorSpeed = map(mspeed, 0, ADCScale, 0, MaxSpeed); // Gives the motor speed as a percentage for the pot value

 Ratio = map(RatioRaw, 0, ADCScale, 1, 4);
 

  ExhaleDelay = (InhaleDelay * Ratio);
  InhaleDelay = map(InhaleDelayRaw ,0 ,ADCScale ,500 , 5000);

  DispVol = map(volumeval, 0, ADCScale, 0, 1500);
  
debugger ();

}

//THIS IS JUST TO PRINT THE ADC VALUES FOR DEBUGGING
void debugger (){
  Serial.print ("S: ");       Serial.print(mspeed);     Serial.print (" ");
  Serial.print ("V: ");       Serial.print(volumeval);  Serial.print (" ");
  Serial.print ("Cur Pos: "); Serial.print(currentpos); Serial.print (" ");
  
  Serial.print ("Lmax Pos: ");Serial.print(lowposL);    Serial.print (" ");
  Serial.print ("Rmax Pos: ");Serial.print(lowposR);    Serial.print (" ");
  Serial.print ("High Pos: ");Serial.print(highpos);    Serial.print (" ");
  
  Serial.print ("In: ");      Serial.print(InhaleDelay);  Serial.print (" ");
  Serial.print ("Out: ");     Serial.print(ExhaleDelay);  Serial.print (" ");
  Serial.print ("Ratio: ");     Serial.print(Ratio);      Serial.print (" ");   

  Serial.print ("DVol: ");     Serial.print(DispVol);      Serial.print (" ");
  Serial.print ("DSpd: ");     Serial.print(MotorSpeed);   Serial.println (" ");

      
}
    
	
	
	
