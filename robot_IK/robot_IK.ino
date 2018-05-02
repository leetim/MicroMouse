  /*robot_IK.ino
*/
#include "motor.h"
//#include "graph.h"
#include "sensors.h"

///////////////////////////////////////////////////////////////////////////////////////////////
const byte Motor_left_pinA = 14;
const byte Motor_left_pinB = 15;
const byte Motor_left_pinE = 18;
const byte Motor_right_pinA = 16;
const byte Motor_right_pinB = 17;
const byte Motor_right_pinE = 19;

Cl_Motor Motor_left(Motor_left_pinA, Motor_left_pinE, Motor_left_pinB); // создать мотор
Cl_Motor Motor_right(Motor_right_pinA, Motor_right_pinE, Motor_right_pinB); // создать мотор

///////////////////////////////////////////////////////////////////////////////////////////////
const byte front_trig_pin = 2;
const byte front_echo_pin = 3;
const byte back_trig_pin = 4;
const byte back_echo_pin = 5;
const byte servo_pin = 11;

UltraHead uh;//(front_trig_pin, front_echo_pin, back_trig_pin, back_echo_pin, servo_pin);
///////////////////////////////////////////////////////////////////////////////////////////////
//#2 датчики
const byte IK_L_pin = 8; // пин левого ик-датчика
const byte IK_C_pin = 9; // пин центрального ик-датчика
const byte IK_R_pin = 10; // пин правого датчика
Cl_IK IK_L;
Cl_IK IK_C;
Cl_IK IK_R;

///////////////////////////////////////////////////////////////////////////////////////////////
const byte optopara_left_pin = 13;
const byte optopara_right_pin = 12;
float round_length = 1.0;
int points_count = 12;
OptoPara opto_para;

///////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  //#1 мотор
//  Motor.setup();
  //#2 датчики
  uh = UltraHead(front_trig_pin, front_echo_pin, back_trig_pin, back_echo_pin, servo_pin);
  IK_L.setup(IK_L_pin);
  IK_C.setup(IK_C_pin);
  IK_R.setup(IK_R_pin);
  opto_para = OptoPara(optopara_left_pin, optopara_right_pin, round_length, points_count);
  pinMode(13, INPUT);
}

byte mem1[256];
byte temp[256];

int n = 64;

//bool check(){
//  for (int i = 0; i < n; i++){
//    if (mem1[i] != temp[i]) return true;
//  }
//  return false;
//}

void loop() {
//  uh.toggle_direction();
//  delay(2000);
//  Serial.println(uh.get_front_distance());
//  Serial.println(uh.get_back_distance());
//  return;
  
  IK_L.loop();
  IK_C.loop();
  IK_R.loop();
  opto_para.loop();
//  Motor_left.goForward();
  if (!IK_C.IK) Motor_left.goBack();
  if (!IK_R.IK) Motor_right.goBack();
  if (!IK_L.IK) Motor_left.goForward();
  if (IK_C.IK && IK_R.IK && IK_L.IK) {
    Motor_left.stopMotor();
    Motor_right.stopMotor();
  }
  Serial.println(opto_para.get_distance_left());
}
