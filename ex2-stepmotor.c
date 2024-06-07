//Experiment 2: step motor clockwise and anti clockwise                                                                                                                                                                                                    
#include <reg51.h>  // Include register definitions for 8051

// Define step sequence arrays
unsigned char stepCW[4] = {0x09, 0x0A, 0x06, 0x05};   // Clockwise steps: P2.0 to P2.3
unsigned char stepCCW[4] = {0x05, 0x06, 0x0A, 0x09};  // Counter-clockwise steps

// Simple delay function
void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 127; j++);  // Roughly 1 ms delay
}

void main(void) {
    while (1) {
        // Rotate 50 steps clockwise
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 4; j++) {
                P2 = stepCW[j];  // Apply clockwise step
                delay(10);      // Adjust delay for step speed
            }
        }
        delay(500);  // Pause for half a second

        // Rotate 50 steps anti-clockwise
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 4; j++) {
                P2 = stepCCW[j];  // Apply anti-clockwise step
                delay(10);        // Adjust delay for step speed
            }
        }
        delay(500);  // Pause for half a second
    }
}