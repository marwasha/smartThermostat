#include "cloud.h"
#include "Particle.h"

void pushTemp(float temp) {
  String Tempurature = String(temp);
  Particle.publish("Tempurature", Tempurature, PRIVATE);
}
