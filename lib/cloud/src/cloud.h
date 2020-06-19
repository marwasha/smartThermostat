struct outsideData {
  float temp;
  float windSpeed;
  int   cloudCov:
  int   time;
  int   sunrise;
  int   sunset;
}

class OWMWH {
  public:
    OWMWH();
    float getOutsideData();
    void setup();

  private:
    outsideData outsideDataCur;
    void requestOT();
    void subHand(const char *event, const char *data);
    outsideData parseOutsideData(const char *data);
};

void pushTemps(float temp, float tempOut);
