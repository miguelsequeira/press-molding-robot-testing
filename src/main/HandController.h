#ifndef HAND_CONTROLLER_H
#define HAND_CONTROLLER_H

#define BTN0_NOT_PRESSED    100
#define BTN1_EMERGENCY      101
#define BTN2_BLOCK_TRACK    102
#define BTN3_GRAB_MOLD      103
#define BTN4_ROTATE         104
#define BTN5_FORWARD        105
#define BTN6_BACKWARD       106
#define BTN7_UP             107
#define BTN8_DOWN           108

#include <Controllino.h>
#include "Button.h"

class HandController {

  private:
    byte* pinIn;
    byte* pinOut;
    byte* pinLed;
    Button* buttons;

  public:
    HandController(byte pinIn[], byte pinOut[], byte pinLed[]);

    void init();

    int getClosedButton();
    Button* getClosedButtonObj();
};
#endif
