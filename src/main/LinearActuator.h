#ifndef LINEAR_ACTUATOR_H
#define LINEAR_ACTUATOR_H
#include <Arduino.h>
class LinearActuator {

  private:
    int direction;
    int enable;
    byte enablePin;
    byte directionPin;

  public:
    LinearActuator(byte enablePin, byte directionPin);

    void init();
    void setEnabled(int enabled);
    void setDirection(int direction);
};
#endif
