#include <Controllino.h>
#include "PushPullMotor.h"
PushPullMotor::PushPullMotor(byte forwardPin, byte backwardPin) {
  this->forwardPin = forwardPin;
  this->backwardPin = backwardPin;
  init();
}
void PushPullMotor::init() {
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
}

void PushPullMotor::setEnabled(int enabled) {
    // TODO: implement
    digitalWrite(forwardPin, enabled);
    digitalWrite(backwardPin, enabled);
}

void PushPullMotor::setDirection(int direction) {
    this->direction = direction;

    if(direction==LOW) {
        digitalWrite(forwardPin, LOW);
        digitalWrite(backwardPin, HIGH);  
    } else {
        digitalWrite(forwardPin, HIGH);
        digitalWrite(backwardPin, LOW);  
    }
    
}

void PushPullMotor::setAppliedPower(int appliedPower) {
    // TODO:implement
    this->appliedPower = appliedPower;
    //analogWrite(pulsePin, appliedPower);
}

int PushPullMotor::getAppliedPower() {
    return appliedPower;
}
