/*robot_IK.ino
  #1 мотор
  #2 датчики
*/
//#1 мотор
#include "Cl_Motor.h"
Cl_Motor Motor; // создать мотор
const byte IN1_pin = 5; // определяем пины управления двигателями правый
const byte IN2_pin = 7; // правый
const byte IN3_pin = 5; // левый
const byte IN4_pin = 7; // левый
const byte EN2_pin = 6; // шим правого двигателя
const byte EN1_pin = 6; // шим левого двигателя



//#2 датчики
#include "Cl_IK.h"
Cl_IK IK_L, IK_C, IK_R;
const byte IK_L_pin = 3; // пин левого ик-датчика
const byte IK_C_pin = 2; // пин центрального ик-датчика
const byte IK_R_pin = 1; // пин правого датчика

void setup() {
  //#1 мотор
  Motor.setup(IN1_pin, IN2_pin, EN1_pin, IN3_pin, IN4_pin, EN2_pin);
  //#2 датчики
  IK_L.setup(IK_L_pin);
  IK_C.setup(IK_C_pin);
  IK_R.setup(IK_R_pin);
}

void loop() {
  //#1 мотор
  Motor.loop();
  //#2 датчики
  IK_L.loop();
  IK_C.loop();
  IK_R.loop();
  if (! IK_L.IK || ! IK_C.IK )  Motor.Back_Right();
  else if (! IK_R.IK) Motor. Back_Left();
  else Motor.FORWARD();
}
