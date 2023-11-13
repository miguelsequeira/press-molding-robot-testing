#ifndef STATE_H
#define STATE_H
#include <Arduino.h>
class State {

  private:
    int availableButton

  public:
    State();

    int getAvailableButton();
};
#endif
