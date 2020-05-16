#include "sensors.h"

tempSensor::tempSensor(uint8_t offset, char unitType) {
  MCP9808 device = MCP9808(offset + MCP9808_DEFAULT_ADDRESS);
  unit = unitType;
  if (!(unit != 'F' || unit != 'C')) {
    unit = 'C';
  };
}

void tempSensor::setup() {
  device.begin();
  device.setResolution(MCP9808_SLOWEST);
  temp = device.getTemperature();
}

float tempSensor::read() {
  temp = temp + (device.getTemperature() - temp) / filterRate;
  if (unit == 'C') {
    return temp;
  } else {
    return temp*1.8 + 32;
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
