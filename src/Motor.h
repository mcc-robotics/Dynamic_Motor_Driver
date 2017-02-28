//
// Created by gberl on 2/28/2017.
//

#ifndef MOTOR_H
#define MOTOR_H

class Motor {

public:

  /**
   * If the motor is In/In mode, both pins should be analog. If the motor is Phase/Enable mode, pin1 (Phase) should be
   * digital and pin2 (enable) should be PWM.
   * @param pin1
   * @param pin2
   */
  Motor(uint8_t pin1, uint8_t pin2) {
    // Initialize the pins
    Motor::_pin1 = pin1;
    Motor::_pin2 = pin2;

    // Set the pinMode and turn motor off
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
    coast();
  }

  virtual void forwardBrake(uint8_t speed) {}

  virtual void reverseBrake(uint8_t speed) {}

  virtual void forwardCoast(uint8_t speed) {}

  virtual void reverseCoast(uint8_t speed) {}

  virtual void brake() {}

  virtual void coast() {}

  const static uint8_t _MAX_SPEED = 255;

protected:

  uint8_t _pin1;
  uint8_t _pin2;

};

#endif // MOTOR_H
