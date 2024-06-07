//Experiment 1: buzzer sound by switch
#include <reg51.h>  // Include register definitions for 8051

// Define pin connections for the switch and buzzer
sbit SWITCH = P1^0;  // Switch connected to P1.0
sbit BUZZER = P1^1;  // Buzzer connected to P1.1

void main(void) {
    // Initial pin configurations
    BUZZER = 0;  // Ensure the buzzer is off initially
    
    while (1) {
        // Check if the switch is pressed (assuming active low)
        if (SWITCH == 0) {
            // Switch is pressed, turn on the buzzer
            BUZZER = 1;
        } else {
            // Switch is not pressed, turn off the buzzer
            BUZZER = 0;
        }
    }
}