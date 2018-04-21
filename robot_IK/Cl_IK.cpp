/*Cl_IK.cpp
*/
#include "Arduino.h"
#include "Cl_IK.h"
Cl_IK::Cl_IK() {
}
void Cl_IK::setup(byte _pin) {
  IK_pin = _pin;
  pinMode(IK_pin, INPUT);

}
void Cl_IK::loop() {
  IK = digitalRead(IK_pin) ;
}
