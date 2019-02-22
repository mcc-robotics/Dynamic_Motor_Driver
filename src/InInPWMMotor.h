//
// Created by Geoff Berl on 2/20/19.
//

#ifndef MOTORDRIVER_ININPWMMOTOR_H
#define MOTORDRIVER_ININPWMMOTOR_H


#include "Motor.h"

class InInPWMDriver : public Motor {

public:
  InInPWMDriver(uint8_t motPin1, uint8_t motPin2, uint8_t motPWM)
      : Motor(motPin1, motPin2) {
    _motorPWM = motPWM;
  }

  /*
   * These are all virtual functions inherited from MotorDriver
   */

  void setCoastDrivePower(int8_t speed);

  void setBrakeDrivePower(int8_t speed);

  void brake();

  void coast();

protected:

    uint8_t _motorPWM;

};


#endif //MOTORDRIVER_ININPWMMOTOR_H