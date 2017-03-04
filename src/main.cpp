//
// Created by gberl on 2/28/2017.
//

#define PIN_1A    33
#define PIN_2A    34
#define PIN_3A    35
#define PIN_4A    36
#define PIN_EN12  37
#define PIN_EN34  38


#include <Arduino.h>
#include <DRV8835.h>

//DRV8835 driver(1, 2, 3, 4, IN_IN_MODE);

void setup() {
//  Serial.begin(115200);
//  while(!Serial.availableForWrite()) {} // Wait for serial communication

  Serial.println("Begin");

  pinMode(PIN_1A, OUTPUT);
  pinMode(PIN_2A, OUTPUT);
  pinMode(PIN_3A, OUTPUT);
  pinMode(PIN_4A, OUTPUT);
  pinMode(PIN_EN12, OUTPUT);
  pinMode(PIN_EN34, OUTPUT);
  digitalWrite(PIN_1A, LOW);
  digitalWrite(PIN_2A, LOW);
  digitalWrite(PIN_3A, LOW);
  digitalWrite(PIN_4A, HIGH);
  analogWrite(PIN_EN12, 0);
  analogWrite(PIN_EN34, 100);


}

void loop() {

}