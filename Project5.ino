#include <Servo.h> // Include the Servo library to control the servo motor

// Define pin connections for the ultrasonic sensor
const int trigPin = 10;     // TRIG pin of HC-SR04 connected to digital pin 10
const int echoPin = 9;      // ECHO pin of HC-SR04 connected to digital pin 9
const int servoPin = 11;    // Servo signal wire connected to digital pin 11

const int distanceThreshold = 20; // Threshold distance in cm to detect hand presence

Servo myServo; // Create a Servo object

void setup() {
  Serial.begin(9600);           // Start the serial monitor for debugging
  pinMode(trigPin, OUTPUT);     // Set TRIG pin as output
  pinMode(echoPin, INPUT);      // Set ECHO pin as input
  myServo.attach(servoPin);     // Attach the servo to its pin
  myServo.write(0);             // Initialize the servo to 0 degrees
}

void loop() {
  long duration;   // Variable to store pulse duration
  int distance;    // Variable to store calculated distance

  // Trigger an ultrasonic pulse
  digitalWrite(trigPin, LOW);   // Ensure trigger pin is low
  delayMicroseconds(2);         // Short delay
  digitalWrite(trigPin, HIGH);  // Send a 10 microsecond pulse
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);   // Turn the trigger pin low again

  // Measure the time taken for the echo to return
  duration = pulseIn(echoPin, HIGH);

  // Convert duration to distance (cm)
  distance = duration * 0.034 / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if hand is within threshold distance
  if (distance > 0 && distance < distanceThreshold) {
    myServo.write(90); // Move servo to 90° if hand is detected
  } else {
    myServo.write(0);  // Return servo to 0° if hand is not detected
  }

  delay(200); // Wait 200 milliseconds before next reading
}

