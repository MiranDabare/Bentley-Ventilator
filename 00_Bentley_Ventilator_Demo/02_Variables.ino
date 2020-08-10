//-------------------------------UPDATABLE VARIABLES-----------------------------\\

   float MinVolPos = 17500;  // INSERT THE PISTON BOTTOM MOST ANALOG VALUE

    float CircleDiff = 3200;
   float MaxVolPosL = MinVolPos + CircleDiff;  // INSERT THE PISTON LEFT TOP ANALOG VALUE
   float MaxVolPosR = MinVolPos - CircleDiff;  // INSERT THE PISTON RIGHT TOP ANALOG VALUE

  

   float    MaxSpeed   = 100.0; //INSERT THE MAX RPM OF THE BELLOW
   float InhaleTime = 500.0; // INSERT THE INHALATION DELAY
   float ExhaleTime = 500.0; // INSERT THE EXHALATION DELAY

   float HighPressureWarn = 30;
   float LowPressureWarn = 1;

   float SetPEEPPressure = 5.0; // SET PEEP PRESSURE IN cmH2O

   float MaxMotorFlowRate = 2666.66; //MAX FLOW RATE ALLOWED BY THE MOTOR (ml/s)

   float BellowCapacity = 1000.0; //ADD THE BELLOW VOLUME IN MILLITERS

   float MaxMotorRPM = 80.0; //ADD THE MAX MOTOR RPM
 


//-------------------------------GRAPHER VARIABLES-----------------------------\\

int     x_pos         = 20; //position along the graph x axis

float   y_pos_old   = 120; //old y axis position of X value

byte    x_scale       = 5; //scale of graph x axis, controlled by touchscreen buttons

 int    y_pos       = 50;
 

int     GraphMenu     = 1;
int     OGraphMenu    = 1;
int PlotMenu =1;
int OPlotMenu =1;

int     OldGraphMenu  = 1;
int     PlottingPoint = 0;
int     GraphColour   = GREEN;
String  GraphName     = "Pressure(cmH2O)";


//---------------------------- MOTOR VARIABLES-----------------------------\\
    
   float  SpeedVal      = 0.0;          // VARIABLE INITIALIZATION
  // int16_t  VolumeVal     = 0.0;        // VARIABLE INITIALIZATION
   float  MotorSpeed    = 0.0;       // VARIABLE INITIALIZATION
   float  Ratio  = 0.0;

   float  OMotorSpeed      = 0.0;       // VARIABLE INITIALIZATION
   float  ORatio           = 0.0;
   float  OInhaleTime    = 500.0; // INSERT THE INHALATION DELAY
   float OFlowRate = 0.0;

   float    maxvolume       = 1000.0;
   float    minvolume       = 500.0;
   float    volume          = 0.0;

   float  mspeed          = 0.0;
   int  BPMRaw          = 0.0;
   int  BPM             = 0.0;
   int  OBPM             = 0.0;

   float    CurrentVolPos      = 0;     // VARIABLE INITIALIZATION
   float    lowpotval       = 0;      // VARIABLE INITIALIZATION
   int SetVolRaw = 0;
   int SetVolR = 0;
   int SetVolL =0;

   float FlowRate = 0.0;

   bool      StartButton     = LOW;
   bool      OStartButton    = LOW;
   int      Pos             = 1; 
   int      DispVol         = 0;
   int      ODispVol        = 0;

   int GraphVolume = 0;
   
    float   highpos         = 0;
    float   LSelVol         = 0;
    float  RSetVol          = 0;
   
 
//---------------------------- ADC VARIABLES-----------------------------\\
   int ADCScale = 26705;       // INSERT THE MAX ADC VALUE  (change this val also in the ReadPots Fuct too)



  double Pressure = 0.0;
  double OPressure = 0.0;
  double PressDiff =0.0;
  double TrigPressure = 3.0;


  double AtPressure = 1000.0;
  int cleared = 0;

  //--------- TIMING ------------\\
   
   unsigned long LoopTime = 0.0;
   unsigned long StartTime = 0.0;
  
