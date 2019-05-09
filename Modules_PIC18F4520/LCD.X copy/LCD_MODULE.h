

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

/**
 * Set the pins of the MCU to 
 *  prepare LCD for Reading 
 * 
 * @param alpha
 */
void LCD_Set_Pins(char lower_nibble)
{
    
	if(lower_nibble & 1)
		D4 = 1;
	else
		D4 = 0;

	if(lower_nibble & 2)
		D5 = 1;
	else
		D5 = 0;

	if(lower_nibble & 4)
		D6 = 1;
	else
		D6 = 0;

	if(lower_nibble & 8)
		D7 = 1;
	else
		D7 = 0;
}


/**
 * Send value to LCD pins 
 * set LCD to receive in 
 * instruction mode
 * 
 * @param cmd
 */
void LCD_Cmd(char cmd)
{
    // Instruction mode
	RS = 0;           
    
    // Set MCU pins
	LCD_Set_Pins(cmd);
    
    // Start LCD Reading
	EN  = 1;             
    
    // wait for LCD to finish read
    __delay_ms(4);
    
    // End Read
    EN  = 0;           
}

/**
 * Quick Clear Screen 
 * function
 * 
 * @return void
 */
void Lcd_Clear(void)
{
	LCD_Cmd(0);
	LCD_Cmd(1);
}

/**
 * Set Cursor position on LCD
 * 4 bit mode, send upper byte then lower
 * 
 * @param row
 * @param col
 */
void Lcd_Set_Cursor(char row, char col)
{
	char position,upper_nibble,lower_nibble;
    
    // if row 1, base value is 0x80
	if(row == 1)
	{
	  position = 0x80 + col - 1;
      
    // else row 2, base value is 0xC0  
    } else{
        position = 0xC0 + col - 1;
    }
    
    // extract upper nibble
	upper_nibble = position>>4;
        
    //extract lower nibble
	lower_nibble = position & 0x0F;
        
    // send upper nibble
    LCD_Cmd(upper_nibble);
        
    // send lower nibble
    LCD_Cmd(lower_nibble);

}

/**
 * LCD Command initializations
 * to set up LCD for 4 bit mode
 * no cursor shown but moves in 
 * right hand direction, display on
 * 
 */
void Lcd_Init()
{
  LCD_Set_Pins(0x00);
   __delay_ms(10);
  LCD_Cmd(0x03);
	__delay_ms(5);
  LCD_Cmd(0x03);
	__delay_ms(10);
  LCD_Cmd(0x03);
  LCD_Cmd(0x02);
  LCD_Cmd(0x02);
  LCD_Cmd(0x08);
  LCD_Cmd(0x00);
  LCD_Cmd(0x0C);  
  LCD_Cmd(0x00);
  LCD_Cmd(0x06);
   
}

void Lcd_Write_Char(char alpha)
{
   char upper_nibble,lower_nibble;
   
   // extract nibbles
   upper_nibble = alpha & 0xF0;
   lower_nibble = alpha & 0x0F;

   
   // send upper nibble
   // Data Mode
   RS = 1;            
   
   // shift upper nibble to lower position for pin read
   LCD_Set_Pins( upper_nibble >> 4 );         
   
   // Read
   EN = 1;
   __delay_us(40);
   EN = 0;
   
   // send lower nibble
   LCD_Set_Pins(lower_nibble);
   EN = 1;
   __delay_us(40);
   EN = 0;
}

/**
 * write string to LCD
 * 
 * @param string
 */
void Lcd_Write_String(char *string)
{
	int i;
    
    // index string one char at a time, end at null terminating character
	for(i=0; string[i] !='\0' ;i++)
	   Lcd_Write_Char( string[i] );
}

/**
 * Methods for moving LCD screen text 
 * Left and Right by one position
 */
void Lcd_Shift_Right(void)
{
	LCD_Cmd(0x01);
	LCD_Cmd(0x0C);
}
void Lcd_Shift_Left(void)
{
	LCD_Cmd(0x01);
	LCD_Cmd(0x08);
}

#endif	/* XC_HEADER_TEMPLATE_H */

