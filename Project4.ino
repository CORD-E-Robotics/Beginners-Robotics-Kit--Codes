// Include necessary libraries
#include <Wire.h>           // For I2C communication (used by the LCD)
#include <LiquidCrystal_I2C.h>  // For controlling the I2C LCD
#include <DHT.h>            // For reading the DHT11 sensor

// Define DHT sensor pin and type
#define DHTPIN 2            // Digital pin connected to DHT11
#define DHTTYPE DHT11       // Type of DHT sensor (DHT11, DHT22, etc.)

// Initialize DHT sensor and LCD objects
DHT dht(DHTPIN, DHTTYPE);   // Create DHT object
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD address: 0x27, 16 columns, 2 rows

void setup() {
  // Initialize the LCD
  lcd.init();       // Start LCD communication
  lcd.backlight();    // Turn on backlight (if available)

  // Initialize DHT sensor
  dht.begin();        // Start DHT sensor
  delay(500);         // Short delay for sensor stabilization
}

void loop() {
  // Wait 2 seconds between readings (DHT11 needs ~1 sec minimum)
  delay(2000);  

  // Read temperature and humidity
  float temp = dht.readTemperature();  // Read temperature in Celsius
  float hum = dht.readHumidity();      // Read humidity in %

  // Check if readings failed (returns NaN if error)
  if (isnan(temp) || isnan(hum)) {
    lcd.clear();              // Clear LCD if error occurs
    lcd.setCursor(0, 0);      // Move cursor to first line
    lcd.print("DHT Error!");  // Display error message
    return;                   // Skip the rest of the loop
  }

  // If readings are OK, display them on the LCD
  lcd.clear();                // Clear previous readings
  lcd.setCursor(0, 0);        // Move to first line, first column
  lcd.print("Temp: ");       // Print label
  lcd.print(temp);           // Print temperature value
  lcd.print(" C");           // Print unit (°C)

  lcd.setCursor(0, 1);        // Move to second line, first column
  lcd.print("Hum:  ");        // Print label
  lcd.print(hum);            // Print humidity value
  lcd.print(" %");           // Print unit (%)
}
