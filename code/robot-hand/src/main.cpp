#include <ESP32Servo.h>
#include <Arduino.h>

Servo little;
Servo ring;
Servo middle;
Servo ind;
Servo thumb;

void setup() {

  Serial.begin(115200);
  little.attach(2);
  ring.attach(4);
  middle.attach(5);
  ind.attach(18);
  thumb.attach(19);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil(',');
    int values[5];
    values[0] = data.toInt();
    
    for (int i = 1; i < 5; i++) {
      data = Serial.readStringUntil(',');
      values[i] = data.toInt();
    }

    little.write(values[0]);
    ring.write(values[1]);
    middle.write(values[2]);
    ind.write(values[3]);
    thumb.write(values[4]);
  }
}
