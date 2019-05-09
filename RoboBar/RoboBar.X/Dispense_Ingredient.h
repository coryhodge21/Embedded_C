

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_Dispense_Ingredient
#define	XC_HEADER_Dispense_Ingredient

#include <xc.h> // include processor files - each processor file is guarded.  

void Dispense_Ingredient( char * ingredient ) {

       
    /* 
     * VODKA */
    if ((strcmp(ingredient , "VODKA") == 0 ) ){
            
        Servo_Select(0);
    }   
        
    
    /* 
     * WHISKEY*/
    if ( (strcmp(ingredient , "WHISKEY") == 0 ) ){
        Servo_Select(2);
    }
    
    /* 
     * TEQUILA*/
    if ( (strcmp(ingredient , "TEQUILA") == 0 ) ){
            
        Servo_Select(2);
    }
    
    
    /* 
     * GIN*/
    if ( (strcmp(ingredient , "GIN") == 0 ) ){
        Servo_Select(3);
    }
    
    
    /* 
     * White Rum*/
    if ( (strcmp(ingredient , "WHITE_RUM") == 0 ) ){
        Servo_Select(4);
    }
         
    /* 
     * Dark Rum*/
    if ( (strcmp(ingredient , "DARK_RUM") == 0 ) ){
            Servo_Select(5);

    }
    
    /* 
     * BLUE_CARACAO*/
    if ( (strcmp(ingredient , "BLUE_CARACAO") == 0 ) ){
        Servo_Select(6);

    }
    
    /* 
     * TRIPLE_SEC*/
    if ( (strcmp(ingredient , "TRIPLE_SEC") == 0 ) ){
       Servo_Select(7);

    }
}

#endif	/* XC_HEADER_TEMPLATE_H */

