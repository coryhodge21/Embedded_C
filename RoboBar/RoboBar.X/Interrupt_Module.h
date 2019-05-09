
/* 
 * File:   Interrupt.h
 * Author: Cory W. Hodge
 * Comments:    PIC18F4520-I/P PDIP 
 *              No Priority Interrupt Service Routine
 * Revision history: 8/20/19
 */

 
#ifndef XC_INTERRUPT
#define	XC_INTERRUPT

#include <xc.h> // include processor files - each processor file is guarded.  




// Interrupt variables 

// timer 2 counter
unsigned int tmr2_counter = 0;


/**
 *   Interrupts Initializations 
 * 
 * 
*/
void Interrupt_Init(){
    
    
    /////////////
    /* General */
    /////////////
    
    // Enable Global Interrupts
    INTCONbits.GIE = 1;
    
    // Enable peripheral (internal Oscillator) to trigger interrupts
    INTCONbits.PEIE = 1;

    // diable priorities
    RCONbits.IPEN=0x0;
    
    

    
    
}   // END Interrupt_Init();






/**
 * Main Interrupt Service Routine (ISR)
 * 
 * check source by checking if (Source.enable && Source.flag) bit set
 * 
 */
void __interrupt () my_isr_routine (void) {

    // Handle Timer 2 Interrupts, 
    // timer 2 counter register == PR2 triggers TMR2IF 
    if (T2CONbits.TMR2ON == 1 && PIR1bits.TMR2IF == 1){
    
    
        // BLINK LED: f,blink = f,osc / 4 * prescale
        //LATBbits.LATB0 = ~LATBbits.LATB0;
    
        /*  clear flag  */
        PIR1bits.TMR2IF = 0;
    
    }
    
    // If more interrupt flags, add logic
}










#endif	/* XC_HEADER_TEMPLATE_H */

