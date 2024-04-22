/*
 * Remote Feelings: Adam Curtis, Aymeric Wang, Xinying Hu
 * 11/30/21
 * Prototype version. Author: Aymeric Wang
 */

#ifndef SENDER_H
#define SENDER_H

#include <Arduino.h>
#include <Wire.h>
#include "calibration.h"

#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <HTTPClient.h>

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";
const char* SlaveServerName = "http://192.168.4.2/post"; 

AsyncWebServer server(80);

void Server(){
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

void test_UART() { 
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

void message_send(String message){
  String formatted_message;
  formatted_message ="<"+message+">";
  Serial.print(formatted_message);
}

void send_control() {
  static int i = 0;
  int output;

  for (i = 0; i < (numOfFingers - 1); i++){
    // output = map(fingerPos[i], fingerPosMin[i], fingerPosMax[i], 0, 255);
    // if(output > 255) output = 255;
    // if(output < 0) output = 0;
    // Serial.print(output);
    // Serial.println("");

    output = map(fingerPos[i], fingerPosMin[i], fingerPosMax[i], 0, 255);
    if(output > 255) output = 255;
    if(output < 0) output = 0;
    Serial.print(output);
    Serial.print(",");
  }
  
  // output = map(fingerPos[i], fingerPosMin[i], fingerPosMax[i], 0, 255);
  // if(output > 255) output = 255;
  // if(output < 0) output = 0;
  // Serial.print(output);
  // Serial.println("");

}

#endif