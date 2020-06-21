#include "cloud.h"
#include "Particle.h"
#include "ArduinoJson.h"

OWMWH::OWMWH() {}

void OWMWH::setup() {
  Particle.subscribe("hook-response/outsideData", &OWMWH::subHand, this, MY_DEVICES);
  requestOutsideData();
}

void OWMWH::subHand(const char *event, const char *data) {
  const size_t capacity = JSON_OBJECT_SIZE(6) + 110;
  DynamicJsonDocument doc(capacity);
  deserializeJson(doc, data);
  outsideDataCur.temp = atof(doc["temp"]);
  outsideDataCur.windSpeed = atof(doc["windSpeed"]);
  outsideDataCur.cloudCov = atof(doc["cloudCov"])/100;
  float curTime = atof(doc["curTime"]);
  float sunrise = atof(doc["sunrise"]);
  float sunset = atof(doc["sunset"]);
  outsideDataCur.sun = (curTime - sunrise)/(sunset - sunrise);
  outsideDataCur.sun = (outsideDataCur.sun < 0) ? 0 : outsideDataCur.sun;
  outsideDataCur.sun = (outsideDataCur.sun > 1) ? 1 : outsideDataCur.sun;
  return;
}

void OWMWH::requestOutsideData() {
    Particle.publish("outsideData", "", PRIVATE);
}

void pushData(float temp, float ac, outsideData dataOut) {
  String data = String::format("{\"temp\":%.2f, \"tempOut\":%.2f, \"wind\":%.2f, \"cloud\":%.2f, \"sun\":%.2f, \"AC\":%.2f}",
                                temp, dataOut.temp, dataOut.windSpeed, dataOut.cloudCov, dataOut.sun, ac);
  Particle.publish("houseData", data, PRIVATE);
}
