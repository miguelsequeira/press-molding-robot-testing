#include <Controllino.h>
#include "TestsModule.h"
#include "State.h"
#include "Led.h"
#include "InductiveSensor.h"
#include "Encoder.h"
#include "BrakeActuator.h"
#include "Stepper.h"
#include "LinearActuator.h"
#include "PushPullMotor.h"


Led leds[] = {Led(CONTROLLINO_D0), Led(CONTROLLINO_D1), Led(CONTROLLINO_D2), Led(CONTROLLINO_D3), Led(CONTROLLINO_D4), Led(CONTROLLINO_D5), Led(CONTROLLINO_D6), Led(CONTROLLINO_D7),
              Led(CONTROLLINO_D8), Led(CONTROLLINO_D9), Led(CONTROLLINO_D10), Led(CONTROLLINO_D11), Led(CONTROLLINO_D12), Led(CONTROLLINO_D13), Led(CONTROLLINO_D14), Led(CONTROLLINO_D15),
              Led(CONTROLLINO_D16), Led(CONTROLLINO_D17), Led(CONTROLLINO_D18), Led(CONTROLLINO_D19), Led(CONTROLLINO_D20), Led(CONTROLLINO_D21), Led(CONTROLLINO_D22), Led(CONTROLLINO_D23)};

Stepper stepperYY = Stepper(CONTROLLINO_D3, CONTROLLINO_D4, CONTROLLINO_D5);
Stepper stepperZZ = Stepper(CONTROLLINO_D0, CONTROLLINO_D1, CONTROLLINO_D2);
LinearActuator linearActuator = LinearActuator(CONTROLLINO_D6, CONTROLLINO_D7);
PushPullMotor pushPullMotor = PushPullMotor(CONTROLLINO_R14, CONTROLLINO_R15);
InductiveSensor sensor = InductiveSensor(CONTROLLINO_A1);



TestsModule::TestsModule() {
}

void TestsModule::run() {

    disableAll();

    testStepperYY();
    testStepperZZ();
    testLinearActuator();
    testPushPullMotor();


    //testInductiveSensor();
//    testEncoder();
//    testBrakeActuator();
}

void TestsModule::disableAll() {
  stepperYY.setEnabled(LOW);
  stepperZZ.setEnabled(LOW);
  linearActuator.setDirection(HIGH);
  pushPullMotor.setEnabled(LOW);
}

void TestsModule::testPushPullMotor() {
    pushPullMotor.setEnabled(HIGH);
    pushPullMotor.setDirection(LOW);
    delay(2000);
    pushPullMotor.setDirection(HIGH);
    delay(2000);
}

void TestsModule::testStepperYY() {

    stepperYY.setEnabled(HIGH);
    stepperYY.setDirection(LOW);
    stepperYY.setAppliedPower(1);
    delay(2000);
    stepperYY.setAppliedPower(5);
    stepperYY.setDirection(HIGH);
    delay(2000);
    stepperYY.setAppliedPower(0);
    stepperYY.setEnabled(LOW);
}


void TestsModule::testStepperZZ() {

    stepperZZ.setEnabled(HIGH);
    stepperZZ.setDirection(LOW);
    stepperZZ.setAppliedPower(1);
    delay(2000);
    stepperZZ.setAppliedPower(50);
    stepperZZ.setDirection(HIGH);
    delay(2000);
    stepperZZ.setAppliedPower(0);
    stepperZZ.setEnabled(LOW);
}

void TestsModule::testLinearActuator() {

    linearActuator.setEnabled(HIGH);
    linearActuator.setDirection(LOW);
    delay(2000);
    linearActuator.setEnabled(LOW);
    linearActuator.setDirection(LOW);
    delay(2000);

    linearActuator.setDirection(HIGH);
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
    if(sensor.isClosed()) {
        Serial.println("Object Detected");
    } else {
    }   Serial.println("Object Not Detected");
}


void TestsModule::testLeds() {

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
