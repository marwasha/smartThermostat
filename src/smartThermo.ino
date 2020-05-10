#include "display.h"
#include "sensors.h"

float temp;
tempSensor MCP = tempSensor(0);

void setup() {
  displaySetup();

}

void loop() {
  temp = MCP.read()*1.8 + 32;
  displayTemp(temp);
  delay(250);
}
