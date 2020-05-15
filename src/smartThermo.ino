#include "display.h"
#include "sensors.h"

float temp;
bool heaterStatus;

tempSensor MCP = tempSensor(0, 'F');
unitStatus heater = unitStatus('h', A0);

void setup() {
  displaySetup();
}

void loop() {
  temp = MCP.read(); // Need to calibrate or replace??
  displayTemp(temp);
  displayStatus(heater.type, heater.read());
  delay(300);
}
