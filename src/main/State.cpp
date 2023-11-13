#include "State.h"
State::State(byte pin) {
  this->pin = pin;
  this->availableButton = 1;
  init();
}
void State::init() {
  pinMode(pin, INPUT);
}
int State::getAvailableButton() {
    int value = digitalRead(pin);
    if(value != LOW)
    {
      return 1;
    } else{
      return 2;
    }
}
