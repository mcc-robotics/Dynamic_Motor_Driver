//
// Created by gberl on 2/28/2017.
//

#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#define BRAKE_DRIVE 0
#define COAST_DRIVE 1
#define MOTOR_A 0
#define MOTOR_B 1

class MotorDriver {
public:
  /**
   * Set the motor speed for motor A. You may optionally define a drive type of brake or coast. The drive type
   * is defaulted to brake in which an active brake will be applied to the motor to reduce coasting while moving
   * @param speed     the percent of power to apply to the motor (-100 to +100)
   * @param driveType OPTIONAL drive type
   */
  virtual void setMotorASpeed(int8_t speed, uint8_t driveType = BRAKE_DRIVE) {}

  /**
   * Set the motor speed for motor A. You may optionally define a drive type of brake or coast. The drive type
   * is defaulted to brake in which an active brake will be applied to the motor to reduce coasting while moving
   * @param speed     the percent of power to apply to the motor (-100 to +100)
   * @param driveType OPTIONAL drive type
   */
  virtual void setMotorBSpeed(int8_t speed, uint8_t driveType = BRAKE_DRIVE) {}

  /**
   * Stop both motors by braking, this will lock the wheels so there will be little to no movement while stopping.
   */
  virtual void brakeAll() {}

  /**
   * Stop both motors by coasting, this will allow the wheels to continue to spin but only with momentum.
   */
  virtual void coastAll() {}

  /**
   * Stop a specific motor by braking the motor, little to no movement will occur with this type of stop
   * @param motor the motor you wish to brake (MOTOR_A or MOTOR_B)
   */
  virtual void brake(uint8_t motor) {}

  /**
   * Stop a specific motor by coasting the motor, some movement will occur with this type of stop but only from momentum
   * @param motor the motor you wish to stop and coast (MOTOR_A or MOTOR_B)
   */
  virtual void coast(uint8_t motor) {}

protected:

};


#endif //MOTORDRIVER_H
