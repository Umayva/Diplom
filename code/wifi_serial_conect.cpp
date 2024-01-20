#include "WiFi.h"

const char* ssid = "Remote_Feeling"; // replace with your SSID
const char* password = "password"; // replace with your Wi-Fi password

void setup() {
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to the WiFi network");
}

void loop() {
  Serial.println("MASTURBATOR3000 приказать");
  delay(1500);
}