#include <Wire.h>
#include <SFE_BMP180.h>

SFE_BMP180 bmp180;
 char statusp;
  double T, P;
  bool success = false;

void setup() {
  Serial.begin(9600);
  bool success = bmp180.begin();

  if (success) {
    Serial.println("BMP180 init success");
  }
}

void loop() {

 Pressure();

}

void Pressure()
{

 char status;
  double T, P;
  bool success = false;
  
  statusp = bmp180.startTemperature();

  if (statusp != 0) {
    delay(10);
    statusp = bmp180.getTemperature(T);

    if (statusp != 0) {
      statusp = bmp180.startPressure(3);

      if (statusp != 0) {
        delay(statusp);
        statusp = bmp180.getPressure(P, T);

        if (statusp != 0) {
          //Serial.print("Pressure: ");
          Serial.println(P);
          //Serial.println(" hPa");

         // Serial.print("Temperature: ");
          //Serial.print(T);
         // Serial.println(" C");
        }
      }
    }
  }
  
}
