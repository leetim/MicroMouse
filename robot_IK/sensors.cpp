/*Cl_IK.cpp
*/
#include "sensors.h"

#define SOUND_SPEED 58

Cl_IK::Cl_IK() {
}
void Cl_IK::setup(byte _pin) {
  IK_pin = _pin;
  pinMode(IK_pin, INPUT);

}
void Cl_IK::loop() {
  IK = digitalRead(IK_pin) ;
}

bool UltraHead::ready(){
  return true;
}

void UltraHead::toggle_direction(){
  cur_direction = (cur_direction + 1) % 2;
  servo.write(90 * cur_direction + 36);
}

float UltraHead::get_back_distance(){
  return ultra_back.distanceRead();
//  return 0.0;
}

float UltraHead::get_front_distance(){
  return ultra_front.distanceRead();
//  return 0.0;
}
