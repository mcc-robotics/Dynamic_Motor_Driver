//
// Created by Geoff Berl on 3/3/17.
//

#include "InInDriver.h"


void InInDriver::setMotorACoastSpeed(char speed) {
  MotorDriver::setMotorACoastSpeed(speed);

  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // Drive one pin with PWM and the other low
    analogWrite(motorA->getPin1(), LOW);
    analogWrite(motorA->getPin2(), convertSpeed(motorA, speed) * -1);
  } else {
    // Drive one pin with PWM and the other low
    analogWrite(motorA->getPin1(), convertSpeed(motorA, speed));
    analogWrite(motorA->getPin2(), LOW);
  }
}

void InInDriver::setMotorABrakeSpeed(char speed) {
  MotorDriver::setMotorABrakeSpeed(speed);

  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // Drive one pin with PWM and the other high
    analogWrite(motorA->getPin1(), motorA->getMaxSpeed());
    analogWrite(motorA->getPin2(), motorA->getMaxSpeed() - (convertSpeed(motorA, speed) * -1));
  } else {
    // Drive one pin with PWM and the other high
    analogWrite(motorA->getPin1(), motorA->getMaxSpeed() - convertSpeed(motorA, speed));
    analogWrite(motorA->getPin2(), motorA->getMaxSpeed());
  }
}

void InInDriver::setMotorBCoastSpeed(char speed) {
  MotorDriver::setMotorBCoastSpeed(speed);

  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // Drive one pin with PWM and the other low
    analogWrite(motorB->getPin1(), LOW);
    analogWrite(motorB->getPin2(), convertSpeed(motorB, speed) * -1);
  } else {
    // Drive one pin with PWM and the other low
    analogWrite(motorB->getPin1(), convertSpeed(motorB, speed));
    analogWrite(motorB->getPin2(), LOW);
  }
}

void InInDriver::setMotorBBrakeSpeed(char speed) {
  MotorDriver::setMotorBBrakeSpeed(speed);

  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // Drive one pin with PWM and the other high
    analogWrite(motorB->getPin1(), motorB->getMaxSpeed());
    analogWrite(motorB->getPin2(), motorB->getMaxSpeed() - convertSpeed(motorB, speed) * -1);
  } else {
    // Drive one pin with PWM and the other high
    analogWrite(motorB->getPin1(), motorB->getMaxSpeed() - convertSpeed(motorB, speed));
    analogWrite(motorB->getPin2(), motorB->getMaxSpeed());
  }
}

void InInDriver::motorABrake() {
  MotorDriver::motorABrake();

  // Drive both pins high
  analogWrite(motorA->getPin1(), motorA->getMaxSpeed());
  analogWrite(motorA->getPin2(), motorA->getMaxSpeed());
}

void InInDriver::motorACoast() {
  MotorDriver::motorACoast();

  // Drive both pins low
  analogWrite(motorA->getPin1(), LOW);
  analogWrite(motorA->getPin2(), LOW);
}

void InInDriver::motorBBrake() {
  MotorDriver::motorBBrake();

  // Drive both pins high
  analogWrite(motorB->getPin1(), motorB->getMaxSpeed());
  analogWrite(motorB->getPin2(), motorB->getMaxSpeed());
}

void InInDriver::motorBCoast() {
  MotorDriver::motorBCoast();

  // Drive both pins low
  analogWrite(motorB->getPin1(), LOW);
  analogWrite(motorB->getPin2(), LOW);
}