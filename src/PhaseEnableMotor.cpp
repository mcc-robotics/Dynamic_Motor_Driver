//
// Created by Geoff Berl on 3/11/17.
//

#include <Arduino.h>
#include "PhaseEnableMotor.h"

void PhaseEnableMotor::setCoastDrivePower(int8_t power) {
  // Phase Enable doesn't support coast drive
  setBrakeDrivePower(power);
}

void PhaseEnableMotor::setBrakeDrivePower(int8_t power) {
  _goalPower = power;

  // Call the appropriate forward or reverse method
  if (power < 0){
    // Drive phase high and enable PWM at specified speed
    digitalWrite(_pin1, HIGH);
    analogWrite(_pin2, convertPower(power) * -1);
  } else {
    // Drive phase low and enable PWM at specified speed
    digitalWrite(_pin1, LOW);
    analogWrite(_pin2, convertPower(power));
  }
}

void PhaseEnableMotor::brake() {
  _goalPower = 0;

  // Drive Enable low (stop PWM) (phase is irrelevant)
  analogWrite(_pin2, 0);
}

void PhaseEnableMotor::coast() {
  // Phase enable doesn't support coast
  brake();
}
