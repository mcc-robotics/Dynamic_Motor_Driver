//
// Created by Geoff Berl on 2/20/19.
//

#include "InInPWMMotor.h"


void InInPWMDriver::setCoastDrivePower(int8_t power) {
  // Brake mode is not supported, call brake power
  InInPWMDriver::setBrakeDrivePower(power);
}

void InInPWMDriver::setBrakeDrivePower(int8_t power) {
  // Call the appropriate forward or reverse method
  if (power < 0) {
    // (REVERSE) Drive one high, one low and drive PWM
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, HIGH);
    analogWrite(_motorPWM, convertPower(power) * -1);
  } else {
    // (FORWARD) Drive one high, one low and drive PWM
    digitalWrite(_pin1, HIGH);
    digitalWrite(_pin2, LOW);
    analogWrite(_motorPWM, convertPower(power));
  }
}

void InInPWMDriver::brake() {
  // Drive everything HIGH
  digitalWrite(_pin1, HIGH);
  digitalWrite(_pin2, HIGH);
  analogWrite(_motorPWM, _pwmResolution);
}

void InInPWMDriver::coast() {
  // Drive everything LOW
  digitalWrite(_pin1, LOW);
  digitalWrite(_pin2, LOW);
  analogWrite(_motorPWM, 0);
}