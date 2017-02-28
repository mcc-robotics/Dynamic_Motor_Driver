//
// Created by gberl on 2/28/2017.
//

#ifndef PHASEENABLEMOTOR_H
#define PHASEENABLEMOTOR_H

#include <Arduino.h>
#include "Motor.h"

class PhaseEnableMotor : public Motor {
public:

  PhaseEnableMotor(uint8_t pin1, uint8_t pin2)
      : Motor(pin1, pin2) {}

  void forwardBrake(uint8_t speed);

  void reverseBrake(uint8_t speed);

  void forwardCoast(uint8_t speed);

  void reverseCoast(uint8_t speed);

  void brake();

  void coast();

};


#endif // PHASEENABLEMOTOR_H
