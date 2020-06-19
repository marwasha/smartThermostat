#include "cloud.h"
#include "Particle.h"
#include "ArduinoJson.h"

OWMWH::OWMWH() {}

void OWMWH::setup() {
  Particle.subscribe("hook-response/outsideData", &OWMWH::subHand, this, MY_DEVICES);
  requestOT();
}

void OWMWH::subHand(const char *event, const char *data) {
  outsideDataCur = parseOutsideData(data);
}

outsideData OWMWH::parseOutsideData(const char *data) {
  const size_t capacity = JSON_OBJECT_SIZE(6) + 110;
  DynamicJsonDocument doc(capacity);
  deserializeJson(doc, json);
  outsideDataCur.temp = atof(doc["temp"]); // "28.06"
  outsideDataCur.windSpeed = atof(doc["windSpeed"]); // "0.75"
  outsideDataCur.cloudCov = atoi(doc["cloudCov"]); // "40"
  outsideDataCur.curTime = atoi(doc["curTime"]); // "1592582616"
  outsideDataCur.sunrise = atoi(doc["sunrise"]); // "1592560491"
  outsideDataCur.sunset = atoi(doc["sunset"]); // "1592615611"
}

void OWMWH::requestOT() {
  Particle.publish("outsideTemp", "", PRIVATE);
}

float OWMWH::getOutsideData() {
  requestOT();
  return outsideTemp;
}

void pushTemps(float temp, float tempOut) {
  String data = String::format("{\"temp\":%.2f, \"tempOut\":%.2f}",temp, tempOut);
  Particle.publish("Tempurature", data, PRIVATE);
}
