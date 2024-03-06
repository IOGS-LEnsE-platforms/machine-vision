/**
 * FILENAME :        MachineVision_pinouts.h          
 *
 * DESCRIPTION :
 *       Machine Vision Conveyor system based on Nucleo Board
 *              List of global variables and pinouts of the system
 *
 * NOTES :
 *       Developped by Villou / LEnsE
 **
 * AUTHOR :    Julien VILLEMEJANE        START DATE :    15/jan/2024
 *
 *       LEnsE / Institut d'Optique Graduate School
 *          http://lense.institutoptique.fr/
 *          https://github.com/IOGS-LEnsE/machine-vision
 */

#ifndef     __MACHINE_VISION_PINOUTS_H__
#define     __MACHINE_VISION_PINOUTS_H__

#include "mbed.h"
#include "StepMotor_TMC2100.h"

#define     DEBUG       true

// Step-Motor Driver / Motor 1
DigitalOut      en(PB_13);
DigitalOut      dir(PB_3);
PwmOut          step(PA_10);
InterruptIn       step_in(PC_4);
StepMotor_TMC2100   my_motor(&en, &dir, &step, false);
DigitalOut      M1_CFG1(PB_14);
DigitalOut      M1_CFG2(PB_15);
DigitalOut      M1_CFG3(PB_1);  // Not connected by default / Need to move a jumper

AnalogOut       M1_VREF(PA_4);

// Lighting sources
DigitalOut      Light_RED(PC_3);
DigitalOut      Light_GREEN(PC_2);
DigitalOut      Light_BLUE(PH_1);

// Presence Sensors
InterruptIn     Pres_Sensor_1(PC_14);
InterruptIn     Pres_Sensor_2(PC_15);
InterruptIn     Pres_Sensor_3(PH_0);

#endif