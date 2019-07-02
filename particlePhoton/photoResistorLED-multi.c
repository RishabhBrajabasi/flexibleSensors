// -----------------------------------------------------------------
// Function and Variable with photo sensors (resistor or transistor)
// -----------------------------------------------------------------
// In this example, we're going to register a Particle.variable() with the cloud so that we can read brightness levels from the photoresistor or phototransistor.
// We'll also register a Particle.function so that we can turn the LED on and off remotely.

// We're going to start by declaring which pins everything is plugged into.

int led1 = D6; // This is where your LED is plugged in. The other side goes to a resistor connected to GND.
int led2 = D5; // This is where your LED is plugged in. The other side goes to a resistor connected to GND.
int led3 = D4; // This is where your LED is plugged in. The other side goes to a resistor connected to GND.
int led4 = D3; // This is where your LED is plugged in. The other side goes to a resistor connected to GND.
int led5 = D2; // This is where your LED is plugged in. The other side goes to a resistor connected to GND.

int ldr1 = A0; // This is where your photoresistor or phototransistor is plugged in. The other side goes to the "power" pin (below).
int ldr2 = A1; // This is where your photoresistor or phototransistor is plugged in. The other side goes to the "power" pin (below).
int ldr3 = A2; // This is where your photoresistor or phototransistor is plugged in. The other side goes to the "power" pin (below).
int ldr4 = A3; // This is where your photoresistor or phototransistor is plugged in. The other side goes to the "power" pin (below).
int ldr5 = A4; // This is where your photoresistor or phototransistor is plugged in. The other side goes to the "power" pin (below).

int analoguevalue1; // Here we are declaring the integer variable analoguevalue, which we will use later to store the value of the photoresistor or phototransistor.
int analoguevalue2; // Here we are declaring the integer variable analoguevalue, which we will use later to store the value of the photoresistor or phototransistor.
int analoguevalue3; // Here we are declaring the integer variable analoguevalue, which we will use later to store the value of the photoresistor or phototransistor.
int analoguevalue4; // Here we are declaring the integer variable analoguevalue, which we will use later to store the value of the photoresistor or phototransistor.
int analoguevalue5; // Here we are declaring the integer variable analoguevalue, which we will use later to store the value of the photoresistor or phototransistor.

int ledToggle(String command); // Forward declaration

// Next we go into the setup function.

void setup() {
	// This is here to allow for debugging using the USB serial port
	Serial.begin();

	// First, declare all of our pins. This lets our device know which ones will be used for outputting voltage, and which ones will read incoming voltage.
	pinMode(led1, OUTPUT); // Our LED pin is output (lighting up the LED)
	digitalWrite(led1, HIGH);
	pinMode(led2, OUTPUT); // Our LED pin is output (lighting up the LED)
	digitalWrite(led2, HIGH);
	pinMode(led3, OUTPUT); // Our LED pin is output (lighting up the LED)
	digitalWrite(led3, HIGH);
	pinMode(led4, OUTPUT); // Our LED pin is output (lighting up the LED)
	digitalWrite(led4, HIGH);
	pinMode(led5, OUTPUT); // Our LED pin is output (lighting up the LED)
	digitalWrite(led5, HIGH);

	// We are going to declare a Particle.variable() here so that we can access the value of the photosensor from the cloud.
	Particle.variable("analoguevalue1", &analoguevalue1, INT);
	Particle.variable("analoguevalue2", &analoguevalue2, INT);
	Particle.variable("analoguevalue3", &analoguevalue3, INT);
	Particle.variable("analoguevalue4", &analoguevalue4, INT);
	Particle.variable("analoguevalue5", &analoguevalue5, INT);
	// This is saying that when we ask the cloud for "analoguevalue", this will reference the variable analoguevalue in this app, which is an integer variable.

	// We are also going to declare a Particle.function so that we can turn the LED on and off from the cloud.
	Particle.function("led",ledToggle);
	// This is saying that when we ask the cloud for the function "led", it will employ the function ledToggle() from this app.

}


// Next is the loop function...

void loop() {

	// check to see what the value of the photoresistor or phototransistor is and store it in the int variable analoguevalue
	analoguevalue1 = analogRead(ldr1);
	analoguevalue2 = analogRead(ldr2);
	analoguevalue3 = analogRead(ldr3);
	analoguevalue4 = analogRead(ldr4);
	analoguevalue5 = analogRead(ldr5);

	// This prints the value to the USB debugging serial port (for optional debugging purposes)
	Serial.printf("%d", analoguevalue1);
	Serial.printf(",");
	Serial.printf("%d", analoguevalue2);
	Serial.printf(",");
	Serial.printf("%d", analoguevalue3);
	Serial.printf(",");
	Serial.printf("%d", analoguevalue4);
	Serial.printf(",");
	Serial.printlnf("%d", analoguevalue5);

	// This delay is just to prevent overflowing the serial buffer, plus we really don't need to read the sensor more than
	// 10 times per second (100 millisecond delay)
	delay(100);
}


// Finally, we will write out our ledToggle function, which is referenced by the Particle.function() called "led"

int ledToggle(String command) {
	digitalWrite(led1,HIGH);
	digitalWrite(led2,HIGH);
	digitalWrite(led3,HIGH);
	digitalWrite(led4,HIGH);
	digitalWrite(led5,HIGH);
	return 1;

}
