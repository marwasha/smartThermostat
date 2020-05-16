class OWMWH {
  public:
    OWMWH();
    float getOutsideTemp();
    void setup();

  private:
    float outsideTemp;
    void requestOT();
    void subHand(const char *event, const char *data);
};

void pushTemps(float temp, float tempOut);
