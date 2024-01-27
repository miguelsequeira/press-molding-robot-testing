#ifndef STEPPER_H
#define STEPPER_H
#include <Arduino.h>
class Stepper {

  private:
    int direction;
    int appliedPower;
    byte enablePin;
    byte directionPin;
    byte pulsePin;

  public:
    Stepper(byte enablePin, byte directionPin, byte pulsePin);

    void init();
    void setEnabled(int enabled);
    void setDirection(int direction);
    void setAppliedPower(int appliedPower);
    int getAppliedPower();
};
#endif
