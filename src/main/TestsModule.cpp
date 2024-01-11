#include <Controllino.h>
#include "TestsModule.h"
#include "State.h"
#include "Led.h"
#include "InductiveSensor.h"
#include "Encoder.h"
#include "BrakeActuator.h"
#include "Stepper.h"


Led leds[] = {Led(CONTROLLINO_D0), Led(CONTROLLINO_D1), Led(CONTROLLINO_D2), Led(CONTROLLINO_D3), Led(CONTROLLINO_D4), Led(CONTROLLINO_D5), Led(CONTROLLINO_D6), Led(CONTROLLINO_D7),
              Led(CONTROLLINO_D8), Led(CONTROLLINO_D9), Led(CONTROLLINO_D10), Led(CONTROLLINO_D11), Led(CONTROLLINO_D12), Led(CONTROLLINO_D13), Led(CONTROLLINO_D14), Led(CONTROLLINO_D15),
              Led(CONTROLLINO_D16), Led(CONTROLLINO_D17), Led(CONTROLLINO_D18), Led(CONTROLLINO_D19), Led(CONTROLLINO_D20), Led(CONTROLLINO_D21), Led(CONTROLLINO_D22), Led(CONTROLLINO_D23)};

TestsModule::TestsModule() {
}

void TestsModule::run() {
      //testLeds();
//    testStepper();
//    testInductiveSensor();
//    testEncoder();
//    testBrakeActuator();
}

void TestsModule::testStepper() {
    Stepper stepper = Stepper(CONTROLLINO_D3, CONTROLLINO_D4, CONTROLLINO_D5);

    stepper.setEnabled(HIGH);
    stepper.setDirection(LOW);
    stepper.setAppliedPower(1);
    delay(2000);
    stepper.setAppliedPower(0);
    stepper.setDirection(HIGH);
    stepper.setAppliedPower(5);
    delay(2000);
}

void TestsModule::testBrakeActuator() {
    BrakeActuator breakActuator = BrakeActuator(CONTROLLINO_D0);

    int b = breakActuator.getAppliedPower();
    breakActuator.setDirection(3);
    breakActuator.setAppliedPower(12);
}

void TestsModule::testEncoder() {
    Encoder encoder = Encoder(CONTROLLINO_D0);

    int a = encoder.getRelativePosition();
    int b = encoder.getConstantSpeed();
    int c = encoder.getDirection();
    encoder.setDegreeFactor(1);
    encoder.setMultiplyFactor(2);
}

void TestsModule::testInductiveSensor() {
    InductiveSensor sensor = InductiveSensor(CONTROLLINO_D0);

    if(sensor.isClosed()) {
        Serial.println("Object Detected");
    }
}


void TestsModule::testLeds() {
    Led leds[] = {Led(CONTROLLINO_D0), Led(CONTROLLINO_D1), Led(CONTROLLINO_D2), Led(CONTROLLINO_D3), Led(CONTROLLINO_D4), Led(CONTROLLINO_D5), Led(CONTROLLINO_D6), Led(CONTROLLINO_D7),
              Led(CONTROLLINO_D8), Led(CONTROLLINO_D9), Led(CONTROLLINO_D10), Led(CONTROLLINO_D11), Led(CONTROLLINO_D12), Led(CONTROLLINO_D13), Led(CONTROLLINO_D14), Led(CONTROLLINO_D15),
              Led(CONTROLLINO_D16), Led(CONTROLLINO_D17), Led(CONTROLLINO_D18), Led(CONTROLLINO_D19), Led(CONTROLLINO_D20), Led(CONTROLLINO_D21), Led(CONTROLLINO_D22), Led(CONTROLLINO_D23)};

    for (int j = 7; j >= 0; j--) {
      for (int i = 0; i <= j; i++) {
        leds[i].on();
        delay(100);
        leds[i].off();
      }
      leds[j].on();
      delay(100);
    }
}
