/*
 * File:   main.c
 * Author: cory w hodge
 * Created on March 7, 2019, 3:06 PM
 */

/*
 *  Debugging and Simulation tool
 *  delete before final build
 */
#include "Simulate_Uart.h"

// all #pragma, #define, and @global variables
#include "ProjectProperties.h"

// X8C library
#include <xc.h>
#include <string.h>



// Project Modules
#include "LCD.h"
#include "Drinks.h"
#include "Interrupt_Module.h"
#include "Timer_2_Module.h"
#include "PWM_Module.h"
#include "Servo_Module_Multiplexed_AND.h"
#include "Move_Conveyor.h"
#include "Dispense_Ingredient.h"
#include "Make_Drink.h"
#include "PushButtons.h"

// Start up code
#include "ProjectStartup.h"


/*  BEGIN MAIN */
void main(void) {
    
    /**
     * All Port Definitions and
     *  global initializers go here
     */
    ProjectStartup();
           
     /**
     *  All Module_Initialization() Functions go here
      *     this reduces file inclusions within files
     */
    
    // UART CONSOLE
    //init_uart();
        
    // LCD
    Lcd_Init();
 
    // Build Drinks Array
    // this method initilizes all drinks to 
    // the Master Pointer ***DRINKS
    OPEN_DRINK_MENU(); //Drinks.h
    
    /*
     * Start up Text
    */
    
    // Clear Screen
    Lcd_Clear();
        
    // Position Cursor, write text
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Robo Bar");
        
    // Position Cursor, write text
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String(" V 1.0");
        
    // short pause 1 second
    __delay_ms(100);
    
    
    /**
     * Display First drink in list to update LCD
     *  > displays drink name element string of Drinks_List 
     *    array at current master index value. Default = 0;
     */
    //Lcd_Display_Drink(0);
    // Clear Screen
//    Lcd_Clear();
//    Lcd_Set_Cursor(1,1);
//    Lcd_Write_String(*DRINKS_LIST[0]);
    
    //__delay_ms(100);
    
    
    // Clear Screen
    Lcd_Clear();
        
    // Position Cursor, write text
    Lcd_Set_Cursor(1,1);
    
    // Display Current Drink
    Lcd_Write_String(*DRINKS_LIST[master_index]);
    
    // short pause 1 second
    __delay_ms(100);
    
    /*
     * Infinite Loop
     */
    while(1)
    {
        
        ReadButtons();
        
        
        //Make_Drink();
                
      
        
    }

    // End Program
    return;
}
