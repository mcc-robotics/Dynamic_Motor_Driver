//
// Created by Geoff Berl on 3/18/17.
//

#ifndef MOTORDRIVER_MOTOR_H
#define MOTORDRIVER_MOTOR_H

#include <Arduino.h>
#include <stdint.h>

class Motor {

public:

  Motor(uint8_t motPin1, uint8_t motPin2) {
    _pin1 = motPin1;
    _pin2 = motPin2;
  }

  uint8_t getPin1() {
    return _pin1;
  }

  uint8_t getPin2() {
    return _pin2;
  }

  /**
   * Get the current power setting for this motor.
   * @return the percentage of power this motor is set to
   */
  int8_t getCurrentPower() {
    return _goalPower;
  }

  /**
   * Simple getter to get the current PWM resolution that is set.
   * @return the current PWM resolution setting
   */
  uint8_t getPWMResolution() {
    return _pwmResolution;
  }

  /**
   * Set the PWM resolution, the default is for a 8 bit resolution (255). The resolution is needed because the library
   * allows the user to set a percentage as the speed and the library converts it by using the set PWM resolution.
   * @param pwmResolution the resolution of the PWM pin.
   */
  void setPWMResolution(uint8_t pwmResolution) {
    _pwmResolution = pwmResolution;
  }

  virtual void init() {
    // Enable the pins
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);

    // Initialize the motor off
    brake();
  }

  /**
   * Set the power to apply using Coast drive. If you do not want the speed controlled by the encoders you can simply
   * set the power of the motor. If you want feedback controlled motor speeds you should use the velocity functions.
   * It should also be noted that this is dependent on the Max PWM Resolution which is defaulted to 255. If your PWM
   * pin is not 8 bit you should adjust the PWM Resolution accordingly.
   *
   * Coast drive does not apply any brake while driving so the wheel may drift providing less accurate results. Brake
   * drive should be used for most cases.
   * @param power the percentage of power to apply to the motor
   */
  virtual void setCoastDrivePower(int8_t power) = 0;

  /**
   * Set the power to apply using Brake drive. If you do not want the speed controlled by the encoders you can simply
   * set the power of the motor. If you want feedback controlled motor speeds you should use the velocity functions.
   * It should also be noted that this is dependent on the Max PWM Resolution which is defaulted to 255. If your PWM
   * pin is not 8 bit you should adjust the PWM Resolution accordingly.
   *
   * Brake drive ensure that there is little to no coast between PWM pulses so it typically provides a more accurate
   * result than coast drive.
   * @param power the percentage of power to apply to the motor
   */
  virtual void setBrakeDrivePower(int8_t power) = 0;

  /**
   * Brake stops the motors and applies the brakes to do so. This would be the same as stopping with the brakes in a
   * car.
   */
  virtual void brake() = 0;

  /**
   * Coast stops the motors but applies no breaking which allows the motors to coast freely with any current momentum.
   * Using coast can provide inaccurate results, for accuracy, brake should be used.
   */
  virtual void coast() = 0;

  virtual ~Motor() {};

protected:

  /**
   * Utility function to convert a -100 to 100 speed to the actual speed range of the motor
   * @param power
   * @return
   */
  int convertPower(int8_t power) {
    return (power * _pwmResolution) / 100;
  }

  /** MOTOR values */
  uint8_t _pin1 = 0;
  uint8_t _pin2 = 0;
  int8_t _goalPower = 0;
  uint8_t _pwmResolution = 255;   // The standard PWM pin is set to 8 bit (255)
};

#endif //MOTORDRIVER_MOTOR_H
