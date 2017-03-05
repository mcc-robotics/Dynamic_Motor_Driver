//
// Created by Geoff Berl on 3/4/17.
//

#ifndef MOTORDRIVER_SN754410_H
#define MOTORDRIVER_SN754410_H


#include "HBridgeDriver.h"

class SN754410 : public HBridgeDriver {

public:
  SN754410(unsigned char motorA1, unsigned char motorA2, unsigned char motorAEnable, unsigned char motorB1,
           unsigned char motorB2, unsigned char motorBEnable)
      : HBridgeDriver(motorA1, motorA2, motorAEnable, motorB1, motorB2, motorBEnable) {}

};


#endif //MOTORDRIVER_SN754410_H
