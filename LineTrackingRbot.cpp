#include "LineTrackingRobot.h"
#include <Arduino.h>

LineTrackingRobot::LineTrackingRobot() {
}

void LineTrackingRobot::setup() {
  Serial.begin(9600);
  pinMode(L, INPUT);
  pinMode(M, INPUT);
  pinMode(R, INPUT);
  pinMode(STBY, OUTPUT);

  for (int i = 3; i < 9; i++) {
    pinMode(i, OUTPUT);
  }
}

void LineTrackingRobot::loop() {
  int leftV = analogRead(L);
  int centerV = analogRead(M);
  int rightV = analogRead(R);

  Serial.print("Left = ");
  Serial.println(leftV);
  Serial.print("\t");

  Serial.print("Center = ");
  Serial.print(centerV);
  Serial.print("\t");

  Serial.print("Right = ");
  Serial.print(rightV);
  Serial.print("\t");

  if ((centerV > 450) && (centerV < 550)) {
    forward();
  }
  if ((rightV > 450) && (rightV < 550)) {
    right();
  }
  if ((leftV > 450) && (leftV < 550)) {
    left();
  }
  if ((centerV > 950) && (rightV > 950) && (leftV > 950)) {
    stop();
  }
  if ((centerV < 40) && (rightV < 40) && (leftV < 40)) {
    stop();
  }
}

void LineTrackingRobot::forward() {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, 1);
  analogWrite(PWMA, 100);
  digitalWrite(BIN1, 1);
  analogWrite(PWMB, 100);
  delay(100);
}

void LineTrackingRobot::left() {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, 1);
  analogWrite(PWMA, 100);
  digitalWrite(BIN1, 0);
  analogWrite(PWMB, 100);
  delay(100);
}

void LineTrackingRobot::right() {
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, 0);
  analogWrite(PWMA, 100);
  digitalWrite(BIN1, 1);
  analogWrite(PWMB, 100);
  delay(100);
}

void LineTrackingRobot::stop() {
  digitalWrite(STBY, LOW);
  digitalWrite(AIN1, 1);
  analogWrite(PWMA, 0);
  digitalWrite(BIN1, 1);
  analogWrite(PWMB, 0);
  delay(100);
}
