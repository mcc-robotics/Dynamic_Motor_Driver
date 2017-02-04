//
// Created by gberl on 2/3/2017.
//

#ifndef DRV8835_H
#define DRV8835_H

#define BRAKE_DRIVE 0
#define COAST_DRIVE 1
#define MOTOR_A 0
#define MOTOR_B 1


#include <stdint.h>

class DRV8835 {

public:
    DRV8835(uint8_t motorA1, uint8_t motorA2, uint8_t motorB1, uint8_t motorB2);

    ~DRV8835() {
        delete motorA;
        delete motorB;
    }

    /*
     * Functions that explicitly call out the motor
     */

    void setMotorACoastSpeed(int8_t speed);

    void setMotorABrakeSpeed(int8_t speed);

    void setMotorBCoastSpeed(int8_t speed);

    void setMotorBBrakeSpeed(int8_t speed);

    void motorABrake();

    void motorACoast();

    void motorBBrake();

    void motorBCoast();

    /**
     * Set the motor speed for motor A. You may optionally define a drive type of brake or coast. The drive type
     * is defaulted to brake in which an active brake will be applied to the motor to reduce coasting while moving
     * @param speed     the percent of power to apply to the motor (-100 to +100)
     * @param driveType OPTIONAL drive type
     */
    void setMotorASpeed(int8_t speed, uint8_t driveType = BRAKE_DRIVE);

    /**
     * Set the motor speed for motor A. You may optionally define a drive type of brake or coast. The drive type
     * is defaulted to brake in which an active brake will be applied to the motor to reduce coasting while moving
     * @param speed     the percent of power to apply to the motor (-100 to +100)
     * @param driveType OPTIONAL drive type
     */
    void setMotorBSpeed(int8_t speed, uint8_t driveType = BRAKE_DRIVE);

    /*
     * Functions that control either motor, just pass in which one
     */

    void setCoastSpeed(int8_t speed, uint8_t motor);

    void setBrakeSpeed(int8_t speed, uint8_t motor);

    void brake(uint8_t motor);

    void coast(uint8_t motor);

    /*
     * Functions to control both motors simultaneously
     */

    void setAllCoastSpeed(int8_t speed);

    void setAllBrakeSpeed(int8_t speed);

    void brakeAll();

    void coastAll();

private:

    class DRV8835Motor {
    public:
        DRV8835Motor(uint8_t pin1, uint8_t pin2);

        void forwardBrake(uint8_t speed);

        void reverseBrake(uint8_t speed);

        void forwardCoast(uint8_t speed);

        void reverseCoast(uint8_t speed);

        void brake();

        void coast();

    private:

        uint8_t _pin1;
        uint8_t _pin2;

    };

    uint8_t convertSpeed(int8_t speed);

    DRV8835Motor *motorA;
    DRV8835Motor *motorB;
    const static uint8_t _MAX_SPEED = 255;

};


#endif // DRV8835_H
