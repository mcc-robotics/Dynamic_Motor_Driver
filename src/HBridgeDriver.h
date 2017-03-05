//
// Created by Geoff Berl on 3/3/17.
//

#ifndef MOTORDRIVER_HBRIDGEDRIVER_H
#define MOTORDRIVER_HBRIDGEDRIVER_H

#include "MotorDriver.h"

class HBridgeDriver : public MotorDriver {

public:

  HBridgeDriver(unsigned char motorA1, unsigned char motorA2, unsigned char motorAEnable, unsigned char motorB1,
                unsigned char motorB2, unsigned char motorBEnable)
  : MotorDriver(motorA1, motorA2, motorB1, motorB2) {

    // Initialize variables
    HBridgeDriver::motorAEnable = motorAEnable;
    HBridgeDriver::motorBEnable = motorBEnable;

    // Initialize pins in case it wasn't done before
    pinMode(motorAEnable, OUTPUT);
    pinMode(motorBEnable, OUTPUT);

    // Turn off motors
    MotorDriver::coastAll();
  }

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

private:

  unsigned char motorAEnable = 0;
  unsigned char motorBEnable = 0;

};

#endif //MOTORDRIVER_HBRIDGEDRIVER_H
