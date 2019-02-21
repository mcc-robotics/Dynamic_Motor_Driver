//
// Created by Geoff Berl on 3/3/17.
//

#ifndef MOTORDRIVER_TB6612FNG_H
#define MOTORDRIVER_TB6612FNG_H

#include "HBridgeDriver.h"

class TB6612FNG : public HBridgeDriver {
public:
  TB6612FNG(uint8_t motorA1, uint8_t motorA2, uint8_t motorAEnable, uint8_t motorB1, uint8_t motorB2, uint8_t motorBEnable)
      : HBridgeDriver(motorA1, motorA2, motorAEnable, motorB1, motorB2, motorBEnable) {}


};



#endif //MOTORDRIVER_TB6612FNG_H
