#include "display.h"
#include "sensors.h"

float temp;

void setup() {
  displaySetup();
  sensorsSetup();
}

void loop() {
  temp = readTemp()*1.8 + 32;
  displayTemp(temp);
  delay(250);
}
