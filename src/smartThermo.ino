#include "display.h"
#include "sensors.h"
#include "cloud.h"

float temp;
float tempOut;
bool heaterStatus;
unsigned long lastTime;

tempSensor tempurature = tempSensor(A2, 'C');
unitStatus heater = unitStatus('h', A1);
OWMWH      currentWeather = OWMWH();

void setup() {
  displaySetup();
  tempurature.setup();
  currentWeather.setup();
}

void loop() {
  temp = tempurature.readFiltered(); // Need to calibrate or replace??
  displayTemp(temp, 1, 0);

  unsigned long nowTime = millis();
  if ((nowTime - lastTime) >= 30*1000) {
    lastTime = nowTime;
    tempOut = currentWeather.getOutsideTemp();
    displayTemp(tempOut, 0, 0);
    pushTemps(temp, tempOut);
  }

  displayStatus(heater.type, heater.read());
  delay(250);
}
