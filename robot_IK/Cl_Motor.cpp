// Cl_Motor.cpp

#include "Arduino.h"
#include "Cl_Motor.h"

Cl_Motor::Cl_Motor() { // конструктор
}
void Cl_Motor::setup(byte _IN1_pin,  byte _IN2_pin,  byte _EN1_pin,  byte _IN3_pin, byte _IN4_pin, byte _EN2_pin) { // функцию засунуть в setup() программы
    IN1_pin = 5; // правый вперед
    IN2_pin = 7; // правый назад
    IN3_pin = 5; // левый  вперед
    IN4_pin = 7; // левый назад
    EN1_pin = 6; // шим правого двигателя
    EN2_pin = 6; // шим левого двигателя
  pinMode(IN1_pin, OUTPUT);
  pinMode(IN2_pin, OUTPUT);
  pinMode(IN3_pin, OUTPUT);
  pinMode(IN4_pin, OUTPUT);
  pinMode(EN1_pin, OUTPUT);
  pinMode(EN2_pin, OUTPUT);
  Motor = 0;
  digitalWrite(IN1_pin, 0);
  digitalWrite(IN2_pin, 0);
  digitalWrite(IN3_pin, 0);
  digitalWrite(IN4_pin, 0);
}
void Cl_Motor::loop() { // функцию засунуть в loop() программы
}
void Cl_Motor::STOP() { // остановить мотор
  if (Motor != 0) {
    Motor = 0;
    digitalWrite(IN1_pin, 0);
    digitalWrite(IN2_pin, 0);
    digitalWrite(IN3_pin, 0);
    digitalWrite(IN4_pin, 0);
  }
}
void Cl_Motor::FORWARD() { // запустить мотор вперед
  if (Motor != 1) {
    Motor = 1;
    digitalWrite(IN1_pin, 1);
    digitalWrite(IN2_pin, 0);
    digitalWrite(IN3_pin, 1);
    digitalWrite(IN4_pin, 0);
    analogWrite(EN1_pin, Speed);
    analogWrite(EN2_pin, Speed + d_S);
  }
}
void Cl_Motor::Back_Left() { // функция движения назад влево
  if (Motor != 3) {
    Motor = 3;
    digitalWrite (IN1_pin, 0);
    digitalWrite (IN2_pin, 1);
    digitalWrite (IN3_pin, 0);
    digitalWrite (IN4_pin, 1);
    analogWrite(EN1_pin, 160);
    analogWrite(EN2_pin, 90);
  }
}
void Cl_Motor::Back_Right() { // функция движения назад вправо
  if (Motor != 4) {
    Motor = 4;
    digitalWrite (IN1_pin, 0);
    digitalWrite (IN2_pin, 1);
    digitalWrite (IN3_pin, 0);
    digitalWrite (IN4_pin, 1);
    analogWrite(EN1_pin, 90);
    analogWrite(EN2_pin, 160);
  }
}
