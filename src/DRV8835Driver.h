//
// Created by gberl on 2/3/2017.
//

#ifndef DRV8835_H
#define DRV8835_H

#include <Arduino.h>

#include <Arduino.h>
#include "MotorDriver.h"

class DRV8835 : public MotorDriver {

public:

  /**
   * If calling this constructor the mode will default to In/In unless you have driven the mode pin HIGH on the chip.
   * By default, the mode is driven low which is In/In mode, if you wish to use Phase/Enable use the constructor which
   * specifically sets the drive mode.
   * @param motorA1 The motor A input number 1 or the phase pin depending on the mode
   * @param motorA2 the motor A input number 2 or the enable pin depensing on the mode
   * @param motorB1 the motor B input number 1 or the phase pin depending on the mode
   * @param motorB2 the motor B input number 2 or the phase pin depending on the mode
   */
  DRV8835(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2)
      : MotorDriver(motorA1, motorA2, motorB1, motorB2, IN_IN_MODE) { }

  /**
   * If calling this constructor the mode you specify must match that which you have defined by the circuitry. If you
   * have not connected anything to the Mode pin on the chip or driven the Mode pin LOW then you should be passing in
   * IN_IN_MODE. If you have driven the Mode pin HIGH you must specify PHASE_ENABLE_MODE
   * The benefit of this constructor is that you don't need to lose a digital pin if you simply drive the voltage
   * on the Mode pin physically.
   * @param motorA1 The motor A input number 1 or the phase pin depending on the mode
   * @param motorA2 the motor A input number 2 or the enable pin depensing on the mode
   * @param motorB1 the motor B input number 1 or the phase pin depending on the mode
   * @param motorB2 the motor B input number 2 or the phase pin depending on the mode
   */
  DRV8835(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2, uint8_t mode)
      : MotorDriver(motorA1, motorA2, motorB1, motorB2, mode) { }

  /**
   * The only functional difference the DRV8835 has over other drivers is that it has a drive mode pin to allow for
   * two different drive modes in one unit
   * @param motorA1 The motor A input number 1 or the phase pin depending on the mode
   * @param motorA2 the motor A input number 2 or the enable pin depensing on the mode
   * @param motorB1 the motor B input number 1 or the phase pin depending on the mode
   * @param motorB2 the motor B input number 2 or the phase pin depending on the mode
   * @param mode_pin    the mode pin which controls the chip's drive mode
   * @param mode    the desired drive mode
   */
  DRV8835(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2, uint8_t mode_pin, uint8_t mode)
  : MotorDriver(motorA1, motorA2, motorB1, motorB2, mode) {
    // The only difference here is we need to drive the mode pin to whichever mode the user chose
    pinMode(mode_pin, OUTPUT);
    if (mode == IN_IN_MODE) {
      digitalWrite(mode_pin, LOW);
    } else {
      digitalWrite(mode_pin, HIGH);
    }
  }
};


#endif // DRV8835_H
