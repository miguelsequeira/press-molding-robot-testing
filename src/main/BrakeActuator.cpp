#include "BrakeActuator.h"

BrakeActuator::BrakeActuator(byte pin) {
  this->pin = pin;
  init();
}

void BrakeActuator::init() {
  pinMode(pin, OUTPUT);
  setBrake(HIGH);
}

void BrakeActuator::setBrake(int value) {
    if(value == HIGH) {
        this->brake = LOW;
        digitalWrite(pin, LOW);
    } else {
        this->brake = HIGH;
        digitalWrite(pin, HIGH);
    }
}

int BrakeActuator::isBraked() {
    return brake;
}