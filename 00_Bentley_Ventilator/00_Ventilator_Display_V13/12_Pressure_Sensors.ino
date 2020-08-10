 void PressureSensors()
 {
  bool success = bmp180.begin();
  
    char status;
  double T, P;
  //bool success = false;
  
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
        AirwayPressure = ( P - AtPressure) * 1.01972 ;

        PressDiff = OPressure - Pressure;

        if (status != 0) {
      
        }
      }
    }
  }

  OPressure = Pressure;;

 }
