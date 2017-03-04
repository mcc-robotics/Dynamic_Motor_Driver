//
// Created by Geoff Berl on 3/4/17.
//

#ifndef MOTORDRIVER_SN754410_H
#define MOTORDRIVER_SN754410_H


#include "HBridgeDriver.h"

class SN754410 : public HBridgeDriver {

public:
  SN754410(uint8_t motorA1, uint8_t motorA2, uint8_t motorAEnable, uint8_t motorB1, uint8_t motorB2,
           uint8_t motorBEnable)
      : HBridgeDriver(motorA1, motorA2, motorAEnable, motorB1, motorB2, motorBEnable) {}

};


#endif //MOTORDRIVER_SN754410_H
