#pragma once

#include "Arduino.h"
enum MotorDirection{MD_NONE, MD_STOP, MD_FORWARD, MD_LEFT, MD_RIGHT, MD_BACK};

class Cl_Motor {
  public:
    Cl_Motor(); // конструктор
    Cl_Motor(byte p5, byte p6, byte p7): Motor5_pin(p5), Motor6_pin(p6), Motor7_pin(p7){} // конструктор
    void goForward(); 
    void goBack(); // запустить мотор назад вправо// запустить мотор вперед
    void stopMotor();// остановить мотор
  private:
    byte Motor5_pin;
    byte Motor6_pin;
    byte Motor7_pin;
    MotorDirection Motor;
};

class OptoPara{
public:
  OptoPara(){}
  OptoPara(int left_pin, int right_pin, float round_lengt, int point_count);
  void loop();
  float get_distance_left();
  float get_distance_right();
 private:
  int left_pin;
  int right_pin;
  float step_length;
  int state_left;
  int state_right;
  int count_left;
  int count_right;
};
