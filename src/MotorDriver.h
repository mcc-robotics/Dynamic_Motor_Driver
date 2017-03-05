//
// Created by gberl on 2/28/2017.
//

#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include <Arduino.h>

#define BRAKE_DRIVE 0
#define COAST_DRIVE 1
#define IN_IN_MODE 0
#define PHASE_ENABLE_MODE 1
#define MOTOR_A 0
#define MOTOR_B 1

struct Motor {
  uint8_t _pin1 = 0;
  uint8_t _pin2 = 0;
  int16_t currentSpeed = 0;
  uint16_t _maxSpeed = 255;
};

class MotorDriver {

public:

  /**
   * The main constructor for the motor driver object. The assumption is that you want to control two motors so you
   * will need to provide pins 1 and 2 for each motor as well as specify a drive mode. If a drive mode is not
   * specified or is incorrectly specified, the library will default to Phase/Enable.
   * @param motorA1 The motor A input number 1 or the phase pin depending on the mode
   * @param motorA2 the motor A input number 2 or the enable pin depensing on the mode
   * @param motorB1 the motor B input number 1 or the phase pin depending on the mode
   * @param motorB2 the motor B input number 2 or the phase pin depending on the mode
   * @param mode    the desired drive mode
   */
  MotorDriver(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2) {
    motorA = new Motor();
    motorB = new Motor();
    motorA->_pin1 = motorA1;
    motorA->_pin2 = motorA2;
    motorB->_pin1 = motorB1;
    motorB->_pin2 = motorB2;
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
  }

  /*
   * Functions that explicitly call out the motor
   */

  virtual void setMotorACoastSpeed(int8_t speed) {
    MotorDriver::motorA->currentSpeed = speed;
  }

  virtual void setMotorABrakeSpeed(int8_t speed) {
    MotorDriver::motorA->currentSpeed = speed;
  }

  virtual void setMotorBCoastSpeed(int8_t speed) {
    MotorDriver::motorB->currentSpeed = speed;
  }

  virtual void setMotorBBrakeSpeed(int8_t speed) {
    MotorDriver::motorB->currentSpeed = speed;
  }

  virtual void motorABrake() {
    MotorDriver::motorA->currentSpeed = 0;
  }

  virtual void motorACoast() {
    MotorDriver::motorA->currentSpeed = 0;
  }

  virtual void motorBBrake() {
    MotorDriver::motorB->currentSpeed = 0;
  }

  virtual void motorBCoast() {
    MotorDriver::motorB->currentSpeed = 0;
  }

  /**
 * Set the motor speed for motor A. You may optionally define a drive type of brake or coast. The drive type
 * is defaulted to brake in which an active brake will be applied to the motor to reduce coasting while moving
 * @param speed     the percent of power to apply to the motor (-100 to +100)
 * @param driveType OPTIONAL drive type
 */
  void setMotorASpeed(int8_t speed, uint8_t driveType = BRAKE_DRIVE) {
    if (driveType == COAST_DRIVE) {
      setMotorACoastSpeed(speed);
    } else {
      setMotorABrakeSpeed(speed);
    }
  }

  /**
   * Set the motor speed for motor A. You may optionally define a drive type of brake or coast. The drive type
   * is defaulted to brake in which an active brake will be applied to the motor to reduce coasting while moving
   * @param speed     the percent of power to apply to the motor (-100 to +100)
   * @param driveType OPTIONAL drive type
   */
  void setMotorBSpeed(int8_t speed, uint8_t driveType = BRAKE_DRIVE) {
    if (driveType == COAST_DRIVE) {
      setMotorBCoastSpeed(speed);
    } else {
      setMotorBBrakeSpeed(speed);
    }
  }

  /*
   * Functions that control either motor, just pass in which one
   */

  void setCoastSpeed(int8_t speed, uint8_t motor) {
    if (motor == MOTOR_A) {
      setMotorACoastSpeed(speed);
    } else {
      setMotorBCoastSpeed(speed);
    }
  }

  void setBrakeSpeed(int8_t speed, uint8_t motor) {
    if (motor == MOTOR_A) {
      setMotorABrakeSpeed(speed);
    } else {
      setMotorBBrakeSpeed(speed);
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

  void setAllCoastSpeed(int8_t speed) {
    setMotorACoastSpeed(speed);
    setMotorBCoastSpeed(speed);
  }

  void setAllBrakeSpeed(int8_t speed) {
    setMotorABrakeSpeed(speed);
    setMotorBBrakeSpeed(speed);
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

  int16_t getMotorASpeed() {
    return motorA->currentSpeed;
  }

  int16_t getMotorBSpeed() {
    return motorB->currentSpeed;
  }

  /**
   * Destructor cleans up memory
   */
  virtual ~MotorDriver() {
    delete motorA;
    delete motorB;
  }

protected:

  /**
   * Utility function to convert a -100 to 100 speed to the actual speed range of the motor
   * @param speed
   * @return
   */
  int16_t convertSpeed(Motor *motor, int16_t speed) {
    return (speed * motor->_maxSpeed) / 100;
  }

  // Give child classes access to motor objects by using protected
  Motor *motorA;
  Motor *motorB;

private:


};


#endif //MOTORDRIVER_H
