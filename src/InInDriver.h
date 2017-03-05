//
// Created by Geoff Berl on 3/3/17.
//

#ifndef MOTORDRIVER_ININDRIVER_H
#define MOTORDRIVER_ININDRIVER_H


#include "MotorDriver.h"

class InInDriver : public MotorDriver {

public:
  InInDriver(unsigned char motorA1, unsigned char motorA2, unsigned char motorB1, unsigned char motorB2)
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


#endif //MOTORDRIVER_ININDRIVER_H
