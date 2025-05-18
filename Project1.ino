//Declare variables for pins
int ldrPin = A0;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
// Initialize serial communication
  Serial.begin(9600);
}

void loop() {
// Read the photoresistor value
  int ldrValue = analogRead(ldrPin);
// Print the value in serial monitor
  Serial.println(ldrValue);

  if (ldrValue < 500) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
// wait before reading the values again
  delay(200);
}
