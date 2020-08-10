void InitialCalculations()
{
  MaxMotorFlowRate = BellowCapacity/(180/((MaxMotorRPM/60)*360));
  MaxMotorFlowRate = (MaxMotorRPM/60.0);
  Serial.println(MaxMotorFlowRate);
    MaxMotorFlowRate = MaxMotorFlowRate*360.0;
  Serial.println(MaxMotorFlowRate);
  MaxMotorFlowRate =180.0/MaxMotorFlowRate;
  Serial.println(MaxMotorFlowRate);
    MaxMotorFlowRate =BellowCapacity/MaxMotorFlowRate;
  Serial.println(MaxMotorFlowRate);

}
