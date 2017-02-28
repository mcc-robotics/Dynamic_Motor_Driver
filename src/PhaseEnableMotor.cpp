//
// Created by gberl on 2/28/2017.
//

#include "PhaseEnableMotor.h"

void PhaseEnableMotor::forwardBrake(uint8_t speed) {
  // Drive phase low and enable PWM at specified speed
  digitalWrite(_pin1, LOW);
  analogWrite(_pin2, speed);
}

void PhaseEnableMotor::forwardCoast(uint8_t speed) {
  // Phase enable doesn't support coast
  forwardBrake(speed);
}

void PhaseEnableMotor::reverseBrake(uint8_t speed) {
  // Drive phase high and enable PWM at specified speed
  digitalWrite(_pin1, HIGH);
  analogWrite(_pin2, speed);
}

void PhaseEnableMotor::reverseCoast(uint8_t speed) {
  // Phase enable doesn't support coast
  reverseBrake(speed);
}

void PhaseEnableMotor::brake() {
  // Drive Enable low (stop PWM) (phase is irrelevant)
  analogWrite(_pin2, 0);
}

void PhaseEnableMotor::coast() {
  // Phase enable doesn't support coast
  brake();
}