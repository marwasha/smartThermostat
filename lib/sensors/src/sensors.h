//NEED TO SET UP PROJECTED MCP9808 SENSOR CLASS WITHOUT BREAKING ABSTRACTION
#include "MCP9808.h"

class sensor {
  public:
    float read();
};

class tempSensor: public sensor {
  public:
    tempSensor(uint8_t offset);

    float read();

  protected:
    MCP9808 device;
};
