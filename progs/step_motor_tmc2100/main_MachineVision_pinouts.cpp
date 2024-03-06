/**
 * FILENAME :        main.cpp          
 *
 * DESCRIPTION :
 *       Machine Vision Conveyor system based on Nucleo Board
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

#include "mbed.h"
#include "MachineVision_pinouts.h"

#define     MAX_MODE    4


/// JoyCar inputs/outputs declaration - based on Joy-It Car platform
Ticker controlLoopTik;

InterruptIn     mode_change(BUTTON1);
uint8_t         mode_val = 0;


/* Methods */
/**
 * Interrupt routine attached to the sampling of the Contol Loop System
 *
 * @return Updates the system control loop outputs
 */
void ISR_controlLoopTik(void);

/**
 * Interrupt routine attached to the mode change button
 */
void ISR_change_mode(void);

/**
 * Test of the conveyor 
 */
void conveyor_test(void);

/* Main code */
int main()
{
    // Initialization 
    printf("Machine Vision / Platform Initialization\r\n");
    // 1/2 step
    M1_CFG1 = 0;
    M1_CFG2 = 0;

    // Light test
    Light_RED = 1;
    Light_GREEN = 1;
    Light_BLUE = 1;

    mode_change.fall(&ISR_change_mode);

    // Conveyor test
    conveyor_test();
    // Initialization of main ticker
    controlLoopTik.attach(&ISR_controlLoopTik, 100us);
    
    while (true){
    }
}


/* */
void ISR_controlLoopTik(void){


}

/* */
void ISR_change_mode(void){
    if(mode_val >= MAX_MODE-1){
        mode_val = 0;
    }
    else{
        mode_val++;
    }

    switch(mode_val){
        case 0:
            my_motor.goForward(250);
            printf("\tM-0-Forward\r\n");
            Light_RED = 0;
            Light_GREEN = 1;
            Light_BLUE = 1; 
            break;          
        case 1:
            my_motor.stop();
            printf("\tM-1-Stop\r\n");
            Light_RED = 1;
            Light_GREEN = 0;
            Light_BLUE = 1; 
            break;
        case 2:
            my_motor.goBackward(250);
            printf("\tM-2-Backward\r\n");
            Light_RED = 1;
            Light_GREEN = 1;
            Light_BLUE = 0; 
            break; 
        case 3:
            my_motor.stop();
            printf("\tM-3-Stop\r\n");
            Light_RED = 0;
            Light_GREEN = 0;
            Light_BLUE = 0; 
            break; 
        default:
            printf("\tM-x-x\r\n");
            Light_RED = 1;
            Light_GREEN = 1;
            Light_BLUE = 1; 
    }
}


void conveyor_test(void){
    if(DEBUG)   printf("Machine Vision / Conveyor Test\r\n");
    if(DEBUG)   printf("\tForward (2s)\r\n");
    my_motor.goForward(250);
    thread_sleep_for(2000);      // 2 s
    printf("\tStop (1s)\r\n");
    my_motor.stop();
    thread_sleep_for(1000);      // 1 s
    printf("\tBackward (2s)\r\n");
    my_motor.goBackward(300);
    thread_sleep_for(2000);      // 2 s
    printf("\tStop (1s)\r\n");
    my_motor.stop();
    thread_sleep_for(1000);      // 1 s
    printf("\tEnd of conveyor test\r\n");
}