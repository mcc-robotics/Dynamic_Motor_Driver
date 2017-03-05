//
// Created by Geoff Berl on 3/4/17.
//

#ifndef MOTORDRIVER_PHASEENABLEDRIVER_H
#define MOTORDRIVER_PHASEENABLEDRIVER_H


#include "MotorDriver.h"

class PhaseEnableDriver : public MotorDriver {

public:
  PhaseEnableDriver(unsigned char motorA1, unsigned char motorA2, unsigned char motorB1, unsigned char motorB2)
      : MotorDriver(motorA1, motorA2, motorB1, motorB2) {}

  /*
   * These are all virtual functions inherited from MotorDriver
   */

  void setMotorACoastSpeed(char speed);

  void setMotorABrakeSpeed(char speed);

  void setMotorBCoastSpeed(char speed);

  void setMotorBBrakeSpeed(char speed);

  void motorABrake();

  void motorACoast();

  void motorBBrake();

  void motorBCoast();

};


#endif //MOTORDRIVER_PHASEENABLEDRIVER_H
