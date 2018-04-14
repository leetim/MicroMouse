// Cl_Motor.h
#ifndef Cl_Motor_h
#define Cl_Motor_h

#include "Arduino.h"

class Cl_Motor {
  public:
    Cl_Motor(); // конструктор
    void setup(byte _IN1_pin, byte _IN2_pin, byte _EN1_pin, byte _IN3_pin, byte _IN4_pin, byte _EN2_pin); // функцию засунуть в setup() программы
    void loop(); // функцию засунуть в loop() программы
    void FORWARD(); // запустить мотор вперед
    void Back_Left(); // запустить мотор назад влево
    void Back_Right(); // запустить мотор назад вправо
    void STOP();// остановить мотор
  private:
    byte IN1_pin = 5; // правый вперед
    byte IN2_pin = 7; // правый назад
    byte IN3_pin = 5; // левый  вперед
    byte IN4_pin = 7; // левый назад
    byte EN1_pin = 6; // шим правого двигателя
    byte EN2_pin = 6; // шим левого двигателя
    byte Motor;// 1 мотор вращается вперед/2 мотор вращается назад влево/3 мотор вращается назад вправо / 0 нет
    byte Speed = 95; // скорость движения вперед
    byte d_S = 5;  // поправка для компенсации правого двигателя
};
#endif // Cl_Motor.h
