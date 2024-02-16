#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Controllino.h>
#include <Encoder.h>
#include "TestsModule.h"
#include "State.h"
#include "Led.h"
#include "InductiveSensor.h"
#include "Encoder.h"
#include "BrakeActuator.h"
#include "Stepper.h"
#include "LinearActuator.h"
#include "PushPullMotor.h"
#include "HandController.h"


Led leds[] = {Led(CONTROLLINO_D8), Led(CONTROLLINO_D9), Led(CONTROLLINO_D10)};

Led handLeds[] = {Led(CONTROLLINO_D15), Led(CONTROLLINO_D16), Led(CONTROLLINO_D17), Led(CONTROLLINO_D18), Led(CONTROLLINO_D19), Led(CONTROLLINO_D20), Led(CONTROLLINO_D21), Led(CONTROLLINO_D22), Led(CONTROLLINO_D23)};

Stepper stepperYY = Stepper(CONTROLLINO_D3, CONTROLLINO_D4, CONTROLLINO_D5);
Stepper stepperZZ = Stepper(CONTROLLINO_D0, CONTROLLINO_D1, CONTROLLINO_D2);
LinearActuator linearActuator = LinearActuator(CONTROLLINO_D6, CONTROLLINO_D7);
PushPullMotor pushPullMotor = PushPullMotor(CONTROLLINO_R14, CONTROLLINO_R15);
InductiveSensor sensor = InductiveSensor(CONTROLLINO_A1);
BrakeActuator brakeActuator = BrakeActuator(CONTROLLINO_R12);
Encoder encoder = Encoder(CONTROLLINO_IN0, CONTROLLINO_IN1);

byte handControllerIns[] = {CONTROLLINO_A10, CONTROLLINO_A11, CONTROLLINO_A12, CONTROLLINO_A13};
byte handControllerOuts[] = {CONTROLLINO_D13, CONTROLLINO_D14};
byte handControllerLeds[] = {CONTROLLINO_D15, CONTROLLINO_D18, CONTROLLINO_D19, CONTROLLINO_D20, CONTROLLINO_D21, CONTROLLINO_D22, CONTROLLINO_D23};
HandController handController = HandController(handControllerIns, handControllerOuts, handControllerLeds);

TestsModule::TestsModule() {
}

void TestsModule::run() {
//
    disableAll();

    //runActuators();
    runSensors();
}


void TestsModule::runActuators() {
    testStepperYY();
//    testStepperZZ();
    testLinearActuator();
    testPushPullMotor();
    testBrakeActuator();
        
    testLeds();
}


void TestsModule::runSensors() {   
//    testInductiveSensor();
//    testEncoder();
    //testHandController();
    //testHandLeds();
    //testHandControllerObj();

}

void TestsModule::disableAll() {
    brakeActuator.setBrake(HIGH);
    stepperYY.setEnabled(LOW);
    stepperZZ.setEnabled(LOW);
    linearActuator.setEnabled(LOW);
    pushPullMotor.setEnabled(LOW);
}


void TestsModule::testHandController() {
    byte button = handController.getClosedButton();
     Serial.print("Button Pressed = ");
     Serial.print(button);
     Serial.println();
}


void TestsModule::testHandControllerObj() {
    Button* button = handController.getClosedButtonObj();
    if(false) {
        Serial.print("Button Pressed = ");
        Serial.print(button->getCode());
        Serial.println();
    } else {
        Serial.print("Button NOT Pressed");
    }
}

void TestsModule::testEncoder() {
    long positionLeft  = -999;
    long positionRight = -999;

   long newLeft, newRight;
   newLeft = encoder.read();
   if (newLeft != positionLeft ) {
     Serial.print("Encoder position = ");
     Serial.print(newLeft);
     Serial.println();
     positionLeft = newLeft;
   }
   // if a character is sent from the serial monitor,
   // reset both back to zero.
   if (Serial.available()) {
     Serial.read();
     Serial.println("Reset encoder back to zero");
     encoder.write(0);
   }
}

void TestsModule::testBrakeActuator() {
    brakeActuator.setBrake(HIGH);
    delay(2000);
    brakeActuator.setBrake(LOW);
    delay(2000);
}

void TestsModule::testPushPullMotor() {
    pushPullMotor.setEnabled(HIGH);
    pushPullMotor.setDirection(LOW);
    delay(2000);
    pushPullMotor.setDirection(HIGH);
    delay(2000);
    pushPullMotor.setEnabled(LOW);
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

    delay(2000);
    linearActuator.setEnabled(HIGH);
    linearActuator.setDirection(LOW);
    delay(2000);
    linearActuator.setEnabled(HIGH);
    linearActuator.setDirection(HIGH);
    delay(2000);

    linearActuator.setEnabled(LOW);
}
//
//void TestsModule::testEncoder() {
//    Encoder encoder = Encoder(CONTROLLINO_D0);
//
//    int a = encoder.getRelativePosition();
//    int b = encoder.getConstantSpeed();
//    int c = encoder.getDirection();
//    encoder.setDegreeFactor(1);
//    encoder.setMultiplyFactor(2);
//}

void TestsModule::testInductiveSensor() {
    if(sensor.isClosed()) {
        leds[2].on();
        Serial.println("Object Detected");
    } else {
        leds[2].off();
        Serial.println("Object Not Detected");
    }
}


void TestsModule::testLeds() {

    for (int i = 0; i <= 2; i++) {
      leds[i].on();
      delay(1000);
      leds[i].off();
    }
}


void TestsModule::testHandLeds() {

    for (int i = 0; i < 9; i++) {
      handLeds[i].on();
      delay(1000);
      handLeds[i].off();
    }
}
