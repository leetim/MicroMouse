/*robot_IK.ino
  #1 мотор
  #2 датчики
*/
//#1 мотор
#include "Cl_Motor.h"
const byte Motor5_pin = 5;
const byte Motor6_pin = 6;
const byte Motor7_pin = 7;
Cl_Motor Motor(Motor5_pin, Motor6_pin, Motor7_pin); // создать мотор

//#2 датчики
#include "Cl_IK.h"
Cl_IK IK_L, IK_C, IK_R;
const byte IK_L_pin = 3; // пин левого ик-датчика
const byte IK_C_pin = 2; // пин центрального ик-датчика
const byte IK_R_pin = 1; // пин правого датчика

void setup() {
//  Serial.begin(9600);
  //#1 мотор
  Motor.setup();
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

  if (!IK_C.IK) Motor.goBack();
  if (!IK_R.IK) Motor.turnLeft();
  if (!IK_L.IK) Motor.turnRight();
  if (IK_C.IK && IK_R.IK && IK_L.IK) Motor.stopMotor();
}
