//////////////////////////////////////////////////////////////////////////////////
/*
 *ADD ALL THE REQUIRED HEADERS INTO THIS SECTION
 */



//------------ BMP 180 PRESSURE SENSOR HEADERS -----------------\\
#include <Wire.h>
#include <SFE_BMP180.h>

SFE_BMP180 bmp180;


//---------------- LCD HEADERS ----------------\\
#include <Adafruit_GFX.h> 
#include <TouchScreen.h>
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
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
#define GRAY    0x2965

const int XP = 6, XM = A2, YP = A1, YM = 7; //ID=0x9341
const int TS_LEFT = 893, TS_RT = 136, TS_TOP = 942, TS_BOT = 139;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Adafruit_GFX_Button on_btn, off_btn;

#define TS_MINX 948 //min/max values for touchscreen
#define TS_MINY 173 //!!!THIS IS UNIQUE FOR EVERY TOUCHSCREEN!!!
#define TS_MAXX 118 
#define TS_MAXY 893

#define MINPRESSURE 10 //min/max pressure for touchscreen
#define MAXPRESSURE 1000

// ---------------- ADC HEADERS-------------------------//

#include <Adafruit_ADS1015.h>

 Adafruit_ADS1115 ads(0x48);  /* Use this for the 16-bit version */
 Adafruit_ADS1115 ads2(0x49); 

// ---------------- MOTOR HEADERS-------------------------//

#include <RobojaxBTS7960.h>

 
#define RPWM          12 // define pin 3 for RPWM pin (output)
#define R_EN          23 // define pin 2 for R_EN pin (input)
#define R_IS          25 // define pin 5 for R_IS pin (output)

#define LPWM          13 // define pin 6 for LPWM pin (output)
#define L_EN          27 // define pin 7 for L_EN pin (input)
#define L_IS          29 // define pin 8 for L_IS pin (output)

#define CW            1 //do not change
#define CCW           0 //do not change
#define debug         0 //change to 0 to hide serial monitor debugging infornmation or set to 1 to view

RobojaxBTS7960 motor(R_EN,RPWM,R_IS, L_EN,LPWM,L_IS,debug);


//------------ BMP 180 PRESSURE SENSOR VARIABLES -----------------\\
  char status;
  
  float T;
  float P;
  float AirwayPressure = 0.0;
  float AirwayPressureO = 0.0;
  float PEEPPressure = 0.0;
  
  bool success = false;



//------------ OTHER HEADERS -----------------\\

#define StartButtonPin  46
#define ExhaustSolenoidPin 45
  //------------ LED PINS -------------------------\\

int GreenLED = 26;
int Buzzer = 22;

int RedLED = 28;
unsigned long CycleTime = 0.0;
