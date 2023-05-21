#include "RobotCar.h"
#include <Arduino.h>

RobotCar::RobotCar() {
}

void RobotCar::setup() {
  servo1.attach(10);
  servo1.write(90);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(i, OUTPUT);
  pinMode(STBY, OUTPUT);

  for (int i = 3; i < 9; i++) {
    pinMode(i, OUTPUT);
  }

  stop();
}

void RobotCar::loop() {
  servo1.write(90);
  delay(500);
  middleDistance = calculateDistance();

  if (middleDistance <= 20) {
    stop();
    delay(300);
    servo1.write(10);
    delay(1000);
    rightDistance = calculateDistance();
    delay(300);
    servo1.write(90);
    delay(1000);
    servo1.write(180);
    delay(1000);
    leftDistance = calculateDistance();
    delay(500);
    servo1.write(90);
    delay(1000);
    delay(500);
    servo1.write(90);
    delay(1000);

    if (rightDistance > leftDistance) {
      right();
      delay(360);
    } else if (rightDistance < leftDistance) {
      left();
      delay(360);
    } else if ((rightDistance <= 20) || (leftDistance <= 20)) {
      backward();
      delay(180);
    } else {
      forward();
    }
  } else {
    forward();
  }
}

void RobotCar::forward() {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, 1);
  analogWrite(PWMA, 100);
  digitalWrite(BIN1, 1);
  analogWrite(PWMB, 100);
  Serial.println("Forward");
}

void RobotCar::backward() {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, 0);
  analogWrite(PWMA, 100);
  digitalWrite(BIN1, 0);
  analogWrite(PWMB, 100);
  Serial.println("Backward");
}

void RobotCar::left() {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, 1);
  analogWrite(PWMA, 100);
  digitalWrite(BIN1, 0);
  analogWrite(PWMB, 100);
  Serial.println("Left");
}

void RobotCar::right() {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, 0);
  analogWrite(PWMA, 100);
  digitalWrite(BIN1, 1);
  analogWrite(PWMB, 100);
  Serial.println("Right");
}

void RobotCar::stop() {
  digitalWrite(STBY, LOW);
  digitalWrite(AIN1, 1);
  analogWrite(PWMA, 0);
  digitalWrite(BIN1, 1);
  analogWrite(PWMB, 0);
  Serial.println("STOP");
}

int RobotCar::calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float distance = pulseIn(echoPin, HIGH);
  distance = distance / 58;
  return (int)distance;
}
