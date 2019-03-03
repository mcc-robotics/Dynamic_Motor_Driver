//
// Created by gberl on 2/20/2019.
//

#ifndef MOTORDRIVER_TB67H420FTG_H
#define MOTORDRIVER_TB67H420FTG_H

#include <Arduino.h>
#include "MotorDriver.h"
#include "InInMotor.h"
#include "InInPWMMotor.h"

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
  TB67H420FTG(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2) {
    motorA = new InInMotor(motorA1, motorA2);
    motorB = new InInMotor(motorB1, motorB2);
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
  TB67H420FTG(uint8_t motorA1, uint8_t motorA2, uint8_t motorAPWM, uint8_t motorB1, uint8_t motorB2, uint8_t motorBPWM) {
    motorA = new InInPWMMotor(motorA1, motorA2, motorAPWM);
    motorB = new InInPWMMotor(motorB1, motorB2, motorBPWM);
  }

};


#endif // MOTORDRIVER_TB67H420FTG_H
