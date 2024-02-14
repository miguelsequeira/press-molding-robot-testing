#ifndef BRAKE_ACTUATOR_H
#define BRAKE_ACTUATOR_H
#include <Arduino.h>
class BrakeActuator {

  private:
    int brake;
    byte pin;

  public:
    BrakeActuator(byte pin);

    void init();
    void setBrake(int value);
    int isBraked();
};
#endif
