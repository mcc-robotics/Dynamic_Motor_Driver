//
// Created by Geoff Berl on 3/4/17.
//

#ifndef MOTORDRIVER_L298_H
#define MOTORDRIVER_L298_H


#include "HBridgeMotor.h"

/**
 * L298 doesn't add any additional functionality so we just simply extend the HBridgeDriver class and this
 * allows the HBridgeDriver functions to handle manipulations of motors. It's a redundant class as you could
 * simply create an HBridgeDriver object but the point is that you don't need to know that the L298 is an
 * H-Bridge, you just create an L298 object and let the library do the rest.
 */
class L298 : public MotorDriver {
public:
  L298(unsigned char motorA1, unsigned char motorA2, unsigned char motorAEnable, unsigned char motorB1,
       unsigned char motorB2, unsigned char motorBEnable) {
    // Create the motors
    motorA = new HBridgeMotor(motorA1, motorA2, motorAEnable);
    motorB = new HBridgeMotor(motorB1, motorB2, motorBEnable);
  }


};


#endif //MOTORDRIVER_L298_H
