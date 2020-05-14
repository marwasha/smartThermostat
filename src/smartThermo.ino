#include "display.h"
#include "sensors.h"

float temp;
bool heaterStatus;

tempSensor MCP = tempSensor(0);
unitStatus heater = unitStatus('h', A0);

void setup() {
  displaySetup();
}

void loop() {
  temp = MCP.read()*1.8 + 32;
  displayTemp(temp);
  displayStatus(heater.type, heater.read());
  delay(250);
}
