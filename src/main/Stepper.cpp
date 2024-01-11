#include <Controllino.h>
#include "Stepper.h"
Stepper::Stepper(byte enablePin, byte directionPin, byte pulsePin) {
  this->enablePin = enablePin;
  this->directionPin = directionPin;
  this->pulsePin = pulsePin;
  init();
}
void Stepper::init() {
  pinMode(enablePin, OUTPUT);
  pinMode(directionPin, OUTPUT);
  pinMode(pulsePin, OUTPUT);
}

void Stepper::setEnabled(int enabled) {
    digitalWrite(enablePin, enabled);
}

void Stepper::setDirection(int direction) {
    digitalWrite(directionPin, direction);
}

void Stepper::setAppliedPower(int appliedPower) {
    this->appliedPower = appliedPower;
    analogWrite(pulsePin, appliedPower);
}

int Stepper::getAppliedPower() {
    return appliedPower;
}
