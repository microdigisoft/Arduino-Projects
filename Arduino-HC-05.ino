#define ledPin 11 // Initialize pin 11 to drive LED
int state = 0; // To read state of serial data from HC05 module
void setup() {
  pinMode(ledPin, OUTPUT);//Define ledpin as output
  digitalWrite(ledPin, LOW);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
  if (Serial.available() > 0) { // Checks whether data is coming from the serial port
    state = Serial.read(); // Reads the data from the serial port
  }
  if (state == '0') {
    digitalWrite(ledPin, LOW); // Turn LED OFF
    Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
    state = 0;
  }
  else if (state == '1') {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");;
    state = 0;
  }
}
