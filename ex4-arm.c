// Experiment 4: ARM/PLC

#include <stdint.h>

// Define memory locations (you can adjust these based on your setup)
volatile uint8_t* sourceMemory = (volatile uint8_t*)0x20000000; // Example source memory address
volatile uint8_t* destMemory = (volatile uint8_t*)0x40000000;   // Example destination memory address

// Number of data elements (N)
#define NUM_ELEMENTS 10

int main() {
    uint32_t i;

    // Move data from source to destination
    for (i = 0; i < NUM_ELEMENTS; ++i) {
        // Read data from source memory
        uint8_t data = *sourceMemory;

        // Process the data (multiply by a factor, e.g., 2)
        uint8_t processedData = data * 2;

        // Write processed data to destination memory
        *destMemory = processedData;
    }

    // Program stops here
    while (1) {
        // Add any other necessary logic or tasks
    }

    return 0;
}
