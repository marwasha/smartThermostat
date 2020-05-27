//NEED TO SET UP PROJECTED MCP9808 SENSOR CLASS WITHOUT BREAKING ABSTRACTION

#define thermA 0.001129148
#define thermB 0.000234125
#define thermC 0.0000000876741
#define thermVdiv 10000.0
#define thermADC 4096.0

class tempSensor {
  public:
    tempSensor(int pinSet, char unitType);
    void setup();
    float readFiltered();

  private:
    float read();
    int filterRate = 120;
    float temp;
    float tempFiltered;
    char unit;
    int pin;
};

class unitStatus {
  public:
    char type;
    unitStatus(char unitType, int pin);
    bool read();
  private:
    int inPin;
};
