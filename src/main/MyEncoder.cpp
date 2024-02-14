#include "MyEncoder.h"

MyEncoder::MyEncoder(byte pin) {
  this->pin = pin;
  init();
}

void MyEncoder::init() {
  pinMode(pin, INPUT);
}

int MyEncoder::getRelativePosition() {
    int value = analogRead(pin);
    return value;
}

int MyEncoder::getConstantSpeed() {
    return constantSpeed;
}

int MyEncoder::getDirection() {
    return direction;
}

void MyEncoder::setDegreeFactor(int degreeFactor) {
    this->degreeFactor = degreeFactor;
}
void MyEncoder::setMultiplyFactor(int multiplyFactor) {
    this->multiplyFactor = multiplyFactor;
}