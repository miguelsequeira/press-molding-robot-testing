#ifndef INDUCTIVE_SENSOR_H
#define INDUCTIVE_SENSOR_H
#include <Arduino.h>
class InductiveSensor {

  private:
    byte pin;
    int threshold;

  public:
    // Setup pin and call init()
    InductiveSensor(byte pin);

    // Setup the pin as INPUT
    void init();

    bool isClosed();

    void setThreshold();
};
#endif
