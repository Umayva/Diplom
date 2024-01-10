#include "WiFi.h"

const char* ssid = "yourSSID"; // replace with your SSID
const char* password = "yourPASSWORD"; // replace with your Wi-Fi password

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
  

}