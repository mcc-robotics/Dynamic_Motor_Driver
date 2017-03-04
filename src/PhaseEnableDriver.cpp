//
// Created by Geoff Berl on 3/4/17.
//

#include "PhaseEnableDriver.h"

void PhaseEnableDriver::setMotorACoastSpeed(int8_t speed) {
  // Phase enable doesn't support coast
  setMotorABrakeSpeed(speed);
}

void PhaseEnableDriver::setMotorABrakeSpeed(int8_t speed) {
  if (speed < 0){
    // Drive phase high and enable PWM at specified speed
    digitalWrite(motorA->_pin1, HIGH);
    analogWrite(motorA->_pin2, speed);
  } else {
    // Drive phase low and enable PWM at specified speed
    digitalWrite(motorA->_pin1, LOW);
    analogWrite(motorA->_pin2, speed);
  }
}

void PhaseEnableDriver::setMotorBCoastSpeed(int8_t speed) {
  // Phase enable doesn't support coast
  setMotorBBrakeSpeed(speed);
}

void PhaseEnableDriver::setMotorBBrakeSpeed(int8_t speed) {
  if (speed < 0){
    // Drive phase high and enable PWM at specified speed
    digitalWrite(motorB->_pin1, HIGH);
    analogWrite(motorB->_pin2, speed);
  } else {
    // Drive phase low and enable PWM at specified speed
    digitalWrite(motorB->_pin1, LOW);
    analogWrite(motorB->_pin2, speed);
  }
}

void PhaseEnableDriver::motorABrake() {
  // Drive Enable low (stop PWM) (phase is irrelevant)
  analogWrite(motorA->_pin2, 0);
}

void PhaseEnableDriver::motorACoast() {
  // Phase enable doesn't support coast
  motorABrake();
}

void PhaseEnableDriver::motorBBrake() {
  // Drive Enable low (stop PWM) (phase is irrelevant)
  analogWrite(motorB->_pin2, 0);
}

void PhaseEnableDriver::motorBCoast() {
  // Phase enable doesn't support coast
  motorBBrake();
}
