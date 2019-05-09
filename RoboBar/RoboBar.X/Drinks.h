
/* 
 * File:   Drinks.h
 * Author:  Cory W. Hodge
 * Comments: File Containing all drinks and drink pointer definitions
 * Revision history: 8/9/19
 */

  
#ifndef XC_HEADER_DRINKS
#define	XC_HEADER_DRINKS

#include <xc.h> // include processor files - each processor file is guarded.  


/**
 *    !!!      IMPORTANT INFO FOR UPDATING THIS FILE        !!!
 * 
 *          The **DRINKS_LIST[] array is a @global variable and size 
 *          
 *          must be explicitly updated in ProjectProperties.h when
 * 
 *          adding drinks to this program. 
 */

/**
 *  Function to fill all arrays with proper values
*/
void OPEN_DRINK_MENU(){
    
    /*
     * Char * strings : Instructions for making drink, listed as 
     *                      the ingredients name
     * 
     *                  SPECIAL Instruction:    "HOME"
     *                      Required last string of array, terminates the drink
     *                      and instructs the cup tray to the HOME position
     * 
     *                  SPECIAL Instruction:    "DRINK_NAME"
     *                      Required first string of array, this will be 
     *                      displayed to the lcd screen   
    */

    /* Terminate Each array with this value */
      char * HOME = "HOME";
    
    /* TODO:
     * All ingredients can be listed here, if the RoboBar
     *   does not have ingredient in stock, it should flash to
     *   the LCD screen
    */
      
     // LIQUOR
     char * VODKA = "VODKA";
     char * WHISKEY = "WHISKEY";
     char * TEQUILA = "TEQUILA";
     char * GIN = "GIN";
     char * WHITE_RUM = "WHITE_RUM";
     char * DARK_RUM = "DARK_RUM";
    
     // LIQUORE MIXERS
     char * BLUE_CARACAO = "BLUE_CARACAO";
     char * TRIPLE_SEC = "TRIPLE_SEC";
    
    
    /**
     *  All Drink names go here, followed by a _name to 
     *      indicate the drink_X_name 
     *      from the *DRINK_X array
    */
    // Example Drink
     //char * DRINK_name = "NAME OF DRINK";
     char * TEST_EVERYTHING_name = "TEST_EVERYTHING";
     char * LONG_ISLAND_name = "LONG_ISLAND";
     char * DRINK_3_name = "DRINK_3";
     char * DRINK_4_name = "DRINK_4";
     char * DRINK_5_name = "DRINK_5";
     

    /*
     *    *DRINK[] :   This is a an array of string instructions (double pointer)
     *              
     *              The First "string" element, is "The Drinks Name" ,
     *              
     *              The Last "string element, is "HOME" . A special
     *                  instruction terminating the drinks execution
     * 
     *              All Elements in between are "INGREDIENT" strings
     *                  used as instructions for making drink
    */

    // example drink 
    // LIST all Drink instruction sets here, name arrays by the drink name, terminate with HOME
    //char * DRINK[] = { DRINK_name, VODKA, WHITE_RUM, BLUE_CARACAO, OJ, HOME };
    
     // TEST_EVERYTHING
    char * TEST_EVERYTHING[] = { TEST_EVERYTHING_name , VODKA, WHISKEY, TEQUILA, GIN, WHITE_RUM, DARK_RUM, BLUE_CARACAO, TRIPLE_SEC, HOME};
    
    // Long Island Ice Tea
    char * LONG_ISLAND[] = { LONG_ISLAND_name , VODKA, WHISKEY, TEQUILA, GIN, WHITE_RUM, DARK_RUM, BLUE_CARACAO, TRIPLE_SEC, HOME };

    // Tequila Cran 
    char * DRINK_3[] = { DRINK_3_name , WHISKEY, HOME };                                            

    // Whiskey Cran
    char * DRINK_4[] = { DRINK_4_name , GIN, WHITE_RUM, HOME };

    // Screw Driver
    char * DRINK_5[] = { DRINK_5_name , VODKA, TRIPLE_SEC, HOME };

    
    /*  POPULATE DRINKS LIST FOR TOTAL PROGRAM USE @global DRINKS_LIST
     * **DRINKS_LIST[] : This is the collection of all the drinks
     *              each element of this array is a set of instructions
     *              for making the drink, listed by its name
     * 
     *              Array of Pointer Arrays: **LIST [  *X [ A['A'], B['B' ], C['C'] ] , 
     *                                                 *Y [ A['A'], B['B' ], C['C'] ] ,
     *                                                 *Z [ A['A'], B['B' ], C['C'] ] ]
     *      
     * 
     *     @global update size explicitly in ProjectProperties.h
     *         reference at global deceleration
     *         DRINKS_LIST_SIZE ++ ;
    */
    //DRINKS_LIST[i] = DRINK;
    DRINKS_LIST[0] = TEST_EVERYTHING;
    DRINKS_LIST[1] = LONG_ISLAND;
    DRINKS_LIST[2] = DRINK_3;
    DRINKS_LIST[3] = DRINK_4;
    DRINKS_LIST[4] = DRINK_5;
  //DRINKS_LIST_SIZE = 5 (ProjectProperties.h)
  
}
#endif	/* XC_HEADER_TEMPLATE_H */


    /**
     *  Development Help on using Pointer to Pointer Array: 
     * 
     *  Pass string to function as *char 
     * 
     *  >> Lcd_Write_String(DRINK);
     * 
     *  Pass index of Pointer array to function, 
     *  this is first string in nested            
     *  Array of string arrays 
     * >> Lcd_Write_String(Drink1_list[0]);
     * 
     *  Pass index to element of Array of String arrays
     *  this is first element of 
     *  Array of
     *  Array of                             
     *  Character Arrays (string)       
     *  >> Lcd_Write_String(*DRINKS[0]);    
     * 
     *  **DRINKS[  *DRINK_1_INSTRUCTION[   DRINK1 ["DRINK1"] ,   VODKA ["VODKA"] ,   HOME ["HOME] ]   ,
     *                  *DRINK_2_INSTRUCTION  [     DRINK2 [ "DRINK2" ] ,   WHISKEY["WHISKEY"] ,    ... ,  ... ,   HOME ["HOME]  ] ;
     * 
     * 
     *   // Works
     *   //printf( "\n\n");
     *   //printf(**DRINKS_LIST);
     * 
     *  // Works
     *  //printf( "\n\n");
     *  //printf(*DRINKS_LIST[index]);
     * 
     *  // WORKS
     *  //char * string = *DRINKS_LIST[0];
     *  //printf(string);
     *   
     *  // works : 
     *  //Lcd_Display_Drink();
    */