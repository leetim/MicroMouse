// Cl_Motor.h
#ifndef Cl_Motor_h
#define Cl_Motor_h

#include "Arduino.h"
enum MotorDirection{MD_NONE, MD_STOP, MD_FORWARD, MD_LEFT, MD_RIGHT, MD_BACK};

class Cl_Motor {
  public:
    Cl_Motor(); // конструктор
    Cl_Motor(byte p5, byte p6, byte p7): Motor5_pin(p5), Motor6_pin(p6), Motor7_pin(p7){} // конструктор
    void setup(); // функцию засунуть в setup() программы
    void loop(); // функцию засунуть в loop() программы
    void goForward(); 
    void turnLeft(); // запустить мотор назад влево
    void turnRight(); // запустить мотор назад вправо// запустить мотор вперед
    void goBack(); // запустить мотор назад вправо// запустить мотор вперед
    void stopMotor();// остановить мотор
  private:
    byte Motor5_pin;
    byte Motor6_pin;
    byte Motor7_pin;
    MotorDirection Motor;
};
#endif // Cl_Motor.h
