#ifndef ENCODER_H
#define ENCODER_H
#include <Arduino.h>
class Encoder {

  private:
    int relativePosition;
    int constantSpeed;
    int direction;
    int degreeFactor;
    int multiplyFactor;
    byte pin;

  public:
    Encoder(byte pin);

    void init();
    int getRelativePosition();
    int getConstantSpeed();
    int getDirection();
    void setDegreeFactor(int degreeFactor);
    void setMultiplyFactor(int multiplyFactor);
};
#endif
