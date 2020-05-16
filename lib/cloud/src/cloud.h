//float outsideTemp = 0;
/*
void requestOutsideTemp(void);
void pullTempOutSetup(void);
void pullTempOut(const char *event, const char *data);
*/


class OWMWH {
  public:
    OWMWH();
    float getOutsideTemp();

  private:
    float outsideTemp;
    void requestOT();
    void readOT(const char *event, const char *data);
};

void pushTemp(float temp);
