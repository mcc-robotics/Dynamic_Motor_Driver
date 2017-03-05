//
// Created by Geoff Berl on 3/5/17.
//

#ifndef MOTORDRIVER_MOTOR_H
#define MOTORDRIVER_MOTOR_H


class Motor {

public:
  unsigned char _pin1 = 0;
  unsigned char _pin2 = 0;
  char _currentPercentSpeed = 0;
  unsigned int _maxSpeed = 255;

};


#endif //MOTORDRIVER_MOTOR_H
