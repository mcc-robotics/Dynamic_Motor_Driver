//
// Created by Geoff Berl on 3/18/17.
//

#ifndef MOTORDRIVER_MOTOR_H
#define MOTORDRIVER_MOTOR_H

#include <stdint.h>
#include <Encoder.h>

class Motor {

public:

  Motor(uint8_t motPin1, uint8_t motPin2) {
    _pin1 = motPin1;
    _pin2 = motPin2;
  }

  uint8_t getPin1() {
    return _pin1;
  }

  uint8_t getPin2() {
    return _pin2;
  }

  /**
   * Get the current power setting for this motor.
   * @return the percentage of power this motor is set to
   */
  int8_t getCurrentPower() {
    return _goalPower;
  }

  /**
   * Simple getter to get the current PWM resolution that is set.
   * @return the current PWM resolution setting
   */
  uint8_t getPWMResolution() {
    return _pwmResolution;
  }

  /**
   * Initialize must be called in setup, this enables the motor pins and initializes the motors in a brake mode.
   */
  virtual void init() {
    // Enable the pins
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);

    // Initialize the motor off
    brake();
  }

  /**
   * Set the power to apply using Coast drive. If you do not want the speed controlled by the encoders you can simply
   * set the power of the motor. If you want feedback controlled motor speeds you should use the velocity functions.
   * It should also be noted that this is dependent on the Max PWM Resolution which is defaulted to 255. If your PWM
   * pin is not 8 bit you should adjust the PWM Resolution accordingly.
   *
   * Coast drive does not apply any brake while driving so the wheel may drift providing less accurate results. Brake
   * drive should be used for most cases.
   * @param power the percentage of power to apply to the motor
   */
  virtual void setCoastDrivePower(int8_t power) = 0;

  /**
   * Set the power to apply using Brake drive. If you do not want the speed controlled by the encoders you can simply
   * set the power of the motor. If you want feedback controlled motor speeds you should use the velocity functions.
   * It should also be noted that this is dependent on the Max PWM Resolution which is defaulted to 255. If your PWM
   * pin is not 8 bit you should adjust the PWM Resolution accordingly.
   *
   * Brake drive ensure that there is little to no coast between PWM pulses so it typically provides a more accurate
   * result than coast drive.
   * @param power the percentage of power to apply to the motor
   */
  virtual void setBrakeDrivePower(int8_t power) = 0;

  /**
   * Brake stops the motors and applies the brakes to do so. This would be the same as stopping with the brakes in a
   * car.
   */
  virtual void brake() = 0;

  /**
   * Coast stops the motors but applies no breaking which allows the motors to coast freely with any current momentum.
   * Using coast can provide inaccurate results, for accuracy, brake should be used.
   */
  virtual void coast() = 0;

  /**
   * Optionally, an encoder can be added and by providing the wheel diameter navigation by distance is achievable.
   * Currently this is only supported functionality for a quadrature encoder on Teensy products.
   * @param pin1    pin 1 for the encoder
   * @param pin2    pin 2 for the encoder
   * @param countsPerRev    the number of counts on the encoder per rotation
   * @param wheelDiameterMM  the diameter of the wheel attached to the motor
   */
  void addEncoder(uint8_t pin1, uint8_t pin2, float countsPerRev, float wheelDiameterMM);

  virtual ~Motor() {
    // Delete encoder in case we created it
    delete(encoder);
  };

protected:

  /**
   * Utility function to convert a -100 to 100 speed to the actual speed range of the motor
   * @param power
   * @return
   */
  int convertPower(int8_t power) {
    return (power * _pwmResolution) / 100;
  }

  /** MOTOR values */
  uint8_t _pin1 = 0;
  uint8_t _pin2 = 0;
  int8_t _goalPower = 0;
  uint8_t _pwmResolution = 255;   // The standard PWM pin is set to 8 bit (255)

  /** Possible Encoder related values */
  Encoder *encoder = nullptr;
  bool encInitialized = false;    // Whether or not the encoder has been initialized

  /** Static Statistical Data */
  float encoderCPR = 0;           // The number of counts in one wheel revolution
  float wheelRadiusMM = 0;      // The radius of the wheel attached to this motor
  float countsPerMM = 0;          // The number of encoder counts in one mm distance
  uint8_t minRequiredPower = 0;   // The minimum power required to move the wheel (weight, lever arm, etc factor into this)
  float maximumMMPerSecond = 0;   // The maximum velocity achievable by this motor
  float circumference = 0;        // The circumference of the wheel (so we don't need to keep computing it)

  // Time variables
  uint32_t lastUpdateMicros = 0;  // The last micros time that an update was performed
  uint32_t elapsedMicros = 0;     // The number of micros that elapsed from the last update to the current update


};

void Motor::addEncoder(uint8_t pin1, uint8_t pin2, float countsPerRev, float wheelDiameterMM) {
  // Create a new encoder object
  encoder = new Encoder(pin1, pin2);
  Motor::encoderCPR = countsPerRev;
  Motor::wheelRadiusMM = wheelDiameterMM / 2;
  // Counts per millimeter is equal to CPR / Circumference
  Motor::circumference = (float) (2 * PI * wheelRadiusMM);
  Motor::countsPerMM = encoderCPR / circumference;
  encInitialized = true;
}

#endif //MOTORDRIVER_MOTOR_H
