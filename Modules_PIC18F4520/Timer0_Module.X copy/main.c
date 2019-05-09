/*
 * File:   main.c
 * Author: coryhodge
 *
 * Created on March 12, 2019, 8:43 AM
 * 
 * Notes:   This is a working example of the Timer 0
 *              interrupt. with LED on portD will blink at ~ .1 seconds
 *           
 */



// PIC18F4520 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = INTIO67    // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 8000000

#include <xc.h>
 
int tick_count = 0x0;

//void interrupt tc_int(void);
 
void main(void)
{
    // Turn on Timer 0
    T0CONbits.TMR0ON = 0x01;               
    
    // 8 bit counter register
    T0CONbits.T08BIT = 1;
    
    // Internal Clock as Source
    T0CONbits.T0CS = 0;
    
    // Timer Source Edge Select l-h transition
    T0CONbits.T0SE = 0;
    
     /**
     *  Choose divisor <2:0>
     * 
     *  Internal clock:  f,chip= 8M Hz ~ (8,000,000)cycles / 1 second
     *  Cycles / Instruction = 4
     *  frequency of system f,sys = f,chip / ( Cycle/Instruction )
     *      * w/ prescale = f,sys = ( f,chip ) / ( Cycle/Instruction * Pre Scale );
     *  (time)Period between clock ticks = T,sys = 1/(f,sys)
     *  > Timer will run interupt every 8bit / 16bit overflow 
     * Timer,interrupt = T,sys * (8/16 bit) = interrupt time in seconds
     * 
     * PIC18F4520 = Internal Osc = 8M
     * 
     * Cycles / Instruction = 4
     * 
     * f,sys = 8M / 4 = 2M
     * 
     *  * No Pre scaler
     * 
     *  T,sys = 1/2M = 2^-6 seconds = 2us 
      * 
      * T, tmr overflow, 8 bit = 2us / 255 = 7.8125 ns
     * 
     * 
     */
    // Bypass Pre Scale
    T0CONbits.PSA = 1;
    
    // Pre Scale : pg 123
    // T0CONbits.T0PS2 = 0;
    // T0CONbits.T0PS1 = 0;
    // T0CONbits.T0PS0 = 0;
    
    // Enable Global Interrupts
    INTCONbits.GIE = 1;
    
    // Enable perepherial (internal Oscillator) to trigger interrupts
    INTCONbits.PEIE = 1;
    
    // Enable Timer0 Overflow Interrupt
    INTCONbits.TMR0IE = 1;
    
    // diable priorities
    RCONbits.IPEN=0x0;

    // OSCillator Set such Port A is IO useable
    //#pragma config OSC = INTIO67    // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
    TRISA = 0xFF;
    
    /*
     * Program setup
     */
    TRISD = 0x00;
    
    LATD = 0xFF;
    
    while (1){
        
    }
        
}
 


void __interrupt () my_isr_routine (void) {

    if (INTCONbits.TMR0IE && INTCONbits.T0IF)
    {
        // clear flag
        INTCONbits.T0IF=0;
        
        // do stuff
        ++tick_count;
        
        // every tick occurs T,overflow ~ 255 counts
        // 8ns * 
        if (tick_count == 0xFF ){
            
            tick_count = 0;
            
            LATD = ~LATD;
        }
      
    }
}
 
