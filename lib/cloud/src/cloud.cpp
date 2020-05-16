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
void pushTemp(float temp) {
  String Tempurature = String(temp);
  Particle.publish("Tempurature", Tempurature, PRIVATE);
}
