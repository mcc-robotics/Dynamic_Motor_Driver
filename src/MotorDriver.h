//
// Created by gberl on 2/28/2017.
//

#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include <Arduino.h>
#include "Motor.h"

#define BRAKE_DRIVE 0
#define COAST_DRIVE 1
#define IN_IN_MODE 0
#define PHASE_ENABLE_MODE 1
#define MOTOR_A 0
#define MOTOR_B 1

class MotorDriver {

public:

//  /**
//   * The main constructor for the motor driver object. The assumption is that you want to control two motors so you
//   * will need to provide pins 1 and 2 for each motor as well as specify a drive mode. If a drive mode is not
//   * specified or is incorrectly specified, the library will default to Phase/Enable.
//   * @param motorA1 The motor A input number 1 or the phase pin depending on the mode
//   * @param motorA2 the motor A input number 2 or the enable pin depensing on the mode
//   * @param motorB1 the motor B input number 1 or the phase pin depending on the mode
//   * @param motorB2 the motor B input number 2 or the phase pin depending on the mode
//   * @param mode    the desired drive mode
//   */
//  MotorDriver(unsigned char motorA1, unsigned char motorA2, unsigned char motorB1, unsigned char motorB2) {
//    motorA = new InInMotor(motorA1, motorA2);
//    motorB = new InInMotor(motorB1, motorB2);
//  }

  virtual void init() {
    // Forward init() to the motor objects
    motorA->init();
    motorB->init();
  }

  /*
   * Functions that explicitly call out the motor
   */

  void setMotorACoastPower(int8_t power) {
    motorA->setCoastDrivePower(power);
  }

  void setMotorABrakePower(int8_t power) {
    motorA->setBrakeDrivePower(power);
  }

  void setMotorBCoastPower(int8_t power) {
    motorB->setCoastDrivePower(power);
  }

  void setMotorBBrakePower(int8_t power) {
    motorB->setBrakeDrivePower(power);
  }

  void motorABrake() {
    motorA->brake();
  }

  void motorACoast() {
    motorA->coast();
  }

  void motorBBrake() {
    motorB->brake();
  }

  void motorBCoast() {
    motorB->coast();
  }

  /**
 * Set the motor speed for motor A. You may optionally define a drive type of brake or coast. The drive type
 * is defaulted to brake in which an active brake will be applied to the motor to reduce coasting while moving
 * @param power     the percent of power to apply to the motor (-100 to +100)
 * @param driveType OPTIONAL drive type
 */
  void setMotorAPower(int8_t power, uint8_t driveType = BRAKE_DRIVE) {
    if (driveType == COAST_DRIVE) {
      setMotorACoastPower(power);
    } else {
      setMotorABrakePower(power);
    }
  }

  /**
   * Set the motor speed for motor A. You may optionally define a drive type of brake or coast. The drive type
   * is defaulted to brake in which an active brake will be applied to the motor to reduce coasting while moving
   * @param power     the percent of power to apply to the motor (-100 to +100)
   * @param driveType OPTIONAL drive type
   */
  void setMotorBPower(int8_t power, uint8_t driveType = BRAKE_DRIVE) {
    if (driveType == COAST_DRIVE) {
      setMotorBCoastPower(power);
    } else {
      setMotorBBrakePower(power);
    }
  }

  /*
   * Functions that control either motor, just pass in which one
   */

  void setCoastPower(int8_t power, uint8_t motor) {
    if (motor == MOTOR_A) {
      setMotorACoastPower(power);
    } else {
      setMotorBCoastPower(power);
    }
  }

  void setBrakePower(int8_t power, uint8_t motor) {
    if (motor == MOTOR_A) {
      setMotorABrakePower(power);
    } else {
      setMotorBBrakePower(power);
    }
  }

  /**
   * Stop a specific motor by braking the motor, little to no movement will occur with this type of stop
   * @param motor the motor you wish to brake (MOTOR_A or MOTOR_B)
   */
  void brake(uint8_t motor) {
    if (motor == MOTOR_A) {
      motorABrake();
    } else {
      motorBBrake();
    }
  }

  /**
   * Stop a specific motor by coasting the motor, some movement will occur with this type of stop but only from momentum
   * @param motor the motor you wish to stop and coast (MOTOR_A or MOTOR_B)
   */
  void coast(uint8_t motor) {
    if (motor == MOTOR_A) {
      motorACoast();
    } else {
      motorBCoast();
    }
  }

  /*
   * Functions to control both motors simultaneously
   */

  void setAllCoastPower(int8_t power) {
    setMotorACoastPower(power);
    setMotorBCoastPower(power);
  }

  void setAllBrakePower(int8_t power) {
    setMotorABrakePower(power);
    setMotorBBrakePower(power);
  }

  /**
   * Stop both motors by braking, this will lock the wheels so there will be little to no movement while stopping.
   */
  void brakeAll() {
    motorABrake();
    motorBBrake();
  }

  /**
   * Stop both motors by coasting, this will allow the wheels to continue to spin but only with momentum.
   */
  void coastAll() {
    motorACoast();
    motorBCoast();
  }

  Motor *getMotorA() {
    return motorA;
  }

  Motor *getMotorB() {
    return motorB;
  }

  /**
   * Destructor cleans up memory
   */
  ~MotorDriver() {
    // Delete the motor objects
    delete motorA;
    delete motorB;
  }

protected:

  // Give child classes access to motor objects by using protected
  Motor *motorA;
  Motor *motorB;

private:


};


#endif //MOTORDRIVER_H
