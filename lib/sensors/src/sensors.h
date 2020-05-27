//NEED TO SET UP PROJECTED MCP9808 SENSOR CLASS WITHOUT BREAKING ABSTRACTION

#define thermA 1.149074145/1000
#define thermB 2.307683271/10000
#define thermC 1.017352663/10000000
#define thermVdiv 10000.0
#define thermADC 4095.0

class tempSensor {
  public:
    tempSensor(int pinSet, char unitType, int filterRateSet);
    void setup();
    float readFiltered();

  private:
    float read();
    int filterRate;
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
