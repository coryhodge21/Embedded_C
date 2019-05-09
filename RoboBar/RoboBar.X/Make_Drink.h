
/* 
 * File:   Make_Drink.h
 * 
 * Author:  Cory W. Hodge
 * 
 * Comments:    Method for initiating drink creation
 * 
 * Revision history: 8/10/19
 */

#ifndef XC_HEADER_Make_Drink
#define	XC_HEADER_Make_Drink

#include <xc.h> // include processor files - each processor file is guarded.  


/**
 *  For every Instruction in Drink Array,
 *   Move stepper to proper location
 *   and dispense drink
 */
void Make_Drink( void ){
    
    // capture selected drink choice
    char ** Instruction_Set = DRINKS_LIST[master_index];
    
    Lcd_Clear();
    
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Making :");
    
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String(Instruction_Set[0]);
    
    // index 0 is drink name
    unsigned int instruction_index = 1;
    while( strcmp(Instruction_Set[instruction_index], "HOME") != 0){
        
        // Display to Lcd acknowledgment of next ingredient arg: char *
        Lcd_Adding_Ingredient(Instruction_Set[instruction_index]);
        
        // Move Conveyor to Proper Location arg: char *
        Move_Conveyor(Instruction_Set[instruction_index]);
        
        // Dispense Ingredient arg: char *
        Dispense_Ingredient(Instruction_Set[instruction_index]);
        
        instruction_index++;
        
    }
    
    // Final Step is to return drink to HOME position
    Move_Conveyor_HOME();
    
    // Display result too screen
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(Instruction_Set[0]);
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String("Complete");
    __delay_ms(100);
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Display_Drink(master_index);
    
    
}

#endif	/* XC_HEADER_TEMPLATE_H */

