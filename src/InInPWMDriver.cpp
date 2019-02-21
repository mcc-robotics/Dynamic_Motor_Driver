//
// Created by Geoff Berl on 2/20/19.
//

#include "InInPWMDriver.h"


void InInPWMDriver::setMotorACoastSpeed(int8_t speed) {
  // Brake mode is not supported, call brake speed
  InInPWMDriver::setMotorABrakeSpeed(speed);
}

void InInPWMDriver::setMotorABrakeSpeed(int8_t speed) {
  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // (REVERSE) Drive one high, one low and drive PWM
    digitalWrite(motorA->_pin1, LOW);
    digitalWrite(motorA->_pin2, HIGH);
    analogWrite(motorAPWM, convertSpeed(motorA, speed) * -1);
  } else {
    // (FORWARD) Drive one high, one low and drive PWM
    digitalWrite(motorA->_pin1, HIGH);
    digitalWrite(motorA->_pin2, LOW);
    analogWrite(motorAPWM, convertSpeed(motorA, speed));
  }
}

void InInPWMDriver::setMotorBCoastSpeed(int8_t speed) {
  // Brake mode is not supported, call brake speed
  InInPWMDriver::setMotorBBrakeSpeed(speed);
}

void InInPWMDriver::setMotorBBrakeSpeed(int8_t speed) {
  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // (REVERSE) Drive one high, one low and drive PWM
    digitalWrite(motorB->_pin1, LOW);
    digitalWrite(motorB->_pin2, HIGH);
    analogWrite(motorBPWM, convertSpeed(motorB, speed) * -1);
  } else {
    // (FORWARD) Drive one high, one low and drive PWM
    digitalWrite(motorB->_pin1, HIGH);
    digitalWrite(motorB->_pin2, LOW);
    analogWrite(motorBPWM, convertSpeed(motorB, speed));
  }
}

void InInPWMDriver::motorABrake() {
  // Drive everything HIGH
  digitalWrite(motorA->_pin1, HIGH);
  digitalWrite(motorA->_pin2, HIGH);
  analogWrite(motorAPWM, motorA->_maxSpeed);
}

void InInPWMDriver::motorACoast() {
  // Drive everything LOW
  digitalWrite(motorA->_pin1, LOW);
  digitalWrite(motorA->_pin2, LOW);
  analogWrite(motorAPWM, 0);
}

void InInPWMDriver::motorBBrake() {
  // Drive everything HIGH
  digitalWrite(motorB->_pin1, HIGH);
  digitalWrite(motorB->_pin2, HIGH);
  analogWrite(motorBPWM, motorB->_maxSpeed);
}

void InInPWMDriver::motorBCoast() {
  // Drive everything LOW
  digitalWrite(motorB->_pin1, LOW);
  digitalWrite(motorB->_pin2, LOW);
  analogWrite(motorBPWM, 0);
}