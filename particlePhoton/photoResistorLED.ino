// -----------------------------------------------------------------
// Function and Variable with photo sensors (resistor or transistor)
// -----------------------------------------------------------------
// In this example, we're going to register a Particle.variable() with the cloud so that we can read brightness levels from the photoresistor or phototransistor.
// We'll also register a Particle.function so that we can turn the LED on and off remotely.

// We're going to start by declaring which pins everything is plugged into.

int led = D6; // This is where your LED is plugged in. The other side goes to a resistor connected to GND.

int photosensor = A0; // This is where your photoresistor or phototransistor is plugged in. The other side goes to the "power" pin (below).

int analogvalue; // Here we are declaring the integer variable analogvalue, which we will use later to store the value of the photoresistor or phototransistor.

int ledToggle(String command); // Forward declaration

// Next we go into the setup function.

void setup() {
	// This is here to allow for debugging using the USB serial port
	Serial.begin();

	// First, declare all of our pins. This lets our device know which ones will be used for outputting voltage, and which ones will read incoming voltage.
	pinMode(led, OUTPUT); // Our LED pin is output (lighting up the LED)
	digitalWrite(led, HIGH);

	// We are going to declare a Particle.variable() here so that we can access the value of the photosensor from the cloud.
	Particle.variable("analogvalue", &analogvalue, INT);
	// This is saying that when we ask the cloud for "analogvalue", this will reference the variable analogvalue in this app, which is an integer variable.

	// We are also going to declare a Particle.function so that we can turn the LED on and off from the cloud.
	Particle.function("led",ledToggle);
	// This is saying that when we ask the cloud for the function "led", it will employ the function ledToggle() from this app.

}


// Next is the loop function...

void loop() {

	// check to see what the value of the photoresistor or phototransistor is and store it in the int variable analogvalue
	analogvalue = analogRead(photosensor);

	// This prints the value to the USB debugging serial port (for optional debugging purposes)
	Serial.printlnf("%d", analogvalue);

	// This delay is just to prevent overflowing the serial buffer, plus we really don't need to read the sensor more than
	// 10 times per second (100 millisecond delay)
	delay(100);
}


// Finally, we will write out our ledToggle function, which is referenced by the Particle.function() called "led"

int ledToggle(String command) {
	digitalWrite(led,HIGH);
	return 1;

}