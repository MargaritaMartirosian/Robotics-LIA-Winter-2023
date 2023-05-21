/*
 * CPP file of Motor class 
 */
// --------------------------- ( CPP ) ----------------------------------
#include "motor.h"   // include library created
//#include <Arduino.h> // include Arduino library 

MOTOR::MOTOR(int ain1, int bin1, int pwma, int pwmb, int stby)
  : AIN1(ain1), BIN1(bin1), PWMA(pwma), PWMB(pwmb), STBY(stby) {}
  // constructor definition for the MOTOR class
  // initialize member variables
//-------------------------INITIALISATION-------------------------
  void MOTOR::init() {
  for (int i = 3; i < 9; i++) {
    pinMode(i, OUTPUT);// i variable is set as ans OUTPUT
  }
  pinMode(STBY, OUTPUT);//STBY pin is set as an OUTPUT 
}

//-------------------------FUNCTIONS-------------------------
void MOTOR::forward () {  // details for forward function
  digitalWrite(STBY,HIGH);// STBY pin 3 is ON
  digitalWrite(AIN1, 1);  // Motor 1 clockwise direction 
  analogWrite(PWMA, 100); // Speed is 100
  digitalWrite(BIN1, 1);  // Motor 2 clockwise direction 
  analogWrite(PWMB, 100); // Speed is 100
  delay(100);
}
void MOTOR::backward() {  // details for backward function                        
  digitalWrite(STBY,HIGH);// STBY pin 3 is ON
  digitalWrite(AIN1, 0);  // Motor 1 counterclockwise direction 
  analogWrite(PWMA, 100); // Speed is 100
  digitalWrite(BIN1, 0);  // Motor 2 counterclockwise direction 
  analogWrite(PWMB, 100); // Speed is 100
  delay(100);
}
void MOTOR::left() {            // details for left function
  digitalWrite(STBY,HIGH);// STBY pin 3 is ON
  digitalWrite(AIN1, 1);  // Motor 1 clockwise direction 
  analogWrite(PWMA, 100); // Speed is 100
  digitalWrite(BIN1, 0);  // Motor 2 counterclockwise direction 
  analogWrite(PWMB, 100); // Speed is 100
  delay(100);
}
void MOTOR::right () {           // details for right function
  digitalWrite(STBY,HIGH);// STBY pin 3 is ON
  digitalWrite(AIN1, 0);  // Motor 1 counterclockwise direction 
  analogWrite(PWMA, 100); // Speed is 100
  digitalWrite(BIN1, 1);  // Motor 2 clockwise direction 
  analogWrite(PWMB, 100); // Speed is 100
  delay(100);
}
void MOTOR::left_forward () {    // details for left forward function
  digitalWrite(STBY,HIGH);// STBY pin 3 is ON
  digitalWrite(AIN1, 1);  // Motor 1 clockwise direction 
  analogWrite(PWMA, 100); // Speed is 100
  digitalWrite(BIN1, 1);  // Motor 2 clockwise direction 
  analogWrite(PWMB, 50);  // Speed is half of 100
  delay(100);
}
void MOTOR::left_backward () {   // details for left backward function
  digitalWrite(STBY,HIGH);// STBY pin 3 is ON
  digitalWrite(AIN1, 0);  // Motor 1 counterclockwise direction 
  analogWrite(PWMA, 100); // Speed is 100
  digitalWrite(BIN1, 0);  // Motor 2 counterclockwise direction 
  analogWrite(PWMB, 50);  // Speed is half of 100
  delay(100);
}

void MOTOR::right_forward () {   // details for right forward function
  digitalWrite(STBY,HIGH);// STBY pin 3 is ON
  digitalWrite(AIN1, 1);  // Motor 1 clockwise direction  
  analogWrite(PWMA, 50);  // Speed is half of 100
  digitalWrite(BIN1, 1);  // Motor 2 clockwise direction 
  analogWrite(PWMB, 100); // Speed is 100
  delay(100);
}

void MOTOR::right_backward () {  // details for right backward function
  digitalWrite(STBY,HIGH);// STBY pin 3 is ON
  digitalWrite(AIN1, 0);  // Motor 1 counterclockwise direction 
  analogWrite(PWMA, 50);  // Speed is half of 100
  digitalWrite(BIN1, 0);  // Motor 2 counterclockwise direction 
  analogWrite(PWMB, 100); // Speed is 100
  delay(100);
}
void MOTOR::Boost(){
  digitalWrite(STBY,HIGH); // STBY pin 3 is OFF
  digitalWrite(AIN1, 1);  // Motor 1 clockwise direction 
  analogWrite(PWMA, 255);   // Speed is 0 
  digitalWrite(BIN1, 1);  // Motor 2 clockwise direction 
  analogWrite(PWMB, 255);   // Speed is 0
 // delay(100);
}

void MOTOR::Stop () {     // datails for stop function
  digitalWrite(STBY,LOW); // STBY pin 3 is OFF
  digitalWrite(AIN1, 1);  // Motor 1 clockwise direction 
  analogWrite(PWMA, 0);   // Speed is 0 
  digitalWrite(BIN1, 1);  // Motor 2 clockwise direction 
  analogWrite(PWMB, 0);   // Speed is 0
  delay(100);
}
