#ifndef STATE_H
#define STATE_H
#include <Arduino.h>
class State {

  private:
    int availableButton;
    byte pin;

  public:
    State(byte pin);

    void init();
    int getAvailableButton();
};
#endif
