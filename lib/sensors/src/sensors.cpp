#include "sensors.h"
#include "math.h"
#include "application.h"


tempSensor::tempSensor(int pinSet, char unitType, int filterRateSet) {
  unit = unitType;
  if (!(unit != 'F' || unit != 'C')) {
    unit = 'C';
  };
  pin = pinSet;
  filterRate = filterRateSet;
}

void tempSensor::setup() {
  pinMode(pin, INPUT);
  temp = read();
}

float tempSensor::read() {
  int v0 = analogRead(pin);
  float R2 = thermVdiv*(thermADC/(float)v0 - 1);
  float logR2 = log(R2);
  float tempK = 1/(thermA + (thermB + (thermC*logR2*logR2))*logR2);
  float tempC = tempK - 273.15;
  if (unit == 'C') {
    return tempC;
  } else {
    return tempC*1.8 + 32;
  }
}

float tempSensor::readFiltered() {
  temp = temp + (read() - temp)/filterRate;
  return temp;
}

unitStatus::unitStatus(int pinSet, char unitType, int filterRateSet) {
  type = unitType;
  pin = pinSet;
  filterRate = filterRateSet;
}

void unitStatus::setup() {
  pinMode(pin, INPUT);
  status = read();
}

float unitStatus::readFiltered() {
  status = status + (read() - status)/filterRate;
  return status;
}

bool unitStatus::read() {
  if (analogRead(pin) > 4098/2) {
    return false;
  } else {
    return true;
  };
}
