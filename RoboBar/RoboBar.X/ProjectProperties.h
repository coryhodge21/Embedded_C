/* 
 * File:   ProjectProperties
 * Author:  Cory W. Hodge
 * Comments:    One file to contain all setup
 *              directions , definitions, and global variables
 * Revision history: 8/3/19
 */

#ifndef XC_HEADER_ProjectProperties
#define	XC_HEADER_ProjectProperties


 // PIC18F4520 Configuration Bit Settings

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
#pragma config LVP = OFF         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
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


/**
 *      CRYSTAL FREQUENCY
 */
#define _XTAL_FREQ 8000000


/* Port Definitions */

/**
 *  LCD 
 *
 */
#define EN LATDbits.LATD0
#define RS LATDbits.LATD1
#define D4 LATDbits.LATD2
#define D5 LATDbits.LATD3
#define D6 LATDbits.LATD4
#define D7 LATDbits.LATD5

/**
 * 
 * Push Buttons 
 *
 */
#define KEY_UP PORTAbits.RA0
#define KEY_DOWN PORTAbits.RA3
#define KEY_CONFIRM PORTAbits.RA1
#define KEY_CANCEL PORTAbits.RA2

/* 
 * 
 * 
 * Stepper Motor 
 * 
 * 
 * 
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
#define STEPPER_EN    LATEbits.LE0
#define STEPPER_DIR   LATEbits.LE1
#define STEPPER_PUL   LATEbits.LE2
#define STEPPER_FULL_STEP  250

// define positions for machine ingredients 
// in terms of stepper motor steps
// @ full step rotation speed
#define HOME_POSITION 0

#define VODKA_POSITION 5
#define WHISKEY_POSITION 10
#define TEQUILA_POSITION 15
#define GIN_POSITION 20
#define WHITE_RUM_POSITION 25
#define DARK_RUM_POSITION 30
#define BLUE_CARACAO_POSITION 35
#define TRIPLE_SEC_POSITION 40


/**
 * 
 * Servo Motors
 * 
 */












/**
 *      Project @global variables
 */

/*
 * **DRINKS_LIST[] : This is the collection of all the drinks
 *                      each element of this array is a set of instructions
 *                      for making the drink, listed by its name
 * 
 *              Array of Pointer Arrays: 
                    **LIST [  *X [ A['A'], B['B' ], C['C'] ] , 
 *                            *Y [ A['A'], B['B' ], C['C'] ] ,
 *                            *Z [ A['A'], B['B' ], C['C'] ] ]    
 * 
 *             The Size of this array must be set here for global
 *                  use. Leave note in Drinks.h to update this value       
*/  
// @global
char ** DRINKS_LIST[5];

// @global this index value will be the current position of the **DRINKS_LIST array
// index used for LCD interaction and initiation of drink making
unsigned int master_index;

// @global  current position of stepper motor
unsigned int curr_position;

// Stepper Motor Sequence for movement
int full_step_sequence[4] = {0b1100, 0b0110, 0b1100, 0b1001};
//int half_step_sequence[8] = {0b0001, 0b0011, 0b0010, 0b0110, 0b0100, 0b1100 , 0b1000, 0b1001};



#endif	/* XC_HEADER_TEMPLATE_H */

