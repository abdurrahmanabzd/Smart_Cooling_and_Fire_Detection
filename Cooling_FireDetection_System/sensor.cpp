#include "sensor.h"
#include <DHT.h>

#define DHTPIN1 2
#define DHTPIN2 3
#define DHTTYPE DHT11
#define UVSensorPin A0
#define FlameSensorPin 4
#define COSensorPin A1

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);

float temperature1;
float temperature2;
int uvValue;
int flameDetected;
int coLevel;

void initializeSensors() {
  dht1.begin();
  dht2.begin();
  pinMode(UVSensorPin, INPUT);
  pinMode(FlameSensorPin, INPUT);
  pinMode(COSensorPin, INPUT);
}

void readSensors() {
  temperature1 = dht1.readTemperature();
  temperature2 = dht2.readTemperature();
  uvValue = analogRead(UVSensorPin);
  flameDetected = digitalRead(FlameSensorPin);
  coLevel = analogRead(COSensorPin);
}
