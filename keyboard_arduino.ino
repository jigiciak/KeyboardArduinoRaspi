#include <Keyboard.h>
#include <Wire.h>
#define SLAVE_ADDRESS 0x04
int inText = 0;
char outText;

void setup() {
  Keyboard.begin();
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
}

void loop() {
  delay(500);
}

void receiveData(int byteCount) {
  while (Wire.available()) {
    inText = Wire.read();
    outText = char(inText);
    Keyboard.print(outText);
    delay(100);
    Keyboard.releaseAll();
  }
}
