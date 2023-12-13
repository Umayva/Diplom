#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <HTTPClient.h>


const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";
const char* SlaveServerName = "http://192.168.4.2/post";
AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  Server ();//запустили сервер для входящих POST-запросов
}

void resiv();

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

void loop() {TestSender ();}

void TestSender ()
{
    WiFiClient client;
    HTTPClient http;

    
    // Your Domain name with URL path or IP address with path
    http.begin(client, SlaveServerName);

    // отсылаем то, что получили
    //    If you need an HTTP request with a content type: text/plain
    http.addHeader("Content-Type", "text/plain");
      int httpResponseCode = http.POST("Привет!");

    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    // Освобождаем ресурсы
    http.end();

}









#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include "ESPAsyncWebServer.h"

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";
const char* MainServerName = "http://192.168.4.1/post";


AsyncWebServer server(80);

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

void loop() {TestSender ();}

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