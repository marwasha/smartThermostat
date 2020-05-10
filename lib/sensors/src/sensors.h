//NEED TO SET UP PROJECTED MCP9808 SENSOR CLASS WITHOUT BREAKING ABSTRACTION

class sensor {
  public:
    float read();
};

class tempSensor: public sensor {
  protected:
    MCP9808 device;

  public:
    tempSensor(uint8_t offset);

    float read();
};
