int sensorPin = A0; // select the input pin for LDR
int sensorPin2 = A1; // select the input pin for LDR

int sensorValue = 0; // variable to store the value coming from the sensor
int sensorValue2 = 0; // variable to store the value coming from the sensor

void setup() {
Serial.begin(9600); //sets serial port for communication
pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
sensorValue = analogRead(sensorPin); // read the value from the sensor
sensorValue2 = analogRead(sensorPin2); // read the value from the sensor

Serial.print(sensorValue); //prints the values coming from the sensor on the screen
Serial.print(","); //prints the values coming from the sensor on the screen

Serial.println(sensorValue2); //prints the values coming from the sensor on the screen

digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  
delay(100);

}
