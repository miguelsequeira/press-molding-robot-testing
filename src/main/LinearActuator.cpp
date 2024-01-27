#include <Controllino.h>
#include "LinearActuator.h"
LinearActuator::LinearActuator(byte enablePin, byte directionPin) {
  this->enablePin = enablePin;
  this->directionPin = directionPin;
  init();
}
void LinearActuator::init() {
  pinMode(enablePin, OUTPUT);
  pinMode(directionPin, OUTPUT);
}

void LinearActuator::setEnabled(int enabled) {
    digitalWrite(enablePin, enabled);
}

void LinearActuator::setDirection(int direction) {
    digitalWrite(directionPin, direction);
}
