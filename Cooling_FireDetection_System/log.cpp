#include "logging.h"
#include <SD.h> // SD card library
#include <RTClib.h> // Real-time clock library

const int chipSelect = 10;
RTC_DS3231 rtc;

void initializeRTC() {
  if (!rtc.begin()) {
    Serial.println("RTC initialization failed!");
    return;
  }

  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    return;
  }
}

void logData() {
  DateTime now = rtc.now();
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.print(now.timestamp());
    dataFile.print(", Temp1: ");
    dataFile.print(temperature1);
    dataFile.print(", Temp2: ");
    dataFile.print(temperature2);
    dataFile.print(", UV: ");
    dataFile.print(uvValue);
    dataFile.print(", CO: ");
    dataFile.println(coLevel);
    dataFile.close();
  }
}
ssss