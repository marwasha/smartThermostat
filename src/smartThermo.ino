#include "display.h"
#include "sensors.h"
#include "cloud.h"

#define sampleRateLocal .05 //Seconds
#define sampleRateWeb   16 //Seconds
#define sampleRatePull  13 //Seconds

bool pullRequested = false;
float temp;
float tempOut;
float ac = 0;
bool heaterStatus;
unsigned long lastTimeWeb = 0;
unsigned long lastTimeLocal = 0;

tempSensor tempurature = tempSensor(A2, 'C', sampleRateWeb/sampleRateLocal);
OWMWH      currentWeather = OWMWH();

void setup() {
  displaySetup();
  tempurature.setup();
  currentWeather.setup();
  delay(5000);
}

void loop() {
  unsigned long nowTime = millis();
  if ((nowTime - lastTimeLocal) >= sampleRateLocal*1000 | (nowTime - lastTimeLocal) < 0) {
    lastTimeLocal = nowTime; // This only triggers at 20Hz and avoids rollovers
    temp = tempurature.readFiltered();
    displayTemp(temp, 1, 0);
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
