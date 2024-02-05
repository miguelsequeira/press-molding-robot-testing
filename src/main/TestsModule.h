#ifndef TESTS_MODULE_H
#define TESTS_MODULE_H
#include <Arduino.h>
class TestsModule {

  public:
    TestsModule();

    void run();
    void disableAll();
    void testLeds();
    void testInductiveSensor();
    void testEncoder();
    void testBrakeActuator();
    void testStepperYY();
    void testStepperZZ();
    void testLinearActuator();
    void testPushPullMotor();
};
#endif
