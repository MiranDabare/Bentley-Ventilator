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
   int ADCScale =26705;       // INSERT THE MAX ADC VALUE
   float MaxSpeed   = 100; //INSERT THE MAX RPM OF THE BELLOW
   int16_t InhaleDelay = 500; // INSERT THE INHALATION DELAY
   int16_t ExhaleDelay = 500; // INSERT THE EXHALATION DELAY

   float maxvolume  = 1000;
   float minvolume  = 500;
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
