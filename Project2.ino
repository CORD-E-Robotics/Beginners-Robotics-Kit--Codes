// declare variables for pins
int sensorpin = A0;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;

// variable for sensor reading
int sensor;

// delay time between sensor readings (milliseconds)
int delayTime = 1000; 

// "wet" and "dry" thresholds - these require calibration
int wet = 800;
int dry = 500;

void setup(){
  // set pins as outputs
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  
  // initialize serial communication
  Serial.begin(9600);
}

void loop(){
  // take reading from sensor
  sensor = analogRead(sensorpin);
  
  // print sensor reading
  Serial.println(sensor);
  
  // If sensor reading is greater than "wet" threshold,
  // turn on the blue LED. If it is less than the "dry"
  // threshold, turn on the red LED. If it is in between
  // the two values, turn on the yellow LED.
  if(sensor>wet){
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,HIGH);
  }
  else if(sensor<dry){
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
  }
  else{
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,LOW);
  }
  
  // wait before taking next reading
  delay(delayTime);
  }

