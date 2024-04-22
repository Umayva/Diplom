#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include "ESPAsyncWebServer.h"

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";
const char* MainServerName = "http://192.168.4.1/post";
AsyncWebServer server(80);

void Server ()
{
    server.on(
    "/post",
    HTTP_POST,
    [](AsyncWebServerRequest * request){},
    NULL,
    [](AsyncWebServerRequest * request, uint8_t *data, size_t len, size_t index, size_t total) {

//      IsReadyForRead = false;
      for (size_t i = 0; i < len; i++) {
        Serial.write(data[i]);
      }
 
      Serial.println();
 
      request->send(200);
  });
 
    server.begin();
}

void TestSender ()
{
    WiFiClient client;
    HTTPClient http;
    http.begin(client, MainServerName);

    // отсылаем то, что получили
//    If you need an HTTP request with a content type: text/plain
    http.addHeader("Content-Type", "text/plain");
      int httpResponseCode = http.POST("И тебе привет!");

    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    // Освобождаем ресурсы
    http.end();
}