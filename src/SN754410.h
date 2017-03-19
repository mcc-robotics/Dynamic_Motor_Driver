//
// Created by Geoff Berl on 3/4/17.
//

#ifndef MOTORDRIVER_SN754410_H
#define MOTORDRIVER_SN754410_H


#include "MotorDriver.h"
#include "HBridgeMotor.h"

class SN754410 : public MotorDriver {

public:
  SN754410(uint8_t motorA1, uint8_t motorA2, uint8_t motorAEnable, uint8_t motorB1,
           uint8_t motorB2, uint8_t motorBEnable) {
    // Create the motors
    motorA = new HBridgeMotor(motorA1, motorA2, motorAEnable);
    motorB = new HBridgeMotor(motorB1, motorB2, motorBEnable);
  }

};


#endif //MOTORDRIVER_SN754410_H
