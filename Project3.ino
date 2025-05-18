// Declare variables for pins
int pirPin = 2;
int ledPin = 8;
int buzzerPin = 9;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
//Initialize serial monitor
  Serial.begin(9600);
}
void loop() {
// Read PIR sensor
  int motion = digitalRead(pirPin);
// When motion is detected
  if (motion == HIGH) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
// Print on serial monitor
    Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  delay(500);
}

