int photoResistor1 = A0;
//int photoResistor2 = A1;
int photoResistor3 = A2;
//int photoResistor4 = A3;

int pr1 = 0;
//int pr2 = 0;
int pr3 = 0;
//int pr4 = 0;

//int avg = 0;
void setup() {
  Serial.begin(9600); //sets serial port for communication
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  pr1 = analogRead(photoResistor1);
  //  pr2 = analogRead(photoResistor2);
  pr3 sch= analogRead(photoResistor3);
  //  pr4 = analogRead(photoResistor4);

  //  avg = (pr1+pr2+pr3+pr4)/4;
  Serial.print(pr1); Serial.print(",");
  //  Serial.print(pr2);Serial.print(",");
  Serial.print(pr3); Serial.print(",");
  //  Serial.print(pr4);Serial.print(",");
  //  Serial.print(pr5);Serial.print(",");
  //  Serial.print(avg);Serial.print(",");
  Serial.println();
  
  digitalWrite(LE
  D_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  //  delay(100);

}
