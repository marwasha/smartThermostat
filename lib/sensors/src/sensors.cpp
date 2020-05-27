#include "sensors.h"
#include "math.h"
#include "application.h"


tempSensor::tempSensor(int pinSet, char unitType) {
  unit = unitType;
  if (!(unit != 'F' || unit != 'C')) {
    unit = 'C';
  };
  pin = pinSet;
}

void tempSensor::setup() {
  pinMode(pin, INPUT);
  temp = read();
}

float tempSensor::read() {
  int tempReading = analogRead(pin);
  double tempK = log(thermVdiv * (thermADC / tempReading - 1));
  tempK = 1 / (thermA + (thermB + (thermC * tempK * tempK ))* tempK );
  float temp = tempK - 273.15;
  if (unit == 'C') {
    return temp;
  } else {
    return temp*1.8 + 32;
  }
}

float tempSensor::readFiltered() {
  temp = temp + (read() - temp)/filterRate;
  return temp;
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
