#ifndef SENSOR_H
#define SENSOR_H

#include <DHT.h>

void initializeSensors();
void readSensors();

extern float temperature1;
extern float temperature2;
extern int uvValue;
extern int flameDetected;
extern int coLevel;

#endif
