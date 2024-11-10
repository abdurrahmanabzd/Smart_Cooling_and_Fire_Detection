#include "sensor.h"
#include <DHT.h>

float temperature1;
float temperature2;
int uvValue;
int flameDetected;
int coLevel;

void initializeSensors() {
  //Initialize Thermistor
  Serial.begin(9600);
  pinMode(THERMO1, INPUT);
  pinMode(THERMO2, INPUT);
  pinMode(THERMO3, INPUT);

  
  pinMode(UVSensorPin, INPUT); //Initialize UV Sensor
  pinMode(FlameSensorPin, INPUT); //Initialize Flame Detection Sensor
  pinMode(COSensorPin, INPUT); //Initialize Gas Detection Sensor
}

void readSensors() {
  temperature1 = dht1.readTemperature();
  temperature2 = dht2.readTemperature();
  uvValue = analogRead(UVSensorPin);
  flameDetected = digitalRead(FlameSensorPin);
  coLevel = analogRead(COSensorPin);
}

float readTemp(int thermistorPin) { // source : sensor datasheet example code
  int analogValue = analogRead(thermistorPin); // Reading the analog input from the thermistor (temperature sensor).
  float resistance = (1024.0 / analogValue - 1.0) * 10000.0; // Calculate the thermistor resistance (assuming a 10k pull-down resistor)

  // Convert resistance to temperature using the Steinhard-Hart equation
  float temperature = 1.0 / (0.001129148 + 0.000234125 * log(resistance) + 0.0000000876741 * pow(log(resistance), 3)); 
  temperature -= 273.15; // Convert Kelvin to Celcius
  
  return temperature;
}

int readUV() {

}

void detectFlame() {

}

void detectGas() {

}

