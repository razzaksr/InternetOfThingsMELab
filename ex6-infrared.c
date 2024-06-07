// Experiment 6: Infrared test

/*

Infrared Sensor (IR):
An electronic component used to detect specific characteristics 
in its surroundings through emitting or detecting IR radiation.

IR sensors can detect heat, motion, and proximity.
They operate in the infrared part of the electromagnetic spectrum.
Commonly used in remote controls, security systems, and automation.

Working Principle of IR Sensors:
IR sensors include two parts: the emitter and the receiver 
(also called an optocoupler or photo-coupler).

Active IR Sensors:
Emit and detect modulated infrared beams.
Used for distance measurement and obstacle detection.
Example: Reflective sensors in line-following robots.

Passive IR Sensors (PIR):
Only receive radiation emitted by nearby objects.
Detect human presence based on body heat.
Commonly used in motion detectors and automatic lighting systems.

Types of Infrared Sensors:

Photonic Infrared Sensors:
Measure IR radiation.
Used in fiber optics and IR sensors.

Pyroelectric Infrared Sensors:
Detect changes in temperature.
Ideal for motion detection (e.g., PIR motion sensors).

Thermal Infrared Sensors:
Detect heat radiated from objects.
Used in thermal imaging cameras and temperature measurement.

Quantum Infrared Sensors:
Detect energy absorbed or emitted during electron transitions.
Used in gas analyzers and spectroscopy.

*/

#include <avr/io.h>

int main() {
    // Set PA0 as input (IR sensor connected here)
    DDRA &= ~(1 << 0);

    // Set PD0 as output (LED indicator connected here)
    DDRD |= (1 << 0);

    while (1) {
        if (bit_is_set(PINA, 0)) {
            // Sensor detected something
            PORTD |= (1 << PIND0); // Turn on LED
        } else {
            PORTD &= ~(1 << PIND0); // Turn off LED
        }
    }

    return 0;
}
