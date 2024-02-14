#ifndef INDUCTIVE_SENSOR_H
#define INDUCTIVE_SENSOR_H
#include <Arduino.h>
class InductiveSensor {

  private:
    byte pin;

  public:
    InductiveSensor(byte pin);

    void init();

    bool isClosed();
};
#endif
