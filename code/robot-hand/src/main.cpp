#include <Arduino.h>
#include <Wire.h>
#include <string.h>
#include <send.h>
#include <resiv.h>
#include <move.h>
#include <force.h>


int bag[5], i = 0, testatoi = 0;
void counter(int message){

  
  
  bag[i]=message;
  
}

void setup() {
  Serial.begin(9600);       // инициализировать UART со скоростью 9600 бит/с
}
void robot(){
resiv();
move();
read_force();
send_force();
}
void loop() {

  
}
