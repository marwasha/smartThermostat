//NEED TO SET UP PROJECTED MCP9808 SENSOR CLASS WITHOUT BREAKING ABSTRACTION
#include "MCP9808.h"

class sensor {
  public:
    float read();
};

class tempSensor: public sensor {
  public:
    tempSensor(uint8_t offset, char unitType);

    float read();

  private:
    MCP9808 device;
    char unit;
};

class unitStatus: public sensor {
  public:
    char type;
    unitStatus(char unitType, int pin);
    bool read();
  private:
    int inPin;
};
