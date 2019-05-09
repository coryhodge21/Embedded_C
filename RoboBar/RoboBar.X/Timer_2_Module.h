
/* 
 * File:   Timer_2_Module.h
 * Author: Cory W. Hodge 
 * Comments:    Timer 2 setup function, using Timer 2 for PWM
 * Revision history: 8/20/19
 */
 
#ifndef XC_TIMER_2
#define	XC_TIMER_2

#include <xc.h>  


void Timer_2_Init(void){
    
    
    //////////////
    /* TIMER 2  */
    //////////////
    /**
     * 
     *  Timer 2 Interrupt Calculation
     *  
     *      f,osc = freq. of oscillator (Hz rating of chip clock or external clock)
     *      T,osc = Period of Oscillator , 1/f,osc : units of seconds
     * 
     *      f,sys = Freq. of system; = f,osc/4
     *      T,sys = 1/f,sys
     *              time per increment of timer register 
     *              ( timers actual count up register)
     * 
     *      pre-scale: if used, 
     *          f,sys = f,osc/(4 * pre-scale)
     *          T,sys = 1/f,sys
     *      
     *      f,osc = 8M Hz
     *      T,osc = .125us
     * 
     *      f,sys = (8M Hz) / ( 4 * ( 4 ) ) = .5M Hz ( 500k Hz ) 
     *      T,sys = 2us;
     */
    
    
    
    // 1:1 Post Scaler
    T2CONbits.T2OUTPS3 = 0;
    T2CONbits.T2OUTPS2 = 0;
    T2CONbits.T2OUTPS1 = 0;
    T2CONbits.T2OUTPS0 = 0;
    
    // Timer 2 ON
    T2CONbits.TMR2ON = 1;
    
    // Timer 2: Prescale  1 : 16
    T2CONbits.T2CKPS1 = 1;
    T2CONbits.T2CKPS0 = 1;
    
    // Timer 2: Priority (disabled priorities in INTCON *General* )
    //IPR1bits.TMR2IP = 1; // high priority
    
    // Timer 2: Interrupt Enable for PR2 period match
    PIE1bits.TMR2IE = 1;
    
    // Timer 2: Period Register ( 4 bit (default) 0xFF )
    //PR2 = 0xFF;
    // set this in PWM module
    
    // When TMR2 count register == PR2, Flag is set
    // PIR1bits.TMR2IF = 1;
}


#endif	/* XC_HEADER_TEMPLATE_H */

