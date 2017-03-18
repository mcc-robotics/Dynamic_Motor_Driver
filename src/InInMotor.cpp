//
// Created by Geoff Berl on 3/11/17.
//

#include <Arduino.h>
#include "InInMotor.h"

void InInMotor::setCoastDrivePower(int8_t power) {
  _goalPower = power;

  // Call the appropriate forward or reverse method
  if (power < 0) {
    // Drive one pin with PWM and the other low
    analogWrite(_pin1, LOW);
    analogWrite(_pin2, convertPower(power) * -1);
  } else {
    // Drive one pin with PWM and the other low
    analogWrite(_pin1, convertPower(power));
    analogWrite(_pin2, LOW);
  }
}

void InInMotor::setBrakeDrivePower(int8_t power) {
  _goalPower = power;

  // Call the appropriate forward or reverse method
  if (power < 0) {
    // Drive one pin with PWM and the other high
    analogWrite(_pin1, _pwmResolution);
    analogWrite(_pin2, _pwmResolution - (convertPower(power) * -1));
  } else {
    // Drive one pin with PWM and the other high
    analogWrite(_pin1, _pwmResolution - convertPower(power));
    analogWrite(_pin2, _pwmResolution);
  }
}

void InInMotor::brake() {
  _goalPower = 0;

  // Drive both pins high
  analogWrite(_pin1, _pwmResolution);
  analogWrite(_pin2, _pwmResolution);
}

void InInMotor::coast() {
  _goalPower = 0;

  // Drive both pins low
  analogWrite(_pin1, LOW);
  analogWrite(_pin2, LOW);
}