#include <Obstacle.h>
#include <Servo.h>
#include <TFT.h>
#include <Wire.h>
#include <MOTOR.h>

// added NOT ORIGINAL
//#INCLUDE INFRARED FILE
bool Left,Down,Right,Up,Square,Cross,Circle,Triangle,L1,R1,L2,R2;
byte LStickY,LStickX;
//byte R2;
MOTOR motor(8, 7, 5, 6, 3); // NEW NOT ORIGINAL 

Servo myservo;


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  myservo.attach(11);


  Wire.begin(14);
  Wire.onReceive(receiveEvent);

  Serial.begin(115200);

  motor.init(); // NEW NOT ORIGINAL 
 
}

void loop() {

 // obstacle.update();
  /*Serial.print("LSX: ");
  Serial.print(LStickX);
  Serial.print("\t");
  Serial.print("LSY: ");
  Serial.print(LStickY);
  Serial.print("\t");
  Serial.print("LEFT: ");
  Serial.print(Left);
  Serial.print("\t");
  Serial.print("DOWN: ");
  Serial.print(Down);
  Serial.print("\t");
  Serial.print("RIGHT: ");
  Serial.print(Right);
  Serial.print("\t");
  Serial.print("UP: ");
  Serial.print(Up);
  Serial.print("\t");
  Serial.print("SQUARE: ");
  Serial.print(Square);
  Serial.print("\t");
  Serial.print("CROSS: ");
  Serial.print(Cross);
  Serial.print("\t");
  Serial.print("CIRCLE: ");
  Serial.print(Circle);
  Serial.print("\t");
  Serial.print("TRIANGLE: ");
  Serial.print(Triangle);
  Serial.print("\t");
  Serial.print("L1: ");
  Serial.print(L1);
  Serial.print("\t");
  Serial.print("R1: ");
  Serial.print(R1);
  Serial.print("\t");
  Serial.print("L2: ");
  Serial.print(L2);
  Serial.print("\t");
  Serial.print("R2: ");
  Serial.print(R2);
  Serial.print("\t");
  Serial.println();
  */
  // NOT ORIGINAL 
  
}// added


void receiveEvent(int bytes) {
  if (bytes == 14) {

    Left = Wire.read(); 
    Down = Wire.read(); 
    Right = Wire.read(); 
    Up = Wire.read(); 
    Square = Wire.read(); 
       if(Square==1){     
      motor.right();
    
    }
    Cross = Wire.read(); 
       if(Cross==1){     
      motor.backward();
    }
    Circle = Wire.read(); 
       if(Circle==1){     
      motor.left();
    }
    Triangle = Wire.read();
       if(Triangle==1){     
      motor.forward();
    }
    L1 = Wire.read(); 
      if(L1==1){     
      motor.Stop();
    }
    R1 = Wire.read(); 
    if(R1==1){
      motor.Boost();
    }
  
    L2 = Wire.read(); 
    if(L2==1){
      myservo.write(20);
    }else {
      myservo.write(90); // TOO VERIFY
    }

    R2 = Wire.read(); 
    if(R2==1){
      myservo.write(145);
    }
    LStickX=Wire.read();
    LStickY = Wire.read();
    
    
  }
}