#include "display.h"
#include "sensors.h"
#include "cloud.h"

#define sampleRateLocal .05 //Seconds
#define sampleRateWeb   16 //Seconds
#define sampleRatePull  13 //Seconds

int acFilterRate = (sampleRateWeb/sampleRateLocal)/5;
bool pullRequested = false;
float temp;
float tempOut;
float ac = 0;
unsigned long lastTimeWeb = 0;
unsigned long lastTimeLocal = 0;

tempSensor tempurature = tempSensor(A2, 'C', sampleRateWeb/sampleRateLocal);
unitStatus acSensor = unitStatus(A1, 'A', acFilterRate);
OWMWH      currentWeather = OWMWH();


void setup() {
  displaySetup();
  acSensor.setup();
  tempurature.setup();
  currentWeather.setup();
  delay(5000);
}

void loop() {
  unsigned long nowTime = millis();
  if ((nowTime - lastTimeLocal) >= sampleRateLocal*1000 | (nowTime - lastTimeLocal) < 0) {
    lastTimeLocal = nowTime; // This only triggers at 20Hz and avoids rollovers
    temp = tempurature.readFiltered();
    ac = acSensor.readFiltered();
    displayTemp(temp, 1, 0);
    displayStatus(acSensor.type, ac);
  }

  if ((nowTime - lastTimeWeb) >= sampleRatePull*1000 & ~pullRequested) {
    pullRequested = true;
    currentWeather.requestOutsideData();
  }

  if ((nowTime - lastTimeWeb) >= sampleRateWeb*1000 | (nowTime - lastTimeWeb) < 0) {
    lastTimeWeb = nowTime; // This only triggers at a set freq and avoids rollovers
    displayTemp(currentWeather.outsideDataCur.temp, 0, 0);
    pushData(temp, ac, currentWeather.outsideDataCur);
    pullRequested = false;
  }
}
