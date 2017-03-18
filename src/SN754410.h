//
// Created by Geoff Berl on 3/4/17.
//

#ifndef MOTORDRIVER_SN754410_H
#define MOTORDRIVER_SN754410_H


#include "MotorDriver.h"
#include "HBridgeMotor.h"

class SN754410 : public MotorDriver {

public:
  SN754410(unsigned char motorA1, unsigned char motorA2, unsigned char motorAEnable, unsigned char motorB1,
           unsigned char motorB2, unsigned char motorBEnable) {
    // Create the motors
    motorA = new HBridgeMotor(motorA1, motorA2, motorAEnable);
    motorB = new HBridgeMotor(motorB1, motorB2, motorBEnable);
  }

};


#endif //MOTORDRIVER_SN754410_H
