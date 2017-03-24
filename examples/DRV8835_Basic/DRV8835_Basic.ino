#include <DRV8835.h>

/*
 * This is a simple example of how to use the DRV8835 library with your Arduino compatible board.
 *
 * Be sure to change the values for your motor pins. Also be sure that you have attached each motor pin to
 * an appropriate PWM capable pin as the library uses PWM controls.
 *
 *
 * HOOKUP GUIDE for the DRV8835 motor driver board from Pololu <https://www.pololu.com/product/2135
 *                                   ___________
 *           Common Ground  <--  GND |         | GND   --> Common Ground
 * + Logic voltage (2-7 V)  <--  VCC |         | VIN   --> + Motor voltage (usually 6V or 12V)
 *                 MCU PWM  <-- BIN2 |         | BOUT2 --> To motor B
 *                 MCU PWM  <-- BIN1 |         | BOUT1 --> To motor B
 *                 MCU PWM  <-- AIN2 |         | AOUT2 --> To motor A
 *                 MCU PWM  <-- AIN1 |         | AOUT1 --> To motor A
 *                          <-- MODE |_________| VMM   -->
 *
 */

/*
 * Initialize our driver with the pins (motorA1, motorA2, motorB1, motorB2) and we're assuming:
 * Motor A = Left motor
 * Motor B = Right motor
 * The pins here would map to AIN1, AIN2, BIN1, BIN2 respectively
 * Also, note that this constructor requires that you have either driven Mode low on the chip or done nothing with it.
 * If you have driven the mode HIGH you would use ```DRV8835 driver(3, 4, 5, 6, PHASE_ENABLE_MODE);```
 */
DRV8835 driver(3, 4, 5, 6);


void setup() {
  // The only thing left to do is call init() so the library can initialize the pins
  driver.init();

  // Now, we will just call our main code here so that it only happens once

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