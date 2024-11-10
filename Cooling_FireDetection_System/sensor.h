#ifndef SENSOR_H
#define SENSOR_H

// Define I/O pin numbers
#define THERMO1 A0 // 3 x Thermistor KY-013 
#define THERMO2 A1
#define THERMO2 A2
#define UVSENSOR A3 //3 x GUVA-S12SD
#define GASSENSOR A4 // 1 x Gas Sensor MQ-2
#define FLAMESENSOR 4 // 2 x flame detection sensor

void initializeSensors();
void readSensors();

float readTemp(int thermistorPin);
float readUV(int uvSensorPin);
void detectGas();
void detectFlame();


extern float temperature1;
extern float temperature2;
extern int uvValue;
extern int flameDetected;
extern int coLevel;

#endif
