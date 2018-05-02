#pragma once
#include <Ultrasonic.h>
#include <Servo.h>

class UltraHead{
public:
  UltraHead(int trig_back_pin, int echo_back_pin, int trig_front_pin, int echo_front_pin, int servo_pin):
    ultra_back(trig_back_pink, echo_back_pin, 100), ultra_front(trig_front_pin, echo_front_pin, 100), cur_direction(){ servo.attach(servo_pin);}
  bool ready();
  void toggle_direction();
  float get_back_distance();
  float get_front_distance();
private:
  Ultrasonic ultra_back;
  Ultrasonic ultra_front;
  Servo servo;
  int cur_direction;
};