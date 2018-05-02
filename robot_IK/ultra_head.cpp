#include "ultra_head.h"

#define SOUND_SPEAD 58

bool Ultrasonic::ready(){
  return true;
}

void Ultrasonic::toggle_direction(){
  cur_direction = (cur_direction + 1) % 2
  servo.write(90 * cur_direction);
}

float Ultrasonic::get_back_distance(){
  return ultra_back.distanceRead(SOUND_SPEAD);
}

float Ultrasonic::get_front_distance(){
  return ultra_front.distanceRead(SOUND_SPEAD);
}