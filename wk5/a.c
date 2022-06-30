#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//   0 - f
//   0000 - 1111
// a = 0x5555
//   = 0b0101010101010101
// b = 0xABCD
//   = 0b1010101111001101
//
// a     = 0b0101010101010101
// b     = 0b1010101111001101
// a | b = 0b1111111111011101
//
// a     = 0b0101010101010101
// b     = 0b1010101111001101
// a & b = 0b0000000101000101
//
// a     = 0b0101010101010101
// b     = 0b1010101111001101
// a ^ b = 0b1111111010011000
//
// b     = 0b1010101111001101
// ~b    = 0b0101010000110010
// a     = 0b0101010101010101
// a &~b = 0b0101010000010000
//
// b << 5= 0b0111100110100000
// b >> 7= 0b0000000101010111

#define READING   0x01 // 0b0000 0001
#define WRITING   0x02 // 0b0000 0010
#define AS_BYTES  0x04 // 0b0000 0100
#define AS_BLOCKS 0x08 // 0b0000 1000
#define LOCKED    0x10 // 0b0001 0000
                       // 0b0000 0001

int main(int argc, char **argv) {
    uint8_t device;
    // mark the device as locked for reading bytes 
    device = LOCKED;
    device = device | READING;
    device = device | AS_BYTES;

    // mark the device as locked for writing blocks
    // note: first example could also be done like this
    device = LOCKED | WRITING | AS_BLOCKS;

    // toggle the lock on a device, leaving other flags unchanged
    // current device: 0b0001 1010
    //         locked: 0b0001 0000
    //         xor   : 0b0000 1010
    //         target: 0b0000 1010
    device = device ^ LOCKED;

    // remove the lock on a device, leaving other flags unchanged
    // current device: 0b0000 1010
    //        ~locked: 0b1110 1111
    //         and   : 0b0000 1010
    //         target: 0b0000 1010
    device = device & ~LOCKED;

    // swap a device between reading and writing, leaving other flags unchanged 
    // option a:
    //   device: 0b0000 1010
    //   toggle: 0b0000 0011
    //   target: 0b0000 1001
    //
    // option b:
    //   device: 0b0000 1001
    //   toggle: 0b0000 0011
    //   target: 0b0000 1010
    device = device ^ (READING | WRITING);

    printf("%0X\n", device);

    return EXIT_SUCCESS;
}

