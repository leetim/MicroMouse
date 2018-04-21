// Cl_Motor.cpp

#include "Arduino.h"
#include "Cl_Motor.h"

Cl_Motor::Cl_Motor() { // конструктор
}
void Cl_Motor::setup() { // функцию засунуть в setup() программы
  pinMode(Motor5_pin, OUTPUT);
  pinMode(Motor6_pin, OUTPUT);
  pinMode(Motor7_pin, OUTPUT);
  this->stopMotor();
}
void Cl_Motor::loop() { // функцию засунуть в loop() программы
}
void Cl_Motor::stopMotor() { // остановить мотор
  if (Motor != MD_STOP) {
    Motor = MD_STOP;
    digitalWrite(Motor5_pin, 0);
    digitalWrite(Motor6_pin, 0);
    digitalWrite(Motor7_pin, 0);
  }
}
void Cl_Motor::goForward() { // запустить мотор вперед
  if (Motor != MD_FORWARD) {
    Motor = MD_FORWARD;
    digitalWrite(Motor5_pin, 0);
    digitalWrite(Motor6_pin, 1);
    digitalWrite(Motor7_pin, 0);
  }
}
void Cl_Motor::turnLeft() { // функция движения влево
  if (Motor != MD_LEFT) {
    Motor = MD_LEFT;
    digitalWrite(Motor5_pin, 0);
    digitalWrite(Motor6_pin, 1);
    digitalWrite(Motor7_pin, 1);
  }
}
void Cl_Motor::turnRight() { // функция движения вправо
  if (Motor != MD_RIGHT) {
    Motor = MD_RIGHT;    
    digitalWrite(Motor5_pin, 1);
    digitalWrite(Motor6_pin, 1);
    digitalWrite(Motor7_pin, 0);

  }
}

void Cl_Motor::goBack() { // функция движения назад
  if (Motor != MD_BACK) {
    Motor = MD_BACK;    
    digitalWrite(Motor5_pin, 1);
    digitalWrite(Motor6_pin, 1);
    digitalWrite(Motor7_pin, 1);

  }
}
