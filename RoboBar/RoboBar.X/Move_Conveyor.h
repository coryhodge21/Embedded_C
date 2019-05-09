
/* 
 * File:   
 * Author: 
 * Comments:    Method for moving conveyor 
 * Revision history: 
 */


#ifndef XC_HEADER_Move_Conveyor
#define	XC_HEADER_Move_Conveyor

#include <xc.h> // include processor files - each processor file is guarded.  


/**
 * Stepper Required @global vars
 * int curr_position    :   curr_position of stepper motor, initialize to 0
 *                          as HOME base for conveyor positioning.
 * 
 * // Enable : High , Low to send signal
 * #define STEPPER_EN    LATXbits.LATXx
 * 
 * // Direction : High forward, Low reverse
 * #define STEPPER_DIR   LATXbits.LATXx
 * 
 * // Pulse: each pulse received is one step 
 * #define STEPPER_PUL   LATXbits.LATXx
 * 
 */







/**
 * Stepper Setup
 */
void Stepper_Init(){
    
    // Prepare port E to send signals DIO
    ADCON0bits.ADON = 0; // turn off A/D Conversion
    ADCON1bits.PCFG3 = 1;   //  set all Analog pins as DIO
    ADCON1bits.PCFG2 = 1;
    ADCON1bits.PCFG1 = 1;
    ADCON1bits.PCFG0 = 1;
    
    // Set 3 Ports of I/O as output 
    //      to control driver
    TRISE = 0x00; // output to stepper driver
    
    // Initialize port values
    // LEDS ATTACHED SHOWS Pins working 
//      STEPPER_EN = 1;
//    __delay_ms(50);
//    STEPPER_DIR = 1;
//    __delay_ms(50);
//    STEPPER_PUL = 1;
//    __delay_ms(50);
//    STEPPER_EN = 0;
//    __delay_ms(50);
//    STEPPER_DIR = 0;
//    __delay_ms(50);
//    STEPPER_PUL = 0;
//    __delay_ms(50);
    
    // initialize global variable
    curr_position = 0;
}


/**
 *  Function to step the motor in reverse direction
 * 
 * @param next_position
 * 
 * @global curr_position
 * 
 * @return 
 */
void Move_Conveyor_Reverse( int next_position ) {
    
    // Set Direction of Motor spin to high for reverse
    STEPPER_DIR = 1;
    
    // turn on movement
    STEPPER_EN = 1;
    
    for (int i = STEPPER_FULL_STEP; i > 0; i--){
            
        STEPPER_PUL = 1;
            
        __delay_us(5);
            
        STEPPER_PUL = 0;
            
        __delay_us(5);
    }
    
    // turn off movement
    STEPPER_EN = 0;
    
    // adjust current position by one step
    curr_position--;
}

/**
 *  Function to step the motor in reverse direction
 * 
 * @param next_position
 * 
 * @global curr_position
 * 
 * @return 
 */
void Move_Conveyor_Forward( int next_position ) {
    
    // Set Direction of Motor spin to low for forward
    STEPPER_DIR = 0;
    
    // turn on movement
    STEPPER_EN = 1;
    
    for (int i = STEPPER_FULL_STEP; i > 0; i--){
            
        STEPPER_PUL = 1;
            
        __delay_us(5);
            
        STEPPER_PUL = 0;
            
        __delay_us(5);
    }
    
    // turn off movement
    STEPPER_EN = 0;
    
    // adjust current position by one step
    curr_position++;
}



/*
 * Move_Conveyor :      uses @global curr_position to 
 */
void Move_Conveyor( char * next_position ){
    
    
    /* 
     * VODKA */
    if ((strcmp(next_position , "VODKA") == 0 ) ){
            
        // if position past vodka, move back to it
        if (curr_position > VODKA_POSITION ){
                
            while(curr_position > VODKA_POSITION ){
            Move_Conveyor_Reverse(VODKA_POSITION);
            }
        }
            
        // if position before VODKA, move forward to it
        else if (curr_position < VODKA_POSITION) {
                
            while(curr_position < VODKA_POSITION ){
            Move_Conveyor_Forward(VODKA_POSITION);
            }
        }
    // else position ==
    }   
        
    
    /* 
     * WHISKEY*/
    if ( (strcmp(next_position , "WHISKEY") == 0 ) ){
            
        // if position past Whiskey, move back to it
        if (curr_position > WHISKEY_POSITION ){
                
            while(curr_position > WHISKEY_POSITION){
            Move_Conveyor_Reverse(WHISKEY_POSITION);
            }
        }

        // if position before Whiskey , move forward to it
        else if (curr_position < WHISKEY_POSITION) {
                
            while(curr_position < WHISKEY_POSITION){
            Move_Conveyor_Forward(WHISKEY_POSITION);
            }
        }
    // else position ==
    }
    
    /* 
     * TEQUILA*/
    if ( (strcmp(next_position , "TEQUILA") == 0 ) ){
            
        // if position past TEQUILA, move back to it
        if (curr_position > TEQUILA_POSITION ){
                
            while(curr_position > TEQUILA_POSITION){
            Move_Conveyor_Reverse(TEQUILA_POSITION);
            }
        }

        // if position before TEQUILA, move forward to it
        else if (curr_position < TEQUILA_POSITION) {
            
            while(curr_position < TEQUILA_POSITION){
            Move_Conveyor_Forward(TEQUILA_POSITION);
            }
        }
    // else position ==
    }
    
    
    /* 
     * GIN*/
    if ( (strcmp(next_position , "GIN") == 0 ) ){
            
        // if position past GIN, move back to it
        if (curr_position > GIN_POSITION ){
                
            while(curr_position > GIN_POSITION){
            Move_Conveyor_Reverse(GIN_POSITION);
            }
        }

        // if position before GIN, move forward to it
        else if (curr_position < GIN_POSITION) {
                
            while(curr_position < GIN_POSITION){
            Move_Conveyor_Forward(GIN_POSITION);
            }
        }
    // else position ==
    }
    
    
    /* 
     * White Rum*/
    if ( (strcmp(next_position , "WHITE_RUM") == 0 ) ){
            
        // if position past White Rum, move back to it
        if (curr_position > WHITE_RUM_POSITION ){
             
            while(curr_position > WHITE_RUM_POSITION){
            Move_Conveyor_Reverse(WHITE_RUM_POSITION);
            }
        }

        // if position before White Rum, move forward to it
        else if (curr_position < WHITE_RUM_POSITION) {
                
            while(curr_position < WHITE_RUM_POSITION){
            Move_Conveyor_Forward(WHITE_RUM_POSITION);
            }
        }
    // else position ==
    }
         
    /* 
     * Dark Rum*/
    if ( (strcmp(next_position , "DARK_RUM") == 0 ) ){
            
        // if position past DARK Rum, move back to it
        if (curr_position > DARK_RUM_POSITION ){
                
            while(curr_position > DARK_RUM_POSITION ){
            Move_Conveyor_Reverse(DARK_RUM_POSITION);
            }
        }

        // if position before DARK Rum, move forward to it
        else if (curr_position < DARK_RUM_POSITION) {
                
            while(curr_position < DARK_RUM_POSITION){
            Move_Conveyor_Forward(DARK_RUM_POSITION);
            }
        }
    // else position ==
    }
    
    /* 
     * BLUE_CARACAO*/
    if ( (strcmp(next_position , "BLUE_CARACAO") == 0 ) ){
            
        // if position past BLUE_CARACAO, move back to it
        if (curr_position > BLUE_CARACAO_POSITION ){
                
            while(curr_position > BLUE_CARACAO_POSITION ){
            Move_Conveyor_Reverse(BLUE_CARACAO_POSITION);
            }
        }

        // if position before BLUE_CARACAO, move forward to it
        else if (curr_position < BLUE_CARACAO_POSITION) {
                
            while(curr_position < BLUE_CARACAO_POSITION){
            Move_Conveyor_Forward(BLUE_CARACAO_POSITION);
            }
        }
    // else position ==
    }
    
    /* 
     * TRIPLE_SEC*/
    if ( (strcmp(next_position , "TRIPLE_SEC") == 0 ) ){
            
        // if position past TRIPLE_SEC, move back to it
        if (curr_position > TRIPLE_SEC_POSITION ){
               
            while(curr_position > TRIPLE_SEC_POSITION) {
            Move_Conveyor_Reverse(TRIPLE_SEC_POSITION);
            }
        }

        // if position before TRIPLE_SEC, move forward to it
        else if (curr_position < TRIPLE_SEC_POSITION) {
                
            while(curr_position < TRIPLE_SEC_POSITION){
            Move_Conveyor_Forward(TRIPLE_SEC_POSITION);
            }
        }
    // else position ==
    }
    
    
    
    /* 
     * HOME */
    if ( (strcmp(next_position , "HOME") == 0 ) ){
            
        // if position past HOME, move back to it
        if (curr_position > HOME_POSITION ){
              
            while(curr_position > HOME_POSITION ) {
            Move_Conveyor_Reverse(HOME_POSITION);
            }
        }

        // if position before HOME, move forward to it
        else if (curr_position < HOME_POSITION) {
            
            while(curr_position < HOME_POSITION){
            Move_Conveyor_Forward(HOME_POSITION);
            }
        }
    // else position ==
    }
}



void Move_Conveyor_HOME( void) {
    
            // if position past HOME, move back to it
        if (curr_position > HOME_POSITION ){
              
            while(curr_position > HOME_POSITION ) {
            Move_Conveyor_Reverse(HOME_POSITION);
            }
        }

        // if position before HOME, move forward to it
        else if (curr_position < HOME_POSITION) {
            
            while(curr_position < HOME_POSITION){
            Move_Conveyor_Forward(HOME_POSITION);
            }
        }
    
    
}
#endif	/* XC_HEADER_TEMPLATE_H */