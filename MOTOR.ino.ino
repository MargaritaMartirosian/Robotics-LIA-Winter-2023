/*
 * MAIN file of Motor class 
 */
//--------------------------- ( MAIN ) -------------------------------
#include <Arduino.h> // include Arduino library
#include "MOTOR.h"   // include library created 
//-----DEFINE PINS/OBJECT--------
#define AIN1 8 // pin 8 on arduino is connected to motor A
#define BIN1 7 // pin 7 on arduino is connected to motor B
#define PWMA 5 // pin 5 on arduino is connected to motor A
#define PWMB 6 // pin 6 on arduino is connected to motor B 
#define STBY 3 // STBY pin 3 on Arduino Uno used for direction

MOTOR Motor(AIN1, BIN1, PWMA, PWMB, STBY);
//---------SETUP--------
void setup() {
  Motor.init(); // function called within the setup
}
//---------LOOP---------
void loop() {        // code runs in a loop
  Motor.forward ();  // forward function 
  delay(1000);       // program stops for 1 second 
  Motor.backward (); // backward function
  delay(1000);       // program stops for 1 second 
  Motor.left();
  delay(1000);
  Motor.right();
  delay(1000);
  Motor.left_forward();
  delay(1000);
  Motor.left_backward();
  delay(1000);
  Motor.right_forward();
  delay(1000);
  Motor.right_backward();
  delay(1000);
  Motor.Stop(); 
  delay(5000);
}
