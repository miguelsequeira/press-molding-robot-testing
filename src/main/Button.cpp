#include "Button.h"

Button::Button() {
}

Button::Button(byte position, byte pinIn, byte pinOut1, byte pinOut2, byte pinLed) {
  this->position = position;
  this->pinIn = pinIn;
  this->pinOut1 = pinOut1;
  this->pinOut2 = pinOut2;
  this->pinLed = pinLed;

  if(position%2 == 0) {
    this->out1Value = HIGH;
    this->out2Value = LOW;
  } else {
    this->out1Value = LOW;
    this->out2Value = HIGH;
  }
  init();
  setLedOff();
}

void Button::init() {
  pinMode(pinIn, INPUT);
  pinMode(pinOut1, OUTPUT);
  pinMode(pinOut2, OUTPUT);
  pinMode(pinLed, OUTPUT);
}

bool Button::isClosed() {

    digitalWrite(pinOut1, out1Value);
    digitalWrite(pinOut2, out2Value);
    int value = analogRead(pinIn);
    return (value > 358);
}

void Button::setLedOn() {
  digitalWrite(pinLed, HIGH);
}
void Button::setLedOff() {
  digitalWrite(pinLed, LOW);
}
byte Button::getCode() {
    return position;
}