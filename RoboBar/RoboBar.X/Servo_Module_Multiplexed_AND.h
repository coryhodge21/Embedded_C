/* 
 * File:   SERVO_MULTIPLEXED_AND.h
 * Author:  Cory W. Hodge
 * Comments:   Functions for actuating servos multiplexed with 2 
 *              and gates from port B 
 * Revision history: 4/10/19
 */

#ifndef XC_SERVO_MULTIPLEXED_AND
#define	XC_SERVO_MULTIPLEXED_AND

#include <xc.h> // include processor files - each processor file is guarded.  


void Servo_Init(void){
    
    Interrupt_Init();
    Timer_2_Init();
    PWM_Init();
    
    
    
/**
     * Program setup
     */
    // timer2 tester
    TRISB = 0x00;
    LATB = 0x00;
    
    // PWM: CCP2 = PortC. RC1
    TRISCbits.RC1 = 0;
    

}


/**
 * Set the position of the servo arm
 *
 * @param Position
 */
void Servo_Set_Position(int Position){
    
    // Mask upper 8 bits and lower 2 bits of duty cycle
    int upper_8_bits = Position>>2;
    
    CCPR2L = upper_8_bits;
    
    //bit 1
    CCP2CONbits.DC2B1 = (Position&2);
    // bit 0
    CCP2CONbits.DC2B0 = (Position&1);
    
}

void Servo_Actuate(void){
    

         Servo_Set_Position(130);
         __delay_ms(200);
         Servo_Set_Position(50);
}

void Servo_Select(int servo){
    
    /*
     * Multiplexer:
     *  EN = 1 // off
     *  EN = 0 // On
     */
    
    /**
     * 
     * Multiplexer logic:
     *   En = 1 : N/A
     *   S = 0000 : 0 out
     *   S = 1111 : 15 out
     * 
     */ 
    switch (servo) {
        
        case (0) :
            
            LATBbits.LATB0 = 1;
            
            Servo_Actuate();
            __delay_ms(100);
            LATBbits.LATB0 = 0;
            
            break;
      
        case (1) :
            
            LATBbits.LATB1 = 1;
            
            Servo_Actuate();
            __delay_ms(100);

            LATBbits.LATB1 = 0;
            
            break;
        
        case (2) :
            
            LATBbits.LATB2 = 1;
            
            Servo_Actuate();
            __delay_ms(100);
            LATBbits.LATB2 = 0;
            
            break;   
            
        case (3) :
            
            LATBbits.LATB3 = 1;
            
            Servo_Actuate();
            __delay_ms(100);
            LATBbits.LATB3 = 0;
            
            break;
         case (4) :
            
            LATBbits.LATB4 = 1;
            
            Servo_Actuate();
            __delay_ms(100);
            LATBbits.LATB4 = 0;
            
            break;
        case (5) :
            
            LATBbits.LATB5 = 1;
            
            Servo_Actuate();
            __delay_ms(100);
            LATBbits.LATB5 = 0;
            
            break;
        case (6) :
            
            LATBbits.LATB6 = 1;
            
            Servo_Actuate();
            __delay_ms(100);
            LATBbits.LATB6 = 0;
            
            break;
        case (7) :
            
            LATBbits.LATB7 = 1;
            
            Servo_Actuate();
            __delay_ms(100);
            LATBbits.LATB7 = 0;
            
            break;
           
       
        
        default:
            break;
            
            
    }
    
}

#endif	/* XC_SERVO_MULTIPLEXED_AND */

