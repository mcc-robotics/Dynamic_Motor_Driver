//
// Created by Geoff Berl on 3/3/17.
//

#ifndef MOTORDRIVER_HBRIDGEDRIVER_H
#define MOTORDRIVER_HBRIDGEDRIVER_H

#include "MotorDriver.h"

class HBridgeDriver : public MotorDriver {

public:

  HBridgeDriver(uint8_t motorA1, uint8_t motorA2, uint8_t motorAEnable, uint8_t motorB1, uint8_t motorB2, uint8_t motorBEnable)
  : MotorDriver(motorA1, motorA2, motorB1, motorB2) {
    HBridgeDriver::motorAEnable = motorAEnable;
    HBridgeDriver::motorBEnable = motorBEnable;
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

private:

  uint8_t motorAEnable = 0;
  uint8_t motorBEnable = 0;

};

#endif //MOTORDRIVER_HBRIDGEDRIVER_H
