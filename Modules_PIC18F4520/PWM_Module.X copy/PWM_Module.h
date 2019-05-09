
/* 
 * File:   PWM_Module.h
 *
 * Author: Cory W. Hodge
 * 
 * Comments: PIC18F4520-I/P PDIP
 * 
 * Revision history: today :)
 */

#ifndef XC_PWM
#define	XC_PWM


#define _XTAL_FREQ 8000000


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
    
    /* ( INTCON ) Interrupt Control Register  */
    
    // Global Interrupt Enable
    INTCONbits.GIE = 1; 
    
    // Peripheral Interrupt Enable (Timer is peripheral)
    INTCONbits.PEIE = 1;
    
    
    /* Peripheral Interrupt Enable Register 1 */
    
    // Timer 2 match Period set in PR2 Interrupt Enable
    PIE1bits.TMR2IE = 1;
    
    /* ( RCON ) Reset Control Register  */
    
    // Enable Priorities on interrupts
    RCONbits.IPEN = 1;
    
    /* ( IPR1) Peripheral Interrupt Priority Reg1 */
    
    // Make Timer 2 a high priority to get seperate Service routine
    IPR1bits.TMR2IP = 1; // high
    
    /* ( T2CON ) Timer 2 Control Register  */
    
    // Turn on Timer 2
    T2CONbits.TMR2ON = 1;
    
    // Timer 2 PRESCALE [1:0], 00 = 1, 01 = 4, 1x = 16;
    T2CONbits.T2CKPS1 = 0;
    T2CONbits.T2CKPS0 = 1;  // PRE Scale = 4
    
    
    /* ( CCP2CON ) Control Register 2 */
    
    // Use CCP as PWM 11xx
    CCP2CONbits.CCP2M3 = 1;
    CCP2CONbits.CCP2M2 = 1;
    
    
    /*  ( PIR1.TMR2IF ) Peripheral Interrupt Request (FLAG) Register 1 */
    // Timer 2 Interrupt Flag, must be cleared in software 
    // Sets when TMR2 == PR2 
    // syntax: PIR1bits.TMR2IF
    
    /* (PR2) Period Register 2   ( defaults to 0xFF )
     *                                            
     * PR2 = [ (_XTAL_FREQ)  * ( 1 / desired PWM frequence ) /  ( 4 ) * ( 1 / Timer 2 PreScale ) 
     * 
     * PWM desired frequency 2k Hz
     * 
     * Pre Scale 4
     * 
     * _XTAL_FREQ defined for PIC18F 4520 as 8M
    */ 
    PR2 = 0xFF;  // 5k Hz PWM Frequency
            

    
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
    CCPR2L = 0b10000000;

    // bit 1
    CCP2CONbits.DC2B1 = 0;
    // bit 0
    CCP2CONbits.DC2B0 = 0;
    
    // Set Pin as Output, see data sheet for ccp1 & ccp2 pins
    TRISC1 = 0;
    
}








#endif

    /**
     *  Set timer Pre Scale:  
     * 
     * period of PWM signal T,pwm :
     *      
     *          T,pwm = [( PR2 ) + 1 ] * 4 * T,osc * (TMR2_Prescale_Value) 
     * 
     * frequency of PWM signal f,pwm :
     * 
     *          f,pwm = 1/T,pwm 
     * 
     * duty cycle of PWM signal d,pwm :
     * 
     *          d,pwm = 10 bit resolution, registers
     *                                     [ CCP
     * 
     * 
     * 
    */
    