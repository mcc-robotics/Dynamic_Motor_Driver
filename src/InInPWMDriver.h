//
// Created by Geoff Berl on 2/20/19.
//

#ifndef MOTORDRIVER_ININPWMDRIVER_H
#define MOTORDRIVER_ININPWMDRIVER_H


#include "MotorDriver.h"

class InInPWMDriver : public MotorDriver {

public:
  InInPWMDriver(uint8_t motorA1, uint8_t motorA2, uint8_t motorAPWM, uint8_t motorB1, uint8_t motorB2, uint8_t motorBPWM)
      : MotorDriver(motorA1, motorA2, motorB1, motorB2) {
    _motorAPWM = motorAPWM;
    _motorBPWM = motorBPWM;
    pinMode(motorAPWM, OUTPUT);
    pinMode(motorBPWM, OUTPUT);
  }

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

protected:

    uint8_t _motorAPWM;

    uint8_t _motorBPWM;

};


#endif //MOTORDRIVER_ININPWMDRIVER_H
