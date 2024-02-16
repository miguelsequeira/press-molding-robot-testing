#ifndef TESTS_MODULE_H
#define TESTS_MODULE_H
#include <Arduino.h>
class TestsModule {

  public:
    TestsModule();

    void run();
    void runSensors();
    void runActuators();
    void disableAll();
    void testLeds();
    void testInductiveSensor();
    void testEncoder();
    void testBrakeActuator();
    void testStepperYY();
    void testStepperZZ();
    void testLinearActuator();
    void testPushPullMotor();
    void testHandController();
    void testHandControllerObj();
    void testHandLeds();
};
#endif
