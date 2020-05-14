#include "sensors.h"

tempSensor::tempSensor(uint8_t offset) {
  MCP9808 device = MCP9808(offset + MCP9808_DEFAULT_ADDRESS);
  device.begin();
  device.setResolution(MCP9808_SLOWEST);
}

float tempSensor::read() {
  return device.getTemperature();
}

unitStatus::unitStatus(char unitType, int pin) {
  type = unitType;
  inPin = pin;
  pinMode(pin, INPUT);
}

bool unitStatus::read() {
  return !digitalRead(inPin);
}
