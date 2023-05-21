#ifndef LINETRACKINGROBOT_H
#define LINETRACKINGROBOT_H

class LineTrackingRobot {
  public:
    LineTrackingRobot();
    void setup();
    void loop();

  private:
    void forward();
    void left();
    void right();
    void stop();

    int L;
    int M;
    int R;
    int const AIN1 = 8;
    int const PWMA = 5;
    int const BIN1 = 7;
    int const PWMB = 6;
    int STBY = 3;
};

#endif
