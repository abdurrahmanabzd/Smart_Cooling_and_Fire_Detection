#include "communication.h"
#include <ESP8266WiFi.h> // For Wi-Fi communication

const char* ssid = "YourSSID";
const char* password = "YourPassword";

void initializeCommunication() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Wi-Fi connected");
}

void sendAlertToServer(String message) {
  Serial.println("Sending alert: " + message);
  // Add Wi-Fi and server communication logic (e.g., via HTTP, MQTT)
}
