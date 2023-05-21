int LatchPin = 4;  // defines pin for the latch
int ShiftPin = 5;  // defines pin for shift 
int DataInput = 3; // defines pin for data input 
int digPins[4] = {13,12,11,10}; // has four dedicated common pins to control each digit separately 

const byte digits[10] = {  
  // defines an array of bytes that represent the pattern to light up each segment of a digit.
  B00111111,  // 0
  B00000110,  // 1
  B01011011,  // 2
  B01001111,  // 3
  B01100110,  // 4
  B01101101,  // 5
  B01111101,  // 6
  B0000111,   // 7
  B01111111,  // 8
  B01101111,  // 9
};

void setup() { // code run once 
  pinMode (LatchPin ,OUTPUT);
  pinMode (ShiftPin, OUTPUT);
  pinMode (DataInput, OUTPUT);
  pinMode (13, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (10, OUTPUT); 
}

void loop () { // code runs in a loop 

  digitalWrite (13, HIGH);
  digitalWrite (12, HIGH);
  digitalWrite (11, HIGH);
  digitalWrite (10 ,LOW);
  digitalWrite (LatchPin, LOW);
  shiftOut(DataInput, ShiftPin, MSBFIRST, digits[3]);
  digitalWrite (LatchPin, HIGH); 

  delay(5);

  digitalWrite (13, HIGH);
  digitalWrite (12, HIGH);
  digitalWrite (11,LOW);
  digitalWrite (10, HIGH);
  digitalWrite (LatchPin, LOW);
  shiftOut(DataInput, ShiftPin, MSBFIRST, digits[2]);
  digitalWrite (LatchPin, HIGH); 
  
  delay(5);
  
  digitalWrite (13, HIGH);
  digitalWrite (12, LOW);
  digitalWrite (11, HIGH);
  digitalWrite (10 ,HIGH);
  digitalWrite (LatchPin, LOW);
  shiftOut(DataInput, ShiftPin, MSBFIRST, digits[0]);
  digitalWrite (LatchPin, HIGH); 

  delay(5);

  digitalWrite (13, LOW);
  digitalWrite (12, HIGH);
  digitalWrite (11, HIGH);
  digitalWrite (10 ,HIGH);
  digitalWrite (LatchPin, LOW);
  shiftOut(DataInput, ShiftPin, MSBFIRST, digits[2]);
  digitalWrite (LatchPin, HIGH); 

  delay(5);
  
  
}