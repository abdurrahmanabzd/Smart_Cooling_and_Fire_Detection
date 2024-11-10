#include "actuators.h"
#include "sensor.h"
#include "communication.h"
#include <PID_v1.h> // PID control library

#define FanPin1 5
#define FanPin2 6
#define CurtainPin 7
#define BuzzerPin 8

double Setpoint, Input, Output;
PID myPID(&Input, &Output, &Setpoint, 2, 5, 1, DIRECT);

void initializeActuators() {
  pinMode(FanPin1, OUTPUT);
  pinMode(FanPin2, OUTPUT);
  pinMode(CurtainPin, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);

  Setpoint = 22;  // Desired temperature (22°C)
  myPID.SetMode(AUTOMATIC);

  digitalWrite(FanPin1, LOW);
  digitalWrite(FanPin2, LOW);
  digitalWrite(CurtainPin, LOW);
  digitalWrite(BuzzerPin, LOW);
}

void controlActuators() {
  Input = temperature1;
  myPID.Compute();  // Calculate PID output
  if (Output > 0) {
    digitalWrite(FanPin1, HIGH);
    Serial.println("Room 1: Fan ON (PID control)");
  } else {
    digitalWrite(FanPin1, LOW);
    Serial.println("Room 1: Fan OFF");
  }

  if (temperature2 > 25) {
    digitalWrite(FanPin2, HIGH);
    Serial.println("Room 2: Fan ON");
  } else {
    digitalWrite(FanPin2, LOW);
    Serial.println("Room 2: Fan OFF");
  }

  if (uvValue > 300) {
    digitalWrite(CurtainPin, HIGH);
    Serial.println("Curtains Closed: High UV detected.");
  } else {
    digitalWrite(CurtainPin, LOW);
    Serial.println("Curtains Opened.");
  }

  if (flameDetected == HIGH || coLevel > 400) {
    digitalWrite(BuzzerPin, HIGH);
    Serial.println("ALARM! Fire detected.");
    sendAlertToServer("Fire detected!");  // Send emergency notification via Wi-Fi
  } else {
    digitalWrite(BuzzerPin, LOW);
  }
}
