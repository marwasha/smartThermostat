#include "cloud.h"
#include "Particle.h"

OWMWH::OWMWH() {}

void OWMWH::setup() {
  Particle.subscribe("hook-response/outsideTemp", &OWMWH::subHand, this, MY_DEVICES);
  requestOT();
}

void OWMWH::subHand(const char *event, const char *data) {
  outsideTemp = atof(data);
}

void OWMWH::requestOT() {
  Particle.publish("outsideTemp", "", PRIVATE);
}

float OWMWH::getOutsideTemp() {
  requestOT();
  return outsideTemp;
}

void pushTemps(float temp, float tempOut) {
  String data = String::format("{\"temp\":%.2f, \"tempOut\":%.2f}",temp, tempOut);
  Particle.publish("Tempurature", data, PRIVATE);
}
