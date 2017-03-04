//
// Created by gberl on 2/28/2017.
//

#define L298_1A     33
#define L298_2A     34
#define L298_EN12   35
#define DRV8835_1A  37
#define DRV8835_2A  36
#define DRV8835_MODE_PIN  38


#include <Arduino.h>
#include <DRV8835.h>
#include "L298.h"

L298 l298Driver(L298_1A, L298_2A, L298_EN12, 2, 2, 2);
DRV8835 drvDriver(DRV8835_1A, DRV8835_2A, 2, 2, DRV8835_MODE_PIN, PHASE_ENABLE_MODE);

void setup() {
//  Serial.begin(115200);
//  while(!Serial.availableForWrite()) {} // Wait for serial communication
//  Serial.println("Begin");

  delay(2000);

  l298Driver.setAllCoastSpeed(50);
  drvDriver.setAllCoastSpeed(50);
  delay(2000);
  l298Driver.coastAll();
  drvDriver.coastAll();
  delay(2000);
  l298Driver.setAllCoastSpeed(-50);
  drvDriver.setAllCoastSpeed(-50);
  delay(2000);
  l298Driver.coastAll();
  drvDriver.coastAll();


}

void loop() {

}