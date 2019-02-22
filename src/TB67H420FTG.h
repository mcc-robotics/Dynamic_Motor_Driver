//
// Created by gberl on 2/20/2019.
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
 *
 * Possible future enhancements would be to
 * + include a single motor mode
 * + include methods for reading error codes
 */
class TB67H420FTG : public MotorDriver {

public:

  /**
   * If calling this constructor the mode will default to two pin In/In mode.
   * @param motorA1 the motor A input number 1
   * @param motorA2 the motor A input number 2
   * @param motorB1 the motor B input number 1
   * @param motorB2 the motor B input number 2
   */
  TB67H420FTG(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2)
      : MotorDriver(motorA1, motorA2, motorB1, motorB2) {
    driveStrategy = new InInDriver(motorA1, motorA2, motorB1, motorB2);
  }

  /**
   * If calling this constructor the mode will default to three pin In/In/PWM mode.
   * @param motorA1   the motor A input number 1
   * @param motorA2   the motor A input number 2
   * @param motorAPWM the motor A PWM input
   * @param motorB1   the motor B input number 1
   * @param motorB2   the motor B input number 2
   * @param motorBPWM the motor B PWM input
   */
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
