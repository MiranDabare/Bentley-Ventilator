void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i=20; i<51; i++){
  
  pinMode(i,INPUT);
}

  
}

void loop() {
  // put your main code here, to run repeatedly:
/*  
Serial.print("A0 - ");
Serial.print(analogRead(A0)); Serial.print(" ");
Serial.print("A1 - ");
Serial.print(analogRead(A1)); Serial.print(" ");
Serial.print("A2 - ");
Serial.print(analogRead(A2)); Serial.print(" ");
Serial.print("A3 - ");
Serial.print(analogRead(A3)); Serial.print(" ");
Serial.print("A4 - ");
Serial.print(analogRead(A4)); Serial.print(" ");
Serial.print("A8 - ");
Serial.print(analogRead(A5)); Serial.print(" || ");
*/
for (int i=30; i<51; i++){
  
  Serial.print("D"); Serial.print(i); Serial.print(" - ");
  Serial.print(digitalRead(i)); Serial.print(" ");
}

Serial.println(" ");
}
