//
// Created by Geoff Berl on 3/3/17.
//

#include "InInDriver.h"


void InInDriver::setMotorACoastSpeed(char speed) {
  MotorDriver::setMotorACoastSpeed(speed);

  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // Drive one pin with PWM and the other low
    analogWrite(motorA->_pin1, LOW);
    analogWrite(motorA->_pin2, convertSpeed(motorA, speed) * -1);
  } else {
    // Drive one pin with PWM and the other low
    analogWrite(motorA->_pin1, convertSpeed(motorA, speed));
    analogWrite(motorA->_pin2, LOW);
  }
}

void InInDriver::setMotorABrakeSpeed(char speed) {
  MotorDriver::setMotorABrakeSpeed(speed);

  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // Drive one pin with PWM and the other high
    analogWrite(motorA->_pin1, motorA->_maxSpeed);
    analogWrite(motorA->_pin2, motorA->_maxSpeed - (convertSpeed(motorA, speed) * -1));
  } else {
    // Drive one pin with PWM and the other high
    analogWrite(motorA->_pin1, motorA->_maxSpeed - convertSpeed(motorA, speed));
    analogWrite(motorA->_pin2, motorA->_maxSpeed);
  }
}

void InInDriver::setMotorBCoastSpeed(char speed) {
  MotorDriver::setMotorBCoastSpeed(speed);

  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // Drive one pin with PWM and the other low
    analogWrite(motorB->_pin1, LOW);
    analogWrite(motorB->_pin2, convertSpeed(motorB, speed) * -1);
  } else {
    // Drive one pin with PWM and the other low
    analogWrite(motorB->_pin1, convertSpeed(motorB, speed));
    analogWrite(motorB->_pin2, LOW);
  }
}

void InInDriver::setMotorBBrakeSpeed(char speed) {
  MotorDriver::setMotorBBrakeSpeed(speed);

  // Call the appropriate forward or reverse method
  if (speed < 0) {
    // Drive one pin with PWM and the other high
    analogWrite(motorB->_pin1, motorB->_maxSpeed);
    analogWrite(motorB->_pin2, motorB->_maxSpeed - convertSpeed(motorB, speed) * -1);
  } else {
    // Drive one pin with PWM and the other high
    analogWrite(motorB->_pin1, motorB->_maxSpeed - convertSpeed(motorB, speed));
    analogWrite(motorB->_pin2, motorB->_maxSpeed);
  }
}

void InInDriver::motorABrake() {
  MotorDriver::motorABrake();

  // Drive both pins high
  analogWrite(motorA->_pin1, motorA->_maxSpeed);
  analogWrite(motorA->_pin2, motorA->_maxSpeed);
}

void InInDriver::motorACoast() {
  MotorDriver::motorACoast();

  // Drive both pins low
  analogWrite(motorA->_pin1, LOW);
  analogWrite(motorA->_pin2, LOW);
}

void InInDriver::motorBBrake() {
  MotorDriver::motorBBrake();

  // Drive both pins high
  analogWrite(motorB->_pin1, motorB->_maxSpeed);
  analogWrite(motorB->_pin2, motorB->_maxSpeed);
}

void InInDriver::motorBCoast() {
  MotorDriver::motorBCoast();

  // Drive both pins low
  analogWrite(motorB->_pin1, LOW);
  analogWrite(motorB->_pin2, LOW);
}