

/* 
 * File:   PWM_Module.h
 * Author:  Cory W. Hodge
 * Comments:    Setup function for using CCP2 as PWM on PortC.RC1
 * Revision history: 8/20/19
 */

 
#ifndef XC_CCP2_PWM
#define	XC_CCP2_PWM

#include <xc.h> 

/**
 * PWM: 
 * 
 * Signal is generated with TIMER 2
 * 
 * 1. Period: T,pwm :Write period to PR2
 * 
 * 2. Duty Cycle: d,pwm : write cycle to CCPRxL:CCPxCON<5:4>
 * 
 * 3. Set TRIS port pin as output C or B
 * 
 * 4. Set TMR2 Prescale and enable TMR2
 * 
 * 5. Config CCPx Module 
 * 
 */
void PWM_Init(void){
    
/** Registers to set for PWM **/

    // Timer 2: Period Register ( 4 bit (default) 0xFF )
    // using 200(dec) so duty cycle can be ~approx the pulse width in ms
    PR2 = 0xC8;
    
    /* ( CCP2CON ) Control Register 2 */
    
    // MODE: Use CCP as PWM 11xx
    CCP2CONbits.CCP2M3 = 1;
    CCP2CONbits.CCP2M2 = 1;
    CCP2CONbits.CCP2M1 = 1;
    CCP2CONbits.CCP2M0 = 1;

    /**
     * Duty Cycle 
     *  
     *  this is a weird thing and needs re visiting, unsure of the influence PRS
     *      has on this value. However, this gives the duty cycle in a measurment
     *      of time? where the 10 bits between CCPR2L and CCP2CON make up a number
     *      between 0 and 123, representing the ratio of the duty cycle
     *      - 50% duty cycle = 1024/2 = 512; 
     *        convert to binary 10 bit number ( 0b 10 00 00 00 00 00 )
     *        store in registers:
     *        CCPR2L= 0b 10 00 00 00 
     *        CCP2CONbits. = 0;
     *        CCP2CONbits. = 0;
     * 
     *  d,pwm = (CCPRxL:CCPxCON<5:4>) * ( 1 / f, osc ) * ( Pre Scale Value) 
     */
    // 8 most significant bits
    CCPR2L = 0b01111111;

    // bit 1
    CCP2CONbits.DC2B1 = 0;
    // bit 0
    CCP2CONbits.DC2B0 = 0;
    
    // Set Pin as Output, see data sheet for ccp1 & ccp2 pins
    TRISCbits.RC1 = 0;
    
}

#endif	/* XC_CCP2_PWM */

