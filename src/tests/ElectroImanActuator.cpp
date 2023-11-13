#include "InductiveSensor.h"
InductiveSensor::InductiveSensor(byte pin) {
  this->pin = pin;
  init();
}
void InductiveSensor::init() {
  pinMode(pin, INPUT);
}
bool InductiveSensor::isClosed() {
    int value = digitalRead(pin);
    if(value != LOW)
    {
      return true;
    } else{
      return false;
    }
}
void InductiveSensor::setThreshold() {

}
