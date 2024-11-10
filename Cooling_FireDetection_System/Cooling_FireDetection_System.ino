#include "communication.h"
#include "sensor.h"
#include "log.h"

void setup() {
  initializeCommunication();
  initializeSensors();
  initializeActuators();
  initializePID();
  initializeRTC();
}

void loop() {
  
  readSensors(); // Get the sensor readings. 

  controlActuators(); //Control the fans, curtain, and buzzer.

  logData(); // Add sensor readings to log file.  

  delay(2000);  // Delay 2 seconds 
}
