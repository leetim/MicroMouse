#include "ultra_head.h"

#define SOUND_SPEED 58

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
