#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // I2C

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for serial port to open (for some boards)

  Serial.println(F("BMP280 test"));

  if (!bmp.begin(0x76)) {  // Address 0x76 or 0x77, depending on your sensor
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
}

void loop() {
  Serial.print(F("Pressure = "));
  Serial.print(bmp.readPressure() / 100.0F);  // Pressure in hPa
  Serial.print(" hPa\t");

  Serial.print(F("Temperature = "));
  Serial.print(bmp.readTemperature());       // Temperature in °C
  Serial.println(" °C");

  delay(2000);
}
