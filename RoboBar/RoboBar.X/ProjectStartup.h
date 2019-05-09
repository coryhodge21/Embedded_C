
/* 
 * File:   Project Startup .h
 * Author:  Cory W. Hodge
 * Comments:    File for abstracting clutter and localizing port
 *                  initiations. Reducing error and debug time
 * Revision history:  8/10/19
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_Project_Sartup
#define	XC_HEADER_Project_Sartup

#include <xc.h> // include processor files - each processor file is guarded.  


void ProjectStartup(void){
           
    /* All Port Designations here   */
    
    
    /* Push Buttons Port A [0:4] */
    
    // Disable A/D Converter AN0:3 
    ADCON0bits.ADON = 0; // off
    ADCON1bits.PCFG0 = 1;
    ADCON1bits.PCFG1 = 1;
    ADCON1bits.PCFG2 = 1;
    ADCON1bits.PCFG3 = 1;
    
    // Disable Comparator module RA0:3 
    CMCONbits.CM0 = 1;
    CMCONbits.CM1 = 1;
    CMCONbits.CM2 = 1;
    
    // Set Port A as INPUT
    TRISA = 0xFF;
    
    
    /* LCD  Port D [0:5] */
    TRISD = 0x00;
    LATD = 0x00;
    
    /* Stepper Motor Port E */
    Stepper_Init();
    
    /* Initializes Timer0,2, and PWM to servo needs */
    Servo_Init();

    /**
     * @global variable initializations
     */
    
    // index to global **DRINKS_LIST array
    master_index = 0;
    
    // position of drink tray on conveyor belt
    curr_position = 0;
    
    
   
   
}
#endif	/* XC_HEADER_TEMPLATE_H */

