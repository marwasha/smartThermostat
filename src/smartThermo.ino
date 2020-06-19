#include "display.h"
#include "sensors.h"
#include "cloud.h"

#define sampleRateLocal .05 //Seconds
#define sampleRateWeb   30 //Seconds

float temp;
float tempOut;
bool heaterStatus;
unsigned long lastTimeWeb;
unsigned long lastTimeLocal;

tempSensor tempurature = tempSensor(A2, 'C', sampleRateWeb/sampleRateLocal);
//unitStatus heater = unitStatus('h', A1);
OWMWH      currentWeather = OWMWH();

void setup() {
  displaySetup();
  tempurature.setup();
  currentWeather.setup();
}

void loop() {
  unsigned long nowTime = millis();
  if ((nowTime - lastTimeLocal) >= sampleRateLocal*1000 | (nowTime - lastTimeLocal) < 0) {
    lastTimeLocal = nowTime;
    temp = tempurature.readFiltered(); // Need to calibrate or replace??
    displayTemp(temp, 1, 0);
  }

  if ((nowTime - lastTimeWeb) >= sampleRateWeb*1000 | (nowTime - lastTimeWeb) < 0) {
    lastTimeWeb = nowTime;
    tempOut = currentWeather.getOutsideTemp();
    displayTemp(tempOut, 0, 0);
    pushTemps(temp, tempOut);
  }

//  displayStatus(heater.type, heater.read());
}
