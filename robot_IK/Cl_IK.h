/*Cl_IK.h
*/
#ifndef Cl_IK_h
#define Cl_IK_h

#include "Arduino.h"
class Cl_IK {
  public:
    Cl_IK();
    void setup(byte _pin);
    void loop();
    bool IK;// 1 откл / 0 вкл
  private:
    byte IK_pin ;
};
#endif //Cl_IK_h
