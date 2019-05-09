
/* 
 * File:    Simulate_Uart
 * Author:      Cory W. Hodge
 * Comments:        File Containing UART methods
 *                  for setting up UART, and directions 
 *                  on how to use it in project
 * Revision history:  8/10/19
 */

/*
 * Steps to set up in project:
 * 
 *  1. define output method putch or include stdio.h for printf
 * 
 *  2. initilize UART console by setting TXEN and SPEN to 1
 * 
 *  3. R.Click Project Folder in Open Projects Pane
 *     > Set Configuration > Customize
 *     > L.Click active configuration
 *     > in harware pane switch from PICKIT debugger to Simulator
 *     > Simulator option under active configuration will appear, L. Click it
 *     > in Simulator options drop down, select UART IO Options
 *     > check box to enable UART IO 
 * 
 *  4. use printf or putch in program
 * 
 *  5. Debug Program ( only works in debug mode with simulator )
 *     > Oputput windows: one will be UART, this is where text is displayed!
 *     > Right Click or CMD + L to clear previous text
 * 
 */
#ifndef XC_HEADER_UART
#define	XC_HEADER_UART

#include <xc.h> // include processor files - each processor file is guarded.  


// for writing to UART console with printf for simulation
#include <stdio.h>  // For printf("");

// for writing to UART console during simulation
void putch(unsigned char data) {
    while( ! PIR1bits.TXIF)          // wait until the transmitter is ready
        continue;
    TXREG = data;                     // send one character
}

// set bits to initialize UART use
void init_uart( ){
    
    TXSTAbits.TXEN = 1;    // enable transmitter
    RCSTAbits.SPEN = 1;    // enable serial port
}
















#endif	/* XC_HEADER_TEMPLATE_H */

