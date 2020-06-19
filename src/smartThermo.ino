#include "display.h"
#include "sensors.h"
#include "cloud.h"

#define sampleRateLocal .05 //Seconds
#define sampleRateWeb   30 //Seconds
#define sampleRatePull  25 //Seconds

bool pullRequested = false;
float temp;
float tempOut;
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
    tempOut = currentWeather.getOutsideTemp();
  }

  if ((nowTime - lastTimeWeb) >= sampleRateWeb*1000 | (nowTime - lastTimeWeb) < 0) {
    lastTimeWeb = nowTime; // This only triggers at .03Hz and avoids rollovers

    displayTemp(tempOut, 0, 0);
    pushTemps(temp, tempOut);
    pullRequested = false;
  }
}
