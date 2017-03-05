//
// Created by Geoff Berl on 3/4/17.
//

#include "PhaseEnableDriver.h"

void PhaseEnableDriver::setMotorACoastSpeed(char speed) {
  // Phase enable doesn't support coast
  setMotorABrakeSpeed(speed);
}

void PhaseEnableDriver::setMotorABrakeSpeed(char speed) {
  MotorDriver::setMotorABrakeSpeed(speed);

  if (speed < 0){
    // Drive phase high and enable PWM at specified speed
    digitalWrite(motorA->getPin1(), HIGH);
    analogWrite(motorA->getPin2(), convertSpeed(motorA, speed) * -1);
  } else {
    // Drive phase low and enable PWM at specified speed
    digitalWrite(motorA->getPin1(), LOW);
    analogWrite(motorA->getPin2(), convertSpeed(motorA, speed));
  }
}

void PhaseEnableDriver::setMotorBCoastSpeed(char speed) {
  // Phase enable doesn't support coast
  setMotorBBrakeSpeed(speed);
}

void PhaseEnableDriver::setMotorBBrakeSpeed(char speed) {
  MotorDriver::setMotorBBrakeSpeed(speed);

  if (speed < 0){
    // Drive phase high and enable PWM at specified speed
    digitalWrite(motorB->getPin1(), HIGH);
    analogWrite(motorB->getPin2(), convertSpeed(motorB, speed) * -1);
  } else {
    // Drive phase low and enable PWM at specified speed
    digitalWrite(motorB->getPin1(), LOW);
    analogWrite(motorB->getPin2(), convertSpeed(motorB, speed));
  }
}

void PhaseEnableDriver::motorABrake() {
  MotorDriver::motorABrake();

  // Drive Enable low (stop PWM) (phase is irrelevant)
  analogWrite(motorA->getPin2(), 0);
}

void PhaseEnableDriver::motorACoast() {
  // Phase enable doesn't support coast
  motorABrake();
}

void PhaseEnableDriver::motorBBrake() {
  MotorDriver::motorBBrake();

  // Drive Enable low (stop PWM) (phase is irrelevant)
  analogWrite(motorB->getPin2(), 0);
}

void PhaseEnableDriver::motorBCoast() {
  // Phase enable doesn't support coast
  motorBBrake();
}
