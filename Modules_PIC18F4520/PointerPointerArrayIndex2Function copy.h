
/* 
 * File:   Drinks.h
 * Author:  Cory W. Hodge
 * Comments: File Containing all drinks and drink pointer definitions
 * Revision history: 8/9/19
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_DRINKS
#define	XC_HEADER_DRINKS

#include <xc.h> // include processor files - each processor file is guarded.  



/* Global Array of pointer arrays to Drink Instructions 
*/
char ** DRINKS[3];





void Build_Drink_Array(void) {
    
    
    /* Strings permitted to put in ** drink_instructions */
    char * HOME = "HOME";
    
    char * VODKA = "Vodka";
    char * WHISKEY = "WHISKEY";
    char * TEQUILA = "TEQUILA";
    char * GIN = "GIN";
    char * WHITE_RUM = "WHITE_RUM";
    char * DARK_RUM = "DARK_RUM";
    char * BLUE_CARACAO = "BLUE_CARACAO";
    char * TRIPLE_SEC = "TRIPLE_SEC";
    
    char * DRINK1 = "Drink1";
    char * DRINK2 = "Drink2";
    char * DRINK3 = "Drink3";
    
  
    /* Array of Character Arrays(strings)*/
    char * DRINK1_INSTRUCTION[3] = {DRINK1, VODKA, HOME};
    char * DRINK2_INSTRUCTION[3] = {DRINK2, WHISKEY, HOME};
    char * DRINK3_INSTRUCTION[4] = {DRINK3, GIN, TEQUILA, HOME};
    
    /* Array of Arrays of Character Arrays(strings) */
    char **DRINKS[3] = {DRINK1_INSTRUCTION, DRINK2_INSTRUCTION, DRINK3_INSTRUCTION};
    
    
    /**
     *      Development Help on using Arrays: 
     * 
     *  Pass string to function as *char 
     *                                      Lcd_Write_String(DRINK1);
     * 
     * 
     * 
     *  Pass index of array of arrays, 
     *  this is first string in             Lcd_Write_String(Drink1_list[0]);
     *  Array of string arrays 
     * 
     * 
     *  Pass index to element of Array of String arrays
     *  this is first element of 
     *  Array of
     *  Array of                             Lcd_Write_String(*DRINKS[0]);
     *  Character Arrays (string)       
     *      
     * 
     * 
     * 
    */
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        
        /* Pass string to function as *char   */
        Lcd_Write_String(DRINK1);
        
        __delay_ms(100);
        
        Lcd_Clear();
        
        Lcd_Set_Cursor(1,1);
        
        /* Pass index of array of arrays, 
         * this is first string in 
         * Array of string arrays */
        Lcd_Write_String(DRINK1_INSTRUCTION[0]);
        
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String(DRINK2_INSTRUCTION[0]);
        
        __delay_ms(100);
        
        Lcd_Clear();
        
        Lcd_Set_Cursor(1,1);
        /*
         * Pass index to element of Array of String arrays
         * this is first element of 
         * Array of
         *    Array of
         *      Character Arrays (string)
         */
        Lcd_Write_String(*DRINKS[0]);
        
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String(*DRINKS[1]);
        

    
    
}




#endif	/* XC_HEADER_TEMPLATE_H */

