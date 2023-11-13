#include "Encoder.h"

Encoder::Encoder(byte pin) {
  this->pin = pin;
  init();
}

void Encoder::init() {
  pinMode(pin, INPUT);
}

int Encoder::getRelativePosition() {
    return digitalRead(pin);
}

int Encoder::getConstantSpeed() {
    return constantSpeed;
}

int Encoder::getDirection() {
    return direction;
}

void Encoder::setDegreeFactor(int degreeFactor) {
    this->degreeFactor = degreeFactor;
}
void Encoder::setMultiplyFactor(int multiplyFactor) {
    this->multiplyFactor = multiplyFactor;
}