/*
 * HEADER file of Motor class 
 */
//--------------------------- ( HEADER ) -----------------------------------------------
#ifndef MOTOR_H      //if not defined 
#define MOTOR_H      //define the MOTOR_H header file
#include <Arduino.h>; // include Arduino library 
//------------------- ----------CLASS ----------------------------
class MOTOR { // class 
//------------------- ENCAPSULATION/CONSTRUCTOR ------------------
  private:
    int AIN1; // Motor A
    int BIN1; // Motor B
    int PWMA; // Speed for Motor A
    int PWMB; // Speed for Motor B
    int STBY; // STBY pin 3 on Arduino Uno used for direction

  public:
    MOTOR(int ain1, int bin1, int pwma, int pwmb, int stby);
    void init(); // initalisation function 
    void forward(); // forward function
    void backward(); // backward function
    void left();
    void right();
    void left_forward();
    void left_backward();
    void right_forward();
    void right_backward();
    void Boost();
    void Stop(); // stop function
};

#endif
