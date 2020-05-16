#include "cloud.h"
#include "Particle.h"
/*
void requestOutsideTemp(void) {
  Particle.publish("outsideTemp", "48105,us", PRIVATE);
}

void pullTempOutSetup(void) {
  Particle.subscribe("hook-response/outsideTemp", pullTempOut, MY_DEVICES);
}

void pullTempOut(const char *event, const char *data) {
  outsideTemp = atof(data);
}
*/

OWMWH::OWMWH() {
  Particle.subscribe("hook-response/outsideTemp", OWMWH::readOT, MY_DEVICES);
}

void OWMWH::readOT(const char *event, const char *data) {
  outsideTemp = atof(data);
}

void OWMWH::requestOT() {
  Particle.publish("outsideTemp", "", PRIVATE);
}

float OWMWH::getOutsideTemp() {
  requestOT();
  return outsideTemp;
}

void pushTemp(float temp) {
  String Tempurature = String(temp);
  Particle.publish("Tempurature", Tempurature, PRIVATE);
}
