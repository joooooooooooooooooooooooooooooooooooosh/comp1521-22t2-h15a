#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// 320 = 3 * 100 + 2 * 10 + 0 * 1
// 20  = 0b0001 0100
// flip all bits
//     = 0b1110 1011
// add one
// -20 = 0b1110 1011 + 1
// -20 = 0b1110 1100
//
// -1  = 0b1111 1111
// -2  = 0b1111 1110
// -3  = 0b1111 1101
//
//
// -5 + 7
// 5  = 0b0000 0101
// flip bits
//    = 0b1111 1010
//
//add one 1111 111
// -5 = 0b1111 1011
// 7  = 0b0000 0111
//
// -5 + 7
//    = 0b0000 0010

int main(int argc, char **argv) {
    uint16_t a = 30000 + 30000;
    printf("%d\n", a);
    return EXIT_SUCCESS;
}

