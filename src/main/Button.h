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
    Button(byte position, byte pinIn, byte pinLed);

            bool isPressed;           // Current button press state
            bool ledState;           // Current LED state
            bool lastButtonState;    // Previous button state for edge detection
            int signalCount;         // Count of valid signals during sampling
            int sampleCount;         // Total samples taken
            unsigned long lastToggleTime; // Time of last toggle

    void init();
    bool isClosed();
    void setLedOn();
    void setLedOff();
    byte getCode();
};
#endif
