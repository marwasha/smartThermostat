#include cloud.h

void pushTemp(float temp) {
  String Tempurature = String(temp);
  Particle.publish("Tempurature", Tempurature, PRIVATE);
}
