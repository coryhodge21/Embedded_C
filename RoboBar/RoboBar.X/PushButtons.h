/* 
 * File:   PushButtons.h
 * Author:  Cory W. Hodge
 * Comments:    Module for 4 button input bartender interaction
 * Revision history:  8/3/19
 */

#ifndef XC_HEADER_PushButtons
#define	XC_HEADER_PushButtons

#include <xc.h> // include processor files - each processor file is guarded.  

/**
 *  Main Program Navigation
 *    drink selection made from here
 *      
 */
void ReadButtons(void){
    
    // local variable for keeping user in confirmation loop
    int confirm_choice_flag = 0;
    
    
    //De bounce Key Pad between every read
    __delay_ms(50);
    
    // Cycle Display lower in Drink array
    if( KEY_DOWN == 0 ){
        
        // decrement master_index, and display next drink
        // to LCD
        if(master_index > 0 ){
            master_index--;
            Lcd_Display_Drink(master_index);
        }         
        
    }
    
    // Cycle Display higher in Drink Array
    if( KEY_UP == 0 ){
        
        // increment master_index if more drinks in list, and display
        if( ( (master_index + 1) < sizeof(DRINKS_LIST) ) ){
            master_index++;
            Lcd_Display_Drink(master_index);
        } // else end of DRINKS_LIST, Restart Array
        else {
            master_index = 0;
            Lcd_Display_Drink(master_index);
        }
    }
    
    // Confirm and make drink selection
    if( KEY_CONFIRM == 0 ){
        
        /*
         * Display Confirm Choice Screen
         */
        Lcd_Confirm_Choice();
        
        // keep program here until selection made
        while ( confirm_choice_flag == 0 ){
        
            // quick pause to allow user selection
            __delay_ms(50);
        
            // confirm choice and make drink
            if( KEY_CONFIRM == 0 ){
            
                /**
                 *  Perform the tasks necessary to
                 *  make the drinks indicated by the 
                 * curr_index of the **DRINKS[] Array 
                 */
                Make_Drink();
                 
                
                // set flag to exit loop and start again
                confirm_choice_flag = 1;  
                __delay_ms(50);
            }
            
            // cancel choice and return to main
            if (KEY_CANCEL == 0 ){
                
                // return to list view
                Lcd_Display_Drink(master_index);
                
                // return program to main
                confirm_choice_flag = 1;
            }
        }
        
    }
   
}

#endif	/* XC_HEADER_TEMPLATE_H */

