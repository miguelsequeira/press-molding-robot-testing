#include <Controllino.h>
#include "TestsModule.h"
#include "Led.h"
#include "InductiveSensor.h"

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() {
    runTests();
}

void runTests() {
    TestsModule tests = TestsModule();
    tests.run();
}
