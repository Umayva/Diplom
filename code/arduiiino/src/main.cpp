#include <Arduino.h>
#include <Wire.h>
#include <string.h>

int bag[5], i = 0, testatoi = 0;
void counter(int message){
  
  bag[i]=message;
  
}

void setup() {
  Serial.begin(9600);       // инициализировать UART со скоростью 9600 бит/с
}

void loop() {
  // int output;
  // int  att = 0;
  if (i == 5) {
    i = 0;
  }
  
  if(Serial.available()) {  
     
    // char data_rcvd = Serial.read();   // прочитать один байт из последовательного буфера и сохранить в data_rcvd
    // testatoi = atoi(data_rcvd);
    // //testatoi = ;
    // counter(testatoi);
  
    Serial.print(testatoi);
  }

  i++;
  
}
