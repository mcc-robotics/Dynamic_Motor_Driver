//
// Created by Geoff Berl on 3/11/17.
//

#include <Arduino.h>
#include "HBridgeMotor.h"

void HBridgeMotor::setCoastDrivePower(int8_t power) {
  _goalPower = power;

  // Set the direction
  if (power < 0) {
    digitalWrite(_pin1, HIGH);
    digitalWrite(_pin2, LOW);
    analogWrite(_enablePin, convertPower(power) * -1);
  } else {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, HIGH);
    analogWrite(_enablePin, convertPower(power));
  }
}

void HBridgeMotor::setBrakeDrivePower(int8_t power) {
  // HBridge doesn't support brake drive
  setCoastDrivePower(power);
}

void HBridgeMotor::brake() {
  _goalPower = 0;

  // Brake requires both inputs to be equal so we'll set them to low
  digitalWrite(_pin1, LOW);
  digitalWrite(_pin2, LOW);

  // Enable pin doesn't matter
}

void HBridgeMotor::coast() {
  _goalPower = 0;

  // To coast, we simply turn off the motor by setting enable to 0
  analogWrite(_enablePin, 0);
}