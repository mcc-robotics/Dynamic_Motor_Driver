//
// Created by Geoff Berl on 3/4/17.
//

#include "HBridgeDriver.h"

void HBridgeDriver::setMotorACoastSpeed(char speed) {
  MotorDriver::setMotorACoastSpeed(speed);

  // Set the direction
  if (speed < 0) {
    digitalWrite(motorA->getPin1(), HIGH);
    digitalWrite(motorA->getPin2(), LOW);
    analogWrite(motorAEnable, convertSpeed(motorA, speed) * -1);
  } else {
    digitalWrite(motorA->getPin1(), LOW);
    digitalWrite(motorA->getPin2(), HIGH);
    analogWrite(motorAEnable, convertSpeed(motorA, speed));
  }
}

void HBridgeDriver::setMotorABrakeSpeed(char speed) {
  // HBridge doesn't support brake
  setMotorACoastSpeed(speed);
}

void HBridgeDriver::setMotorBCoastSpeed(char speed) {
  MotorDriver::setMotorBCoastSpeed(speed);

  // Set the direction
  if (speed < 0) {
    digitalWrite(motorB->getPin1(), HIGH);
    digitalWrite(motorB->getPin2(), LOW);
    analogWrite(motorBEnable, convertSpeed(motorB, speed) * -1);
  } else {
    digitalWrite(motorB->getPin1(), LOW);
    digitalWrite(motorB->getPin2(), HIGH);
    analogWrite(motorBEnable, convertSpeed(motorB, speed));
  }
}

void HBridgeDriver::setMotorBBrakeSpeed(char speed) {
  // HBridge doesn't support brake
  setMotorBCoastSpeed(speed);
}

void HBridgeDriver::motorABrake() {
  MotorDriver::motorABrake();

  // Brake requires both inputs to be equal so we'll set them to low
  digitalWrite(motorA->getPin1(), LOW);
  digitalWrite(motorA->getPin2(), LOW);

  // Enable pin doesn't matter
}

void HBridgeDriver::motorACoast() {
  MotorDriver::motorACoast();

  // To coast, we simply turn off the motor by setting enable to 0
  analogWrite(motorAEnable, 0);
}

void HBridgeDriver::motorBBrake() {
  MotorDriver::motorBBrake();

  // Brake requires both inputs to be equal so we'll set them to low
  digitalWrite(motorB->getPin1(), LOW);
  digitalWrite(motorB->getPin2(), LOW);

  // Enable pin doesn't matter
}

void HBridgeDriver::motorBCoast() {
  MotorDriver::motorBCoast();

  // To coast, we simply turn off the motor by setting enable to 0
  analogWrite(motorBEnable, 0);
}
