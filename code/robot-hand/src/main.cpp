#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include "ESPAsyncWebServer.h"
#include <resiv.h>
void setup() {
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  Server ();//запустили сервер для входящих POST-запросов
 
}
void loop() {
    TestSender ();
}

