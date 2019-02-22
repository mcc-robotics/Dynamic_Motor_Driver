//
// Created by gberl on 2/3/2017.
//

#ifndef TB67H420FTG_H
#define TB67H420FTG_H

#include <Arduino.h>
#include "MotorDriver.h"
#include "InInDriver.h"
#include "InInPWMDriver.h"

/**
 * The TB67H320FTG chip supports both In/In/PWM and In/In modes so I've implemented a strategy pattern where
 * we simply create the strategy during construction and then forward each call to the strategy, whatever
 * it may be. Once constructed, the class doesn't care what the strategy is, that's the beauty of the
 * strategy pattern.
 */
class TB67H420FTG : public MotorDriver {

public:

    // TODO: Need to implement the constructors for the two strategies
    // TODO: Need to add implementation for single motor control support
    // TODO: Need to add function and implementation for handling error codes
    // TODO: Need to add example in the examples directory

    // TODO: Update comments
  /**
   * If calling this constructor the mode will default to In/In unless you have driven the mode pin HIGH on the chip.
   * By default, the mode is driven low which is In/In mode, if you wish to use Phase/Enable use the constructor which
   * specifically sets the drive mode.
   * @param motorA1 The motor A input number 1 or the phase pin depending on the mode
   * @param motorA2 the motor A input number 2 or the enable pin depending on the mode
   * @param motorB1 the motor B input number 1 or the phase pin depending on the mode
   * @param motorB2 the motor B input number 2 or the phase pin depending on the mode
   */
  TB67H420FTG(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2)
      : MotorDriver(motorA1, motorA2, motorB1, motorB2) {
    driveStrategy = new InInDriver(motorA1, motorA2, motorB1, motorB2);
  }

  // TODO: Add comments
  TB67H420FTG(uint8_t motorA1, uint8_t motorA2, uint8_t motorAPWM, uint8_t motorB1, uint8_t motorB2, uint8_t motorBPWM)
      : MotorDriver(motorA1, motorA2, motorB1, motorB2) {
    driveStrategy = new InInPWMDriver(motorA1, motorA2, motorAPWM, motorB1, motorB2, motorBPWM);
  }

  /*
   * These are all virtual functions inherited from MotorDriver
   */

  void setMotorACoastSpeed(int8_t speed) {
    // Simply call the strategy function
    driveStrategy->setMotorACoastSpeed(speed);
  }

  void setMotorABrakeSpeed(int8_t speed) {
    // Simply call the strategy function
    driveStrategy->setMotorABrakeSpeed(speed);
  }

  void setMotorBCoastSpeed(int8_t speed) {
    // Simply call the strategy function
    driveStrategy->setMotorBCoastSpeed(speed);
  }

  void setMotorBBrakeSpeed(int8_t speed) {
    // Simply call the strategy function
    driveStrategy->setMotorBBrakeSpeed(speed);
  }

  void motorABrake() {
    // Simply call the strategy function
    driveStrategy->motorABrake();
  }

  void motorACoast() {
    // Simply call the strategy function
    driveStrategy->motorACoast();
  }

  void motorBBrake() {
    // Simply call the strategy function
    driveStrategy->motorBBrake();
  }

  void motorBCoast() {
    // Simply call the strategy function
    driveStrategy->motorBCoast();
  }

  ~TB67H420FTG() {
    delete driveStrategy;
  }

private:

  MotorDriver *driveStrategy = nullptr;

};


#endif // TB67H420FTG_H
