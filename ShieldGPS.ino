
#include <SoftwareSerial.h>
static const int RXPin = 7, TXPin = 8;

SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(115200);
  ss.begin(9600);
}

void loop() {
  if (ss.available() > 0 ) {
    Serial.write(ss.read());
  }
}
