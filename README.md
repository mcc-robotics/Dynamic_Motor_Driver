#DRV8835 Motor Driver

This motor driver provides bidirectional control of two DC motors.

##Caveats
The library will work with Arduino or Teensy boards but note that it will do nothing with the PWM frequency. If you want to adjust the PWM frequency you will have to do that outside of this library.

Also, the library currently only supports IN/IN mode. Phase/Enable mode will be added in the future.