#include <PS4Controller.h>
#include <Wire.h>
unsigned long lastTimeStamp = 0;
#define SDA_PIN 21
#define SCL_PIN 19


void notify()
{
  char messageString[200];
  sprintf(messageString, "%4d,%4d,%4d,%4d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d",
  PS4.LStickX(),
  PS4.LStickY(),
  PS4.RStickX(),
  PS4.RStickY(),
  PS4.Left(),
  PS4.Down(),
  PS4.Right(),
  PS4.Up(),
  PS4.Square(),
  PS4.Cross(),
  PS4.Circle(),
  PS4.Triangle(),
  PS4.L1(),
  PS4.R1(),
  PS4.L2(),
  PS4.R2(),  
  PS4.Share(),
  PS4.Options(),
  PS4.PSButton(),
  PS4.Touchpad(),
  PS4.Charging(),
  PS4.Audio(),
  PS4.Mic(),
  PS4.Battery());

  //Only needed to print the message properly on serial monitor. Else we dont need it.
  if (millis() - lastTimeStamp > 50)
  {
    Serial.println(messageString);
    lastTimeStamp = millis();
  }
}

void onConnect()
{
  Serial.println("Connected!.");
}

void onDisConnect()
{
  Serial.println("Disconnected!.");    
}

void setup() 
{
  Serial.begin(115200);
  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisConnect);
  PS4.begin();
  Serial.println("Ready.");
   Wire.begin(SDA_PIN, SCL_PIN); 
}


void loop() 
{
  // send the values over I2C
  Wire.beginTransmission(14);
  Wire.write(PS4.Left());
  Wire.write(PS4.Down());
  Wire.write(PS4.Right());
  Wire.write(PS4.Up());
  Wire.write(PS4.Square());
  Wire.write(PS4.Cross());
  Wire.write(PS4.Circle());
  Wire.write(PS4.Triangle());
  Wire.write(PS4.L1());
  Wire.write(PS4.R1());
  Wire.write(PS4.L2());
  Wire.write(PS4.R2());
  Wire.write(PS4.LStickX());
  Wire.write(PS4.LStickY());
  Wire.endTransmission();

  // delay to avoid flooding the I2C bus
  delay(50);

}