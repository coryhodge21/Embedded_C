/*
 * File:   main.c
 * Author: coryhodge
 *
 * Created on March 12, 2019, 11:48 AM
 */



// PIC18F4520 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = INTIO7     // Oscillator Selection bits (Internal oscillator block, CLKO function on RA6, port function on RA7)
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
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LCD_MODULE.h"


/**
 * Set up ADC
 *  AD Control Reg 0:
 *      <5:2> : Channel select (default) 000
 *      <1>   : ADON: Turn on ADC
 * 
 *  AD Control Reg 2:
 *      <7>   : ADFM: Format regiseter L/R Justified
 *      <2:0> : ADCS: Conversion Select = F,osc / AD-prescaler eq
 */
void ADC_Init()
{
  // Turn on ADC On
  ADCON0bits.ADON = 1;
  
  // Format A/D register, Right Justified ( data on lower bits of port )
  ADCON2bits.ADFM = 1;
  
  // conversion clock select bits: pg (F,osc / 4)
  ADCON2bits.ADCS2 = 1;
  ADCON2bits.ADCS1 = 0;
  ADCON2bits.ADCS0 = 0;

 
}

/**
 * AD Function for selecting channel to read, 
 *    if more than one chanel being used by program
 * 
 *    ADCON0 <5:2>: Channel select bits CH3,2,1,0
 * 
 */
void ADC_Channel_Select( int channel ){
    
    // Clear Channel Select Bits
    // Clear Go/Done
    // keep ADCON0bits.ADON as 1
    ADCON0 &= 0b00000001;
    
    // Select Channel, pg223
    // ADCON0 |= 0b00 xxxx 00;
    switch (channel) {
        
        case 0 :
            ADCON0 |= 0b00000000;
            break;
            
        case 1 :
            ADCON0 |= 0b00000100;
            break;
            
        case 2 :
            ADCON0 |= 0b00001000;
            break;
            
        case 3 :
            ADCON0 |= 0b00001100;
            break;
            
        case 4 :
            ADCON0 |= 0b00010000;
            break;
                
        case 5 :
            ADCON0 |= 0b00010100;
            break;
             
        case 6 :
            ADCON0 |= 0b00011000;
            break;
            
        case 7 :
            ADCON0 |= 0b00011100;
            break;
            
        case 8 :
            ADCON0 |= 0b00100000;
            break;
            
        case 9 :
            ADCON0 |= 0b00100100;
            break;
            
        case 10 :
            ADCON0 |= 0b00101000;
            break;
            
        case 11 :
            ADCON0 |= 0b00101100;
            break;
                
        case 12 :
            ADCON0 |= 0b00110000;
            break;
            
        default:
            break;   
    }
}

/**
 * Read AD Value and return result
 * 
 *  this function assumes channel has been set
 *  good for projects with one AD channel
 */
unsigned int AD_Read(void){
    
    // Set Read Bit high
    ADCON0bits.GO_nDONE = 1;
    
    // wait for read to complete
    while(ADCON0bits.GO_nDONE);
    
    // return value read from pre defined channel
    // AD REgiSter High byte ADRESH
    // AD REgiSter Low byte  ADRESL
    
    // splitting return for demonstration
    unsigned int full_16_bit_value = (ADRESH<<8) + ADRESL;
    
    // with analog pot read is 100 - 1 000; divide by 100 for easier use
    full_16_bit_value /= 100;
    
    return full_16_bit_value;
    
}

/**
 * All in one function to read from selected channel
 */



void main(void) {
    
    // Set led Port Pins as Output
    TRISD = 0x00;
    LATD = 0x00; // clear
    
    // Set ADC Port pin as input (AN0)
    TRISA = 0xFF;
    

    // Set up ADC
    ADC_Init();
    
    // Select ADC Channel to use
    ADC_Channel_Select(0);
    
    // Variables for general program use
    unsigned int AD_Delay = 0;
    
    unsigned int AD_Read_Count = 0;
    
    int AD_Value = 0;

    
    while(1){
        
        if( AD_Delay == 1000 ){
            
            AD_Value = AD_Read();
            
            
            // no voltage
            if ( AD_Value <= 0 ){
                
                LATD0 = 1;
            } else {
                LATD0 = 0;
            }
            
            // greater than 1
            if ( AD_Value > 1 ){
                LATD1 = 1;
            } else {
                LATD1 = 0;
            }
            
            // greater than 10
            if ( AD_Value > 7 ){
                LATD2 = 1;
            } else {
                LATD2 = 0;
            }
            
            // greater than 20
            if ( AD_Value > 8 ){
                LATD3 = 1;
            } else {
                LATD3 = 0;
            }
            
            
            
            AD_Delay = 0;
            
            AD_Read_Count++;
            
            
        }
        
        AD_Delay++;
        
        
        
        
    }
    
    
    
    return;
}
