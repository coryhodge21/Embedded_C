# RoboBar
Robotic Bartender using PIC18F4520-I/P (PDIP) Microchip
Compiler: X8C


Cory W. Hodge
Robotic Bartender

Chip:    
PIC18F4431-I/P (PDIP)

Peripherals:
➢    Key Pad
➢    LCD Screen
➢    Stepper Motors
➢    Servo Motors
➢    Liquid Pump
➢    LED

Global Variables

Drink_Selection[]: An array to copy the positions of the selected recipe

RECIPIE’s[]: Individual hard coded arrays to hold the positions of the recipe’s

Cur_Pos: holds the current value of the conveyer belt step motor

FLAGS[]:   One Array to act as flag register, set individual elements (flags)

Interrupts:

➢    Read Key Pad : @ KEYPAD_FLAG = 1;
-    Update LCD 
-    Update ( global )Drink_Selection = RECIPIE_ARRAY;
-    Set MAKE_FLAG = 1;

➢    Make( void ) : @MAKE_FLAG = 1;
-    Set local int  ptr *Position  = 
( global )Drink_Selection ~ RECIPIE_ARRAY;
-    Move ( *Position)
-    Dispense ( *Position )
-    Repeat until done
-    Move (0);

➢    Move ( Position ) : @MOVE_FLAG = 1;
-    move drink tray to proper location

➢    Dispense ( Position ) : @DISPENSE_FLAG = 1;
-    Actuate servo at current position

