#ifndef BUTTON_H
#define BUTTON_H
#include <Arduino.h>
class Button {

  private:
    byte pinIn, pinOut1, pinOut2, pinLed;
    byte out1Value, out2Value;
    byte position;

  public:
    Button();
    Button(byte position, byte pinIn, byte pinOut1, byte pinOut2, byte pinLed);

    void init();
    bool isClosed();
    void setLedOn();
    void setLedOff();
    byte getCode();
};
#endif
