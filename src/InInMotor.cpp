//
// Created by gberl on 2/28/2017.
//

#include "InInMotor.h"

InInMotor::InInMotor(uint8_t pin1, uint8_t pin2) {
  // Initialize with the parent class
  Motor::init(pin1, pin2);

}

void InInMotor::forwardBrake(uint8_t speed) {
  // Drive one pin with PWM and the other high
  analogWrite(_pin1, _MAX_SPEED - speed);
  analogWrite(_pin2, _MAX_SPEED);
}

void InInMotor::forwardCoast(uint8_t speed) {
  // Drive one pin with PWM and the other low
  analogWrite(_pin1, speed);
  analogWrite(_pin2, LOW);
}

void InInMotor::reverseBrake(uint8_t speed) {
  // Drive one pin with PWM and the other high
  analogWrite(_pin1, _MAX_SPEED);
  analogWrite(_pin2, _MAX_SPEED - speed);
}

void InInMotor::reverseCoast(uint8_t speed) {
  // Drive one pin with PWM and the other low
  analogWrite(_pin1, LOW);
  analogWrite(_pin2, speed);
}

void InInMotor::brake() {
  // Drive both pins high
  analogWrite(_pin1, _MAX_SPEED);
  analogWrite(_pin2, _MAX_SPEED);
}

void InInMotor::coast() {
  // Drive both pins low
  analogWrite(_pin1, LOW);
  analogWrite(_pin2, LOW);
}