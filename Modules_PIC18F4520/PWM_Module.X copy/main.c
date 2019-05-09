/*
 * File:   main.c
 * Author: coryhodge
 *
 * PWM_Module: 
 *      PIC18F4520
 * 
 * 
 * Created on March 13, 2019, 9:55 PM
 */

// 

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
#pragma config PBADEN = OFF      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
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

#define _XTAL_FREQ 8000000

#include <xc.h>

#include "PWM_Module.h"


void main(void) {
    
    
//    PWM_Init();
//    
//    // using RC1 / CCP2
//    TRISC = 0;
//    
//    LATCbits.LATC1 = 1;
    
    TRISB = 0x00;
    LATB = 0xFF;
    
    while(1){
        
     
        
        
        
    }
    
    
    return;
}


void __interrupt ()  timer2 ( void ) {
    
    
    // clear interrupt flag
    PIR1bits.TMR2IF = 0;
    

}





//
//
//
// 
//void PWM1_Init(unsigned char period){
//    TRISC &=0xFD;           //  Set RC2 as output
//    
//    /* CCP PWM mode */
//    CCP1CON &= 0xCF;        //  5,4 bits zeroed (DC1B1:DC1B0 = 00)
//    CCP1CON |= 0x0C;        //  PWM mode ( CCP1M3:CCP1M0 = 1100)
//    
//    /* Timer2 configuration */
//    PR2 = period;           //  configure timer2 period
//    T2CON = 0x02;           //  Set prescalar 16   
//    TMR2ON = 1;             //  timer2 on
//    
//}
// 
//void PWM1_setDC(unsigned int dutycycle){
//    
//    CCPR1L = dutycycle>>2;  //  PWM duty cycle - first 8-bits (MSb)
//    CCP1CON &= 0xCF;        //  5,4 bits zeroed (DC1B1:DC1B0 = 00)
//    CCP1CON |= ((dutycycle<<4)&0x30);  //  PWM duty cycle - last 2-bits (LSb) in CCP1CON 5,4 bits    
//}
// 
//void main()
// {
//    /*open PWM at 2KHz*/ 
//    PWM1_Init(0x270);
//    
//    /*set duty cycle 0 - 1023 range */
//    PWM1_setDC(512);
// 
//    int dc = 0;
//    
//    while(1){
//        
//        while (dc < 1000 ){
//            
//            PWM1_setDC(dc);
//            dc++;
//            __delay_ms(1);
//        }
//        
//        while( dc > 10) {
//            
//            PWM1_setDC(dc);
//            dc--;
//            
//            
//        }
//        
//        
//        
//        
//        
//        
//    }               //  Infinite run
//}