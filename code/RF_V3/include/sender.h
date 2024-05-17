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

void test_UART() { 
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
    output = map(fingerPos[i], fingerPosMin[i], fingerPosMax[i], 0, 255);
    if(output > 255) output = 255;
    if(output < 0) output = 0;
    Serial.print(output);
    Serial.print(",");
  }
  output = map(fingerPos[i], fingerPosMin[i], fingerPosMax[i], 0, 255);
  if(output > 255) output = 255;
  if(output < 0) output = 0;
  Serial.print(output);
  Serial.println("");

}
void sendbytes() {
  // int i = 0;
  int temp_output;
  uint8_t output[5];
  uint8_t max = 125;
  uint8_t min = 1;
  for (int i = 0; i < (numOfFingers); i++){
    temp_output = map(fingerPos[i], fingerPosMin[i], fingerPosMax[i], min, max);
    if(temp_output > max) temp_output = max;
    if(temp_output < min) temp_output = min;
    output[i] = temp_output;
    Serial.write(output[i]);
  }
  Serial.write('~');

}

#endif