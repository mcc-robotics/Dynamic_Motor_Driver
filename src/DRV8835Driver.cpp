//
// Created by gberl on 2/3/2017.
//

#include "DRV8835Driver.h"

DRV8835::DRV8835(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2) {
  // Create motor objects
#if defined(IN_IN_MODE)
  motorA = new InInMotor(motorA1, motorA2);
  motorB = new InInMotor(motorB1, motorB2);
#elif defined(PHASE_ENABLE_MODE)
  motorA = new PhaseEnableMotor(motorA1, motorA2);
  motorB = new PhaseEnableMotor(motorB1, motorB2);
#else
  motorA = new InInMotor(motorA1, motorA2);
  motorB = new InInMotor(motorB1, motorB2);
#endif
}

void DRV8835::setMotorASpeed(int8_t speed, uint8_t driveType) {
  if (driveType == COAST_DRIVE) {
    setMotorACoastSpeed(speed);
  } else {
    setMotorABrakeSpeed(speed);
  }
}

void DRV8835::setMotorBSpeed(int8_t speed, uint8_t driveType) {
  if (driveType == COAST_DRIVE) {
    setMotorBCoastSpeed(speed);
  } else {
    setMotorBBrakeSpeed(speed);
  }
}

void DRV8835::setCoastSpeed(int8_t speed, uint8_t motor) {
  if (motor == MOTOR_A) {
    setMotorACoastSpeed(speed);
  } else {
    setMotorBCoastSpeed(speed);
  }
}

void DRV8835::setBrakeSpeed(int8_t speed, uint8_t motor) {
  if (motor == MOTOR_A) {
    setMotorABrakeSpeed(speed);
  } else {
    setMotorBBrakeSpeed(speed);
  }
}

void DRV8835::brake(uint8_t motor) {
  if (motor == MOTOR_A) {
    motorA->brake();
  } else {
    motorB->brake();
  }
}

void DRV8835::coast(uint8_t motor) {
  if (motor == MOTOR_A) {
    motorA->coast();
  } else {
    motorB->coast();
  }
}

void DRV8835::brakeAll() {
  motorA->brake();
  motorB->brake();
}

void DRV8835::coastAll() {
  motorA->coast();
  motorB->coast();
}

void DRV8835::setAllCoastSpeed(int8_t speed) {
  setMotorACoastSpeed(speed);
  setMotorBCoastSpeed(speed);
}

void DRV8835::setAllBrakeSpeed(int8_t speed) {
  setMotorABrakeSpeed(speed);
  setMotorBBrakeSpeed(speed);
}

// More direct methods (ideally slightly faster but more tedious and confusing than using simpler methods above)

void DRV8835::setMotorACoastSpeed(int8_t speed) {
  // Call the appropriate forward or reverse method
  if (speed < 0) {
    motorA->reverseCoast(convertSpeed(speed * -1));
  } else {
    motorA->forwardCoast(convertSpeed(speed));
  }
}

void DRV8835::setMotorABrakeSpeed(int8_t speed) {
  // Call the appropriate forward or reverse method
  if (speed < 0) {
    motorA->reverseBrake(convertSpeed(speed * -1));
  } else {
    motorA->forwardBrake(convertSpeed(speed));
  }
}

void DRV8835::setMotorBCoastSpeed(int8_t speed) {
  // Call the appropriate forward or reverse method
  if (speed < 0) {
    motorB->reverseCoast(convertSpeed(speed * -1));
  } else {
    motorA->forwardCoast(convertSpeed(speed));
  }
}

void DRV8835::setMotorBBrakeSpeed(int8_t speed) {
  // Call the appropriate forward or reverse method
  if (speed < 0) {
    motorB->reverseBrake(convertSpeed(speed * -1));
  } else {
    motorB->forwardBrake(convertSpeed(speed));
  }
}

/*
 * Private Functions
 */

uint8_t DRV8835::convertSpeed(int8_t speed) {
  return (speed * Motor::_MAX_SPEED) / 100;
}

void DRV8835::motorABrake() {
  motorA->brake();
}

void DRV8835::motorACoast() {
  motorA->coast();
}

void DRV8835::motorBBrake() {
  motorB->brake();
}

void DRV8835::motorBCoast() {
  motorB->coast();
}

