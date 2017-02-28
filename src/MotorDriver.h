//
// Created by gberl on 2/28/2017.
//

#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include "Motor.h"
#include "InInMotor.h"
#include "PhaseEnableMotor.h"

#define BRAKE_DRIVE 0
#define COAST_DRIVE 1
#define IN_IN_MODE 0
#define PHASE_ENABLE_MODE 1
#define MOTOR_A 0
#define MOTOR_B 1

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
  MotorDriver(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2, uint8_t driveMode) {
    if (driveMode == IN_IN_MODE) {
      motorA = new InInMotor(motorA1, motorA2);
      motorB = new InInMotor(motorB1, motorB2);
    } else { // Default to phase enable since it's probably more common
      motorA = new PhaseEnableMotor(motorA1, motorA2);
      motorB = new PhaseEnableMotor(motorB1, motorB2);
    }
  }

  /*
   * Functions that explicitly call out the motor
   */

  void setMotorACoastSpeed(int8_t speed) {
    // Call the appropriate forward or reverse method
    if (speed < 0) {
      motorA->reverseCoast(convertSpeed(speed * -1));
    } else {
      motorA->forwardCoast(convertSpeed(speed));
    }
  }

  void setMotorABrakeSpeed(int8_t speed) {
    // Call the appropriate forward or reverse method
    if (speed < 0) {
      motorA->reverseBrake(convertSpeed(speed * -1));
    } else {
      motorA->forwardBrake(convertSpeed(speed));
    }
  }

  void setMotorBCoastSpeed(int8_t speed) {
    // Call the appropriate forward or reverse method
    if (speed < 0) {
      motorB->reverseCoast(convertSpeed(speed * -1));
    } else {
      motorA->forwardCoast(convertSpeed(speed));
    }
  }

  void setMotorBBrakeSpeed(int8_t speed) {
    // Call the appropriate forward or reverse method
    if (speed < 0) {
      motorB->reverseBrake(convertSpeed(speed * -1));
    } else {
      motorB->forwardBrake(convertSpeed(speed));
    }
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
      motorA->brake();
    } else {
      motorB->brake();
    }
  }

  /**
   * Stop a specific motor by coasting the motor, some movement will occur with this type of stop but only from momentum
   * @param motor the motor you wish to stop and coast (MOTOR_A or MOTOR_B)
   */
  void coast(uint8_t motor) {
    if (motor == MOTOR_A) {
      motorA->coast();
    } else {
      motorB->coast();
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
    motorA->brake();
    motorB->brake();
  }

  /**
   * Stop both motors by coasting, this will allow the wheels to continue to spin but only with momentum.
   */
  void coastAll() {
    motorA->coast();
    motorB->coast();
  }

  /**
   * Destructor cleans up memory
   */
  virtual ~MotorDriver() {
    delete motorA;
    delete motorB;
  }

protected:

  // Give child classes access to motor objects by using protected
  Motor *motorA;
  Motor *motorB;

private:

  /**
   * Convert 0-100 speed to the speed range of the motor
   * @param speed
   * @return
   */
  uint8_t convertSpeed(int8_t speed) {
    return (speed * Motor::_MAX_SPEED) / 100;
  }

};


#endif //MOTORDRIVER_H
