//
// Created by Geoff Berl on 3/4/17.
//

#ifndef MOTORDRIVER_PHASEENABLEDRIVER_H
#define MOTORDRIVER_PHASEENABLEDRIVER_H


#include "MotorDriver.h"

class PhaseEnableDriver : public MotorDriver {

public:
  PhaseEnableDriver(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2)
      : MotorDriver(motorA1, motorA2, motorB1, motorB2) {}

  /*
   * These are all virtual functions inherited from MotorDriver
   */

  void setMotorACoastSpeed(int8_t speed);

  void setMotorABrakeSpeed(int8_t speed);

  void setMotorBCoastSpeed(int8_t speed);

  void setMotorBBrakeSpeed(int8_t speed);

  void motorABrake();

  void motorACoast();

  void motorBBrake();

  void motorBCoast();

};


#endif //MOTORDRIVER_PHASEENABLEDRIVER_H
