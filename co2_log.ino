#include <MHZ19.h>

#include <Arduino.h>
#include <MHZ19.h>

#define RX_PIN 10
#define TX_PIN 11
#define BAUDRATE 9600   

MHZ19 mhz19;
#include <SoftwareSerial.h>
SoftwareSerial mhz19_serial(RX_PIN, TX_PIN);

unsigned long timer = 0;
bool calibrate = false;

void setup() {
  Serial.begin(9600);
  mhz19_serial.begin(BAUDRATE);
  mhz19.begin(mhz19_serial);

  mhz19.autoCalibration(false);

  if (calibrate) {
    Serial.println("Calibrating..");
    mhz19.calibrate();
  }
}

void loop() {
  if (millis() - timer >= 2500) {
    int co2 = mhz19.getCO2(true);
    Serial.print(millis());
    Serial.print(",");
    Serial.println(mhz19.getCO2());

    timer = millis();
  }
}
