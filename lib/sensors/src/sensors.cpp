#include "MCP9808.h"

int DATA_PIN = D0;
int CLOCK_PIN = D1;
byte ADDRESS_TEMP = 0x18;
MCP9808 tempSensor = MCP9808(ADDRESS_TEMP);

void sensorsSetup() {
  delay(500);
  tempSensor.begin();
  tempSensor.setResolution(MCP9808_SLOWEST);
}

float readTemp() {
  return tempSensor.getTemperature();
}
