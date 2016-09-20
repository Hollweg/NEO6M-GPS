<<<<<<< HEAD

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
=======
#include <SoftwareSerial.h>
#include <SD.h>

static const int RXPin = 7, TXPin = 8;
static const int chip_select = 10;
static short int button_SD = LOW;

SoftwareSerial ss(RXPin, TXPin);
String NMEA_protocol;

void setup() {
    Serial.begin(115200);
    ss.begin(9600);
    pinMode(9, INPUT);
    digitalWrite(button_SD, LOW);
    
testa_cartao:
  
    if (!SD.begin(chip_select)){
        Serial.println("Card Failed, or not present");
        if (button_SD == HIGH)
            goto cartao_ok;
        goto testa_cartao;  
    }

cartao_ok:
    
    File LogFile = SD.open("NMEALog.txt", FILE_WRITE);
    if (LogFile){
        Serial.println("SD card OK");
        LogFile.println("NMEA Sentences Acquisiton Log");
        LogFile.println("Created by Guilherme Hollweg");
        LogFile.println("Available on github.com/hollweg");
        LogFile.println("Last modification: 09/2016");
        LogFile.println(" ");
        LogFile.close();     
    }
    
    else{
        Serial.println ("SD card not OK!");
    }
}

void loop(){
  if (ss.available() > 0 ) {
    NMEA_protocol =  ss.readStringUntil('\n');
    File LogFile = SD.open("NMEALog.txt", FILE_WRITE);
    
    if (LogFile){
        LogFile.println(NMEA_protocol);
        LogFile.close();
    }
    
    else{
        Serial.println("Error opening NMEALog.txt!");
    }
>>>>>>> v2
  }
}
