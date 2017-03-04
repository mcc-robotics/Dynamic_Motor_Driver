//
// Created by Geoff Berl on 3/4/17.
//

#ifndef MOTORDRIVER_L298_H
#define MOTORDRIVER_L298_H


#include "HBridgeDriver.h"

/**
 * L298 doesn't add any additional functionality so we just simply extend the HBridgeDriver class and this
 * allows the HBridgeDriver functions to handle manipulations of motors. It's a redundant class as you could
 * simply create an HBridgeDriver object but the point is that you don't need to know that the L298 is an
 * H-Bridge, you just create an L298 object and let the library do the rest.
 */
class L298 : public HBridgeDriver {
public:
  L298(uint8_t motorA1, uint8_t motorA2, uint8_t motorAEnable, uint8_t motorB1, uint8_t motorB2, uint8_t motorBEnable)
      : HBridgeDriver(motorA1, motorA2, motorAEnable, motorB1, motorB2, motorBEnable) {}


};


#endif //MOTORDRIVER_L298_H