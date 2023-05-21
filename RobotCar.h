#ifndef ROBOTCAR_H
#define ROBOTCAR_H

#include <Servo.h>

class RobotCar {
  public:
    RobotCar();
    void setup();
    void loop();

  private:
    void forward();
    void backward();
    void left();
    void right();
    void stop();
    int calculateDistance();

    Servo servo1;
    const int echoPin = 12;
    const int trigPin = 13;
    long duration;
    int distance;
    int const AIN1 = 8;
    int const PWMA = 5;
    int const BIN1 = 7;
    int const PWMB = 6;
    int i;
    int STBY = 3;
    int rightDistance, leftDistance, middleDistance;
};

#endif
