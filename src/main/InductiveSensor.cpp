#include "InductiveSensor.h"
InductiveSensor::InductiveSensor(byte pin) {
  this->pin = pin;
  init();

}
void InductiveSensor::init() {
  pinMode(pin, INPUT);
}
bool InductiveSensor::isClosed() {
    int value = analogRead(pin);
    return (value > 358);
}
