struct outsideData {
  float temp;
  float windSpeed;
  float cloudCov;
  float sun;
};

class OWMWH {
  public:
    OWMWH();
    void requestOutsideData();
    void setup();
    outsideData outsideDataCur;

  private:
    void subHand(const char *event, const char *data);
};

void pushData(float temp, float ac, outsideData dataOut);
