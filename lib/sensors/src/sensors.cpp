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
  float tempStart = device.getTemperature();
  for (int i = 0; i++; i < (sizeof(temp)/(sizeof(temp[0])))) {
    temp[i] = tempStart;
  }
  tempAverage = tempStart;
  index = 0;
}

float tempSensor::read() {
  tempAverage -= temp[index]/tempARRAYSIZE;
  temp[index] = device.getTemperature();
  tempAverage += temp[index]/tempARRAYSIZE;
  if (unit == 'C') {
    return tempAverage;
  } else {
    return tempAverage*1.8 + 32;
  }
  index = (index + 1) % tempARRAYSIZE;
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
