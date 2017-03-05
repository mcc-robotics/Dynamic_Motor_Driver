//
// Created by Geoff Berl on 3/4/17.
//

#include "HBridgeDriver.h"

void HBridgeDriver::setMotorACoastSpeed(int8_t speed) {
  MotorDriver::setMotorACoastSpeed(speed);

  // Set the direction
  if (speed < 0) {
    digitalWrite(motorA->_pin1, HIGH);
    digitalWrite(motorA->_pin2, LOW);
    analogWrite(motorAEnable, convertSpeed(motorA, speed) * -1);
  } else {
    digitalWrite(motorA->_pin1, LOW);
    digitalWrite(motorA->_pin2, HIGH);
    analogWrite(motorAEnable, convertSpeed(motorA, speed));
  }
}

void HBridgeDriver::setMotorABrakeSpeed(int8_t speed) {
  // HBridge doesn't support brake
  setMotorACoastSpeed(speed);
}

void HBridgeDriver::setMotorBCoastSpeed(int8_t speed) {
  MotorDriver::setMotorBCoastSpeed(speed);

  // Set the direction
  if (speed < 0) {
    digitalWrite(motorB->_pin1, HIGH);
    digitalWrite(motorB->_pin2, LOW);
    analogWrite(motorBEnable, convertSpeed(motorB, speed) * -1);
  } else {
    digitalWrite(motorB->_pin1, LOW);
    digitalWrite(motorB->_pin2, HIGH);
    analogWrite(motorBEnable, convertSpeed(motorB, speed));
  }
}

void HBridgeDriver::setMotorBBrakeSpeed(int8_t speed) {
  // HBridge doesn't support brake
  setMotorBCoastSpeed(speed);
}

void HBridgeDriver::motorABrake() {
  MotorDriver::motorABrake();

  // Brake requires both inputs to be equal so we'll set them to low
  digitalWrite(motorA->_pin1, LOW);
  digitalWrite(motorA->_pin2, LOW);

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
  digitalWrite(motorB->_pin1, LOW);
  digitalWrite(motorB->_pin2, LOW);

  // Enable pin doesn't matter
}

void HBridgeDriver::motorBCoast() {
  MotorDriver::motorBCoast();

  // To coast, we simply turn off the motor by setting enable to 0
  analogWrite(motorBEnable, 0);
}
