//
// Created by Geoff Berl on 3/3/17.
//

#include "InInDriver.h"


void InInDriver::setMotorACoastSpeed(int8_t speed) {
  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // Drive one pin with PWM and the other low
    analogWrite(motorA->_pin1, LOW);
    analogWrite(motorA->_pin2, convertSpeed(motorA, speed));
  } else {
    // Drive one pin with PWM and the other low
    analogWrite(motorA->_pin1, convertSpeed(motorA, speed));
    analogWrite(motorA->_pin2, LOW);
  }
}

void InInDriver::setMotorABrakeSpeed(int8_t speed) {
  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // Drive one pin with PWM and the other high
    analogWrite(motorA->_pin1, motorA->_maxSpeed);
    analogWrite(motorA->_pin2, convertSpeed(motorA, motorA->_maxSpeed - speed));
  } else {
    // Drive one pin with PWM and the other high
    analogWrite(motorA->_pin1, convertSpeed(motorA, motorA->_maxSpeed - speed));
    analogWrite(motorA->_pin2, motorA->_maxSpeed);
  }
}

void InInDriver::setMotorBCoastSpeed(int8_t speed) {
  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // Drive one pin with PWM and the other low
    analogWrite(motorB->_pin1, LOW);
    analogWrite(motorB->_pin2, convertSpeed(motorB, speed));
  } else {
    // Drive one pin with PWM and the other low
    analogWrite(motorB->_pin1, convertSpeed(motorB, speed));
    analogWrite(motorB->_pin2, LOW);
  }
}

void InInDriver::setMotorBBrakeSpeed(int8_t speed) {
  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // Drive one pin with PWM and the other high
    analogWrite(motorB->_pin1, motorB->_maxSpeed);
    analogWrite(motorB->_pin2, convertSpeed(motorB, motorB->_maxSpeed - speed));
  } else {
    // Drive one pin with PWM and the other high
    analogWrite(motorB->_pin1, convertSpeed(motorB, motorB->_maxSpeed - speed));
    analogWrite(motorB->_pin2, motorB->_maxSpeed);
  }
}

void InInDriver::motorABrake() {
  // Drive both pins high
  analogWrite(motorA->_pin1, motorA->_maxSpeed);
  analogWrite(motorA->_pin2, motorA->_maxSpeed);
}

void InInDriver::motorACoast() {
  // Drive both pins low
  analogWrite(motorA->_pin1, LOW);
  analogWrite(motorA->_pin2, LOW);
}

void InInDriver::motorBBrake() {
  // Drive both pins high
  analogWrite(motorB->_pin1, motorB->_maxSpeed);
  analogWrite(motorB->_pin2, motorB->_maxSpeed);
}

void InInDriver::motorBCoast() {
  // Drive both pins low
  analogWrite(motorB->_pin1, LOW);
  analogWrite(motorB->_pin2, LOW);
}