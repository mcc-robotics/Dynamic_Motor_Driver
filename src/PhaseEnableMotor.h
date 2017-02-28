//
// Created by gberl on 2/28/2017.
//

#ifndef ININMOTOR_H
#define ININMOTOR_H

#include <Arduino.h>
#include "Motor.h"

class PhaseEnableMotor : public Motor {
public:

  void forwardBrake(uint8_t speed);

  void reverseBrake(uint8_t speed);

  void forwardCoast(uint8_t speed);

  void reverseCoast(uint8_t speed);

  void brake();

  void coast();

};


#endif // ININMOTOR_H
