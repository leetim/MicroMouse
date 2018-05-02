#pragma once

#include "Arduino.h"
#include <Ultrasonic.h>
#include <Servo.h>

class UltraHead{
public:
  UltraHead(){};
  UltraHead(uint8_t trig_back_pin, uint8_t echo_back_pin, uint8_t trig_front_pin, uint8_t echo_front_pin, uint8_t servo_pin):
    ultra_back(echo_back_pin, trig_back_pin), ultra_front(trig_front_pin, echo_front_pin), 
    cur_direction(){ servo.attach(servo_pin);}
  bool ready();
  void toggle_direction();
  float get_back_distance();
  float get_front_distance();
private:
  Ultrasonic ultra_back;
  Ultrasonic ultra_front;
  Servo servo;
  uint8_t cur_direction;
};

class Cl_IK {
  public:
    Cl_IK();
    void setup(byte _pin);
    void loop();
    bool IK;// 1 откл / 0 вкл
  private:
    byte IK_pin ;
};
