#ifndef BRAKE_ACTUATOR_H
#define BRAKE_ACTUATOR_H
#include <Arduino.h>
class BrakeActuator {

  private:
    int direction;
    int appliedPower;
    byte pin;

  public:
    BrakeActuator(byte pin);

    void init();
    void setDirection(int direction);
    void setAppliedPower(int appliedPower);
    int getAppliedPower();
};
#endif
