// Cl_Motor.cpp

#include "Arduino.h"
#include "Cl_Motor.h"

Cl_Motor::Cl_Motor() { // конструктор
  pinMode(Motor5_pin, OUTPUT);
  pinMode(Motor6_pin, OUTPUT);
  pinMode(Motor7_pin, OUTPUT);
  this->stopMotor();
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
    digitalWrite(Motor7_pin, 1);
  }
}

void Cl_Motor::goBack() { // функция движения назад
  if (Motor != MD_BACK) {
    Motor = MD_BACK;    
    digitalWrite(Motor5_pin, 1);
    digitalWrite(Motor6_pin, 1);
    digitalWrite(Motor7_pin, 0);

  }
}


OptoPara::OptoPara(int left_pin, int right_pin, float round_length, int point_count){
  this->left_pin = left_pin;
  this->right_pin = right_pin;
  this->step_length = round_length / point_count;
  pinMode(left_pin, INPUT);
  pinMode(right_pin, INPUT);
  state_left = digitalRead(left_pin);
  state_right = digitalRead(right_pin);
}

void OptoPara::loop(){
  int cur_left = digitalRead(left_pin);
  int cur_right = digitalRead(right_pin);
  if (cur_left != state_left){
    count_left++;
    state_left = cur_left;  
  }
  if (cur_right != state_right){
    count_right++;
    state_right = cur_right;  
  }
}
  
float OptoPara::get_distance_left(){
  return count_left*step_length;    
}
float OptoPara::get_distance_right(){
  return count_right*step_length;  
}
