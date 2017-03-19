//
// Created by gberl on 2/3/2017.
//

#ifndef DRV8835_H
#define DRV8835_H

#include <Arduino.h>
#include "MotorDriver.h"
#include "InInMotor.h"
#include "PhaseEnableMotor.h"

/**
 * The DRV8835 chip supports both Phase/Enable and In/In modes so I've implemented a strategy pattern where
 * we simply create the strategy during construction and then forward each call to the strategy, whatever
 * it may be. Once constructed, the class doesn't care what the strategy is, that's the beauty of the
 * strategy pattern.
 */
class DRV8835 : public MotorDriver {

public:

  /**
   * If calling this constructor the mode will default to In/In unless you have driven the mode pin HIGH on the chip.
   * By default, the mode is driven low which is In/In mode, if you wish to use Phase/Enable use the constructor which
   * specifically sets the drive mode.
   * @param motorA1 The motor A input number 1 or the phase pin depending on the mode
   * @param motorA2 the motor A input number 2 or the enable pin depending on the mode
   * @param motorB1 the motor B input number 1 or the phase pin depending on the mode
   * @param motorB2 the motor B input number 2 or the phase pin depending on the mode
   */
  DRV8835(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2) {
    motorA = new InInMotor(motorA1, motorA2);
    motorB = new InInMotor(motorB1, motorB2);
  }

  /**
   * If calling this constructor the mode you specify must match that which you have defined by the circuitry. If you
   * have not connected anything to the Mode pin on the chip or driven the Mode pin LOW then you should be passing in
   * IN_IN_MODE. If you have driven the Mode pin HIGH you must specify PHASE_ENABLE_MODE
   * The benefit of this constructor is that you don't need to lose a digital pin if you simply drive the voltage
   * on the Mode pin physically.
   * @param motorA1 The motor A input number 1 or the phase pin depending on the mode
   * @param motorA2 the motor A input number 2 or the enable pin depending on the mode
   * @param motorB1 the motor B input number 1 or the phase pin depending on the mode
   * @param motorB2 the motor B input number 2 or the phase pin depending on the mode
   */
  DRV8835(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2, uint8_t mode) {
    if (mode == IN_IN_MODE) {
      motorA = new InInMotor(motorA1, motorA2);
      motorB = new InInMotor(motorB1, motorB2);
    } else if (mode == PHASE_ENABLE_MODE) {
      motorA = new PhaseEnableMotor(motorA1, motorA2);
      motorB = new PhaseEnableMotor(motorB1, motorB2);
    }
  }

  /**
   * The only functional difference the DRV8835 has over other drivers is that it has a drive mode pin to allow for
   * two different drive modes in one unit
   * @param motorA1 The motor A input number 1 or the phase pin depending on the mode
   * @param motorA2 the motor A input number 2 or the enable pin depending on the mode
   * @param motorB1 the motor B input number 1 or the phase pin depending on the mode
   * @param motorB2 the motor B input number 2 or the phase pin depending on the mode
   * @param mode_pin    the mode pin which controls the chip's drive mode
   * @param mode    the desired drive mode
   */
  DRV8835(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2,
          uint8_t mode_pin, uint8_t mode) {
    // The only difference here is we need to drive the mode pin to whichever mode the user chose
    _modePin = mode_pin;
    _mode = mode;
    _usingModePin = true;
    if (mode == IN_IN_MODE) {
      motorA = new InInMotor(motorA1, motorA2);
      motorB = new InInMotor(motorB1, motorB2);
    } else if (mode == PHASE_ENABLE_MODE) {
      motorA = new PhaseEnableMotor(motorA1, motorA2);
      motorB = new PhaseEnableMotor(motorB1, motorB2);
    }
  }

  /**
   * We override init() because we also need to adjust the mode pin
   */
  void init() {
    MotorDriver::init();

    // If not using the mode pin, just return now
    if (!_usingModePin) {
      return;
    }

    pinMode(_modePin, OUTPUT);
    if (_mode == IN_IN_MODE) {
      digitalWrite(_modePin, LOW);
    } else if (_mode == PHASE_ENABLE_MODE) {
      digitalWrite(_modePin, HIGH);
    }
  }

private:

  uint8_t _modePin = 0;
  uint8_t _mode = IN_IN_MODE;
  bool _usingModePin = false;

};


#endif // DRV8835_H
