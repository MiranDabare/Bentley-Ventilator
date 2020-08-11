#include <Wire.h>
#include <SFE_BMP180.h>

SFE_BMP180 bmp180;
  char status;
    double T, P, hPa, cmH2O;
          double AtPressure = 1010.0;
          bool success = false;

            double Pressure = 0.0;
  double OPressure = 1050.0;
  double PressDiff =0.0;
  
    
void setup() {
  Serial.begin(9600);
  bool success = bmp180.begin();
 
  if (success) {
    Serial.println("BMP180 init success");


      if (status != 0) {
    delay(10);
    status = bmp180.getTemperature(T);

    if (status != 0) {
      status = bmp180.startPressure(3);

      if (status != 0) {
        delay(status);
        status = bmp180.getPressure(P, T);
        AtPressure = P;
 

        if (status != 0) {
            Serial.println(P);
        
        }
      }
    }
  }
  }
}

void loop() {

  char status;


  bool success = false;

  status = bmp180.startTemperature();

  if (status != 0) {
    delay(10);
    status = bmp180.getTemperature(T);

    if (status != 0) {
      status = bmp180.startPressure(3);

      if (status != 0) {
        delay(status);
        status = bmp180.getPressure(P, T);
        Pressure = P;
        
       cmH2O = ( P - AtPressure) * 1.01972 ;
       PressDiff = Pressure - OPressure;

        if (status != 0) {
          //Serial.print("Pressure: ");
          Serial.println(PressDiff);
          //Serial.println(" hPa");

         // Serial.print("Temperature: ");
          //Serial.print(T);
         // Serial.println(" C");
        }
      }
    }
  }

    OPressure = Pressure;;
}
