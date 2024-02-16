#include "HandController.h"

int buttonsCodes[] = {BTN1_EMERGENCY, BTN2_BLOCK_TRACK, BTN3_GRAB_MOLD, BTN4_ROTATE, BTN5_FORWARD, BTN6_BACKWARD, BTN7_UP, BTN8_DOWN};

HandController::HandController(byte pinIn[], byte pinOut[], byte pinLed[]) {
    this->pinIn = pinIn;
    this->pinOut = pinOut;
    this->pinLed = pinLed;
    init();

    Button but[8];
    for(int i=0; i<8; i++) {
        int pos= i/2;
        but[i] = Button(buttonsCodes[i], pinIn[pos], pinOut[0], pinOut[1], pinLed[i]);
    }
    this->buttons = but;
}

void HandController::init() {
    pinMode(pinIn[0], INPUT);
    pinMode(pinIn[1], INPUT);
    pinMode(pinIn[2], INPUT);
    pinMode(pinIn[3], INPUT);
    pinMode(pinOut[0], OUTPUT);
    pinMode(pinOut[1], OUTPUT);
}


Button* HandController::getClosedButtonObj() {
    int counter = 0;
    int counterButtonsPressed = 0;
    //Button *buttonSelected;

    for(int i=0; i<8; i++) {
        if(buttons[i].isClosed()) {
            buttons[i].setLedOn();
      //      *buttonSelected = buttons[i];
            counterButtonsPressed++;
       }else {
            buttons[i].setLedOff();
       }
    }

//    if(counterButtonsPressed > 1 || counterButtonsPressed == 0) {
        return NULL;
  //  }

//    return buttonSelected;
}


int HandController::getClosedButton() {

    int threshold = 358;
    int counter = 0;
    int counterButtonsPressed = 0;
    int buttonSelected = 0;

    // emergency button (priority)
    digitalWrite(pinOut[0], HIGH);
    digitalWrite(pinOut[1], LOW);
    Serial.print(analogRead(pinIn[0]));
    Serial.println();
    if(analogRead(pinIn[0]) > threshold) {
        return BTN1_EMERGENCY;
    }

    for(int i=0; i<4; i++) {
        for(int j=0; j<2; j++) {
            digitalWrite(pinOut[((j+1)%2)], LOW);
            digitalWrite(pinOut[j], HIGH);
            Serial.print("reading ");
            Serial.print(i);
            Serial.print(" = ");
            Serial.print(analogRead(pinIn[i]));
            Serial.println();
            if(analogRead(pinIn[i]) > threshold) {
                buttonSelected = buttonsCodes[counter];
                counterButtonsPressed++;
            }
            counter++;
        }
    }

    if(counterButtonsPressed > 1 || counterButtonsPressed == 0) {
        return BTN0_NOT_PRESSED;
    }

    return buttonSelected;
}
