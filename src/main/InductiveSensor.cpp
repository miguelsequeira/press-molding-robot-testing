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
    Serial.println(value);
    if(value > 0)
    {
      return true;
    } else{
      return false;
    }
}
void InductiveSensor::setThreshold() {

}
