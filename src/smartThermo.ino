#include "display.h"
#include "sensors.h"
#include "cloud.h"

float temp;
bool heaterStatus;
unsigned long lastTime;

tempSensor MCP = tempSensor(0, 'F');
unitStatus heater = unitStatus('h', A0);

void setup() {
  displaySetup();
}

void loop() {
  temp = MCP.read(); // Need to calibrate or replace??
  displayTemp(temp);

  unsigned long nowTime = millis();
  if ((nowTime - lastTime) >= 30*1000) {
    lastTime = nowTime;
    pushTemp(temp);
  }

  displayStatus(heater.type, heater.read());
  delay(300);
}
