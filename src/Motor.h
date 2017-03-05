//
// Created by Geoff Berl on 3/5/17.
//

#ifndef MOTORDRIVER_MOTOR_H
#define MOTORDRIVER_MOTOR_H


class Motor {

public:

  Motor(unsigned char pin1, unsigned char pin2) {
    _pin1 = pin1;
    _pin2 = pin2;

    // Setup pins in case it wasn't done before
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
  }

  unsigned char getPin1() {
    return _pin1;
  }

  unsigned char getPin2() {
    return _pin2;
  }

  char getCurrentPercentageSpeed() {
    return _currentPercentSpeed;
  }

  void setCurrentPercentageSpeed(char percentageSpeed) {
    _currentPercentSpeed = percentageSpeed;
  }

  unsigned int getMaxSpeed() {
    return _maxSpeed;
  }

private:
  unsigned char _pin1 = 0;
  unsigned char _pin2 = 0;
  char _currentPercentSpeed = 0;
  unsigned int _maxSpeed = 255;

};


#endif //MOTORDRIVER_MOTOR_H
