#include <Controllino.h>  /* Usage of CONTROLLINO library allows you to use CONTROLLINO_xx aliases in your sketch. */
#include "Led.h"

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
}


Led leds[] = {Led(CONTROLLINO_D0), Led(CONTROLLINO_D1), Led(CONTROLLINO_D2), Led(CONTROLLINO_D3), Led(CONTROLLINO_D4), Led(CONTROLLINO_D5), Led(CONTROLLINO_D6), Led(CONTROLLINO_D7),
              Led(CONTROLLINO_D8), Led(CONTROLLINO_D9), Led(CONTROLLINO_D10), Led(CONTROLLINO_D11), Led(CONTROLLINO_D12), Led(CONTROLLINO_D13), Led(CONTROLLINO_D14), Led(CONTROLLINO_D15),
              Led(CONTROLLINO_D16), Led(CONTROLLINO_D17), Led(CONTROLLINO_D18), Led(CONTROLLINO_D19), Led(CONTROLLINO_D20), Led(CONTROLLINO_D21), Led(CONTROLLINO_D22), Led(CONTROLLINO_D23)};


void loop() {
 
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
