# MultiShiftRegister

MultiShiftRegister (MSR) is an Arduino library for easily interfacing with multiple daisy-chained SIPO (Serial In, Parallel Out) latching shift registers (such as the 74HC595) to greatly expand the number of binary outputs available to the developer.

## Requirements

MSR expects the shift registers to use a CLOCK pin, a LATCH pin, and a DATA pin to control input.

## Installation

Copy all the files in this repository into a MultiShiftRegister folder in your libraries folder found in the root of your sketchbook folder.
After restarting the Arduino IDE, you'll find an example sketch under **File > Examples > MultiShiftRegister**.
