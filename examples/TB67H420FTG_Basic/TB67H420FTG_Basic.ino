#include "TB67H420FTG.h"

/*
 * This is a simple example of how to use the TB67H420FTG_Basic library with your Arduino compatible board.
 *
 * Be sure to change the values for your motor pins. Also be sure that you have attached each motor pin to
 * an appropriate PWM capable pin as the library uses PWM controls.
 *
 *
 * HOOKUP GUIDE for the TB67H420FTG_Basic motor driver board from Pololu <https://www.pololu.com/product/2999
 *                                   ___________
 *                         <--    VM |         |
 *                 Ground  <--   GND |         |
 *                         <--   VCC |         | VIN -->  + Motor voltage (10V - 47V)
 *        MCU Digital (7)  <--  INA1 |         | GND -->  Ground
 *        MCU Digital (8)  <--  INA2 |         | GND -->  Ground
 *            MCU PWM (5)  <--  PWMA |         | B+  -->  To motor B+
 *        MCU Digital (9)  <--  INB1 |         | B-  -->  To motor B-
 *       MCU Digital (10)  <--  INB2 |         | A-  -->  To motor A+
 *            MCU PWM (6)  <--  PWMB |         | A+  -->  To motor A-
 *                         <--   LO1 |         |
 *                         <--   LO2 |         |
 *                         <-- VREFA |_________|
 *
 */

/*
 * Initialize our driver with the pins (motorA1, motorA2, motorAPWM, motorB1, motorB2, motorBPWM) and we're assuming:
 * Motor A = Left motor
 * Motor B = Right motor
 * The pins here would map to INA1, INA2, PWMA, INB1, INB2, PWMB respectively
 * Also, note that this constructor supports the use of using two PWM pins for each motor. In which case you would
 * only need a PWM in each of the INx pins and drive the PWMx pins high either with a 10k resistor to 5V or use a
 * digital pin. In this case the declaration would be (motorA1, motorA2, motorB1, motorB2)
 */
TB67H420FTG driver(7, 8, 5,  9, 10, 6);


void setup() {
  // The only thing left to do is call init() so the library can initialize the pins
  driver.init();

  // What we will do is just call our main code here so that it only happens once

  // Let's move the left motor forward a bit (our motor speed is valued from -100 to +100)
  driver.setMotorAPower(50);  // Set the motor speed to 50% in a forward direction
  delay(1000);                // Wait a second
  driver.motorABrake();       // Stop our motor, we can brake or coast (self explanatory right)

  // Let's move the right motor forward a bit (Motor B this time)
  driver.setMotorBPower(50);  // Set the motor speed to 50% in a forward direction
  delay(1000);                // Wait a second
  driver.motorBBrake();       // Stop our motor

  // Now let's control both motors to drive straight
  driver.setMotorAPower(50);
  driver.setMotorBPower(50);
  delay(1000);                // Wait a second
  driver.brakeAll();          // Notice here we can brake both motors using the brakeAll() function

  // That's it! Now you can see how to control each motor or both motors at the same time.
  // Feel free to change the word 'brake' with 'coast' wherever it shows up to see how coast might differ.
}

void loop() {

}