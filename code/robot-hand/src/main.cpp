#include <Arduino.h>
#include <Wire.h>
#include <string.h>
#include <send.h>
#include <resiv.h>
#include <move.h>
#include <force.h>

#include <Arduino.h> // Подключение библиотеки Arduino для работы с UART

#include <Arduino.h> // Подключение библиотеки Arduino для работы с UART

// Управление серводвигателями
void setServoAngle(int servoPin, int angle) {
  int minPulse = 500; // Минимальная длительность импульса (0 градусов)
  int maxPulse = 2500; // Максимальная длительность импульса (180 градусов)
  int pulseWidth = map(angle, 0, 180, minPulse, maxPulse);
  digitalWrite(servoPin, HIGH); // Включение серводвигателя
  delayMicroseconds(pulseWidth); // Задержка
  digitalWrite(servoPin, LOW); // Выключение серводвигателя
  delay(20); // Задержка для стабилизации
}

void setup() {
  Serial.begin(9600); // Инициализация UART со скоростью 9600 бод

  // Настройка серводвигателей
  int servoPins[5] = {2, 3, 4, 5, 6}; // Пины, к которым подключены серводвигатели
  for (int i = 0; i < 5; i++) {
    pinMode(servoPins[i], OUTPUT); // Настраиваем пины на вывод
  }
}

void loop() {
  if (Serial.available() >= 5) { // Если доступно 5 байт в UART
    int servoAngles[5]; // Массив для хранения углов поворота серводвигателей
    for (int i = 0; i < 5; i++) {
      servoAngles[i] = Serial.read(); // Чтение по одному байту из UART
    }
    
    // Управление серводвигателями
    int servoPins[5] = {2, 3, 4, 5, 6}; // Пины, к которым подключены серводвигатели
    for (int i = 0; i < 5; i++) {
      setServoAngle(servoPins[i], servoAngles[i]); // Установка угла поворота для каждого серводвигателя
    }
  }
}

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
