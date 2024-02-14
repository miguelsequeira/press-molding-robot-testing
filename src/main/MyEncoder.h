#ifndef MY_ENCODER_H
#define MY_ENCODER_H
#include <Arduino.h>
class MyEncoder {

  private:
    int relativePosition;
    int constantSpeed;
    int direction;
    int degreeFactor;
    int multiplyFactor;
    byte pin;

  public:
    MyEncoder(byte pin);

    void init();
    int getRelativePosition();
    int getConstantSpeed();
    int getDirection();
    void setDegreeFactor(int degreeFactor);
    void setMultiplyFactor(int multiplyFactor);
};
#endif
