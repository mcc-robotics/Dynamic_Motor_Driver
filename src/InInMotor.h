//
// Created by Geoff Berl on 3/5/17.
//

#ifndef MOTORDRIVER_ININMOTOR_H
#define MOTORDRIVER_ININMOTOR_H


#include "Motor.h"

class InInMotor : public Motor {

public:

  InInMotor(uint8_t motPin1, uint8_t motPin2)
      : Motor(motPin1, motPin2) { }

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
  void setCoastDrivePower(int8_t power);

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
  void setBrakeDrivePower(int8_t power);

  /**
   * Brake stops the motors and applies the brakes to do so. This would be the same as stopping with the brakes in a
   * car.
   */
  void brake();

  /**
   * Coast stops the motors but applies no breaking which allows the motors to coast freely with any current momentum.
   * Using coast can provide inaccurate results, for accuracy, brake should be used.
   */
  void coast();

};


#endif //MOTORDRIVER_ININMOTOR_H
