//Experiment 3: Clock wave forms generation                                                                                                                                                                                                                            
#include <reg51.h>  // Include register definitions for 8051

// Define output pin
sbit OUT_PIN = P1^0;  // Output on P1.0

// Timer 0 interrupt service routine
void timer0_ISR(void) interrupt 1 {
    OUT_PIN = ~OUT_PIN;  // Toggle the output pin
}

// Initialize Timer 0
void initTimer0(void) {
    TMOD = 0x01;  // Timer 0 in mode 1 (16-bit timer)
    TH0 = 0xFC;   // Load high byte for 1ms delay (assuming 12 MHz clock)
    TL0 = 0x66;   // Load low byte for 1ms delay
    ET0 = 1;      // Enable Timer 0 interrupt
    EA = 1;       // Enable global interrupt
    TR0 = 1;      // Start Timer 0
}

void main(void) {
    initTimer0();  // Initialize Timer 0
    OUT_PIN = 0;   // Ensure the output pin starts at 0
    
    while (1) {
        // Main loop does nothing, everything is handled by the timer interrupt
    }
}