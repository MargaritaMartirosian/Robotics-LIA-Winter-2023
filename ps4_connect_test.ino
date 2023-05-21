#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

#include <BluetoothSerial.h>

#include <PS4Controller.h>

PS4Controller PS4;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (!PS4.connected()) {
    if (PS4.begin(SerialBT)) {
      Serial.println("PS4 connected");
    }
  } else {
    Serial.println("PS4 still connected");
  }
  delay(1000);
}
