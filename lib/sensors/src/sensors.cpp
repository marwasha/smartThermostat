#include "sensors.h"

tempSensor::tempSensor(uint8_t offset, char unitType) {
  MCP9808 device = MCP9808(offset + MCP9808_DEFAULT_ADDRESS);
  device.begin();
  device.setResolution(MCP9808_SLOWEST);
  unit = unitType;
  if (unit != 'F' || unit != 'C') {
    unit = 'C';
  };
}

float tempSensor::read() {
  if (unit == 'C') {
    return device.getTemperature();
  } else {
    return device.getTemperature()*1.8 + 32;
  }
}

unitStatus::unitStatus(char unitType, int pin) {
  type = unitType;
  inPin = pin;
  pinMode(pin, INPUT);
}

bool unitStatus::read() {
  if (analogRead(inPin) > 3460) {
    return false;
  } else {
    return true;
  };
}
