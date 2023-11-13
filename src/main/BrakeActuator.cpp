#include "BrakeActuator.h"

BrakeActuator::BrakeActuator(byte pin) {
  this->pin = pin;
  init();
}

void BrakeActuator::init() {
  pinMode(pin, OUTPUT);
}

void BrakeActuator::setDirection(int direction) {
    this->direction = direction;
}

void BrakeActuator::setAppliedPower(int appliedPower) {
    analogWrite(pin, appliedPower);
}

int BrakeActuator::getAppliedPower() {
    return appliedPower;
}