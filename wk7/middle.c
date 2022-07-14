#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t six_middle_bits(uint32_t asdf);

int main(int argc, char **argv) {
    printf("%08x\n", six_middle_bits(0x0dfb3b80));
    return EXIT_SUCCESS;
}

// input = 0x0dfb3b80
//                            |     |
// input = 0b 0000 1101 1111 1011 0011 1011 1000 0000
// shift = 0b 0000 0000 0000 0000 0110 1111 1101 1001
// mask  = 0b 0000 0000 0000 0000 0000 0000 0011 1111
// output= 0b 0000 0000 0000 0000 0000 0000 0001 1001
//                                            |     |
// output = 0x00000019

uint32_t six_middle_bits(uint32_t asdf) {
    uint32_t ans = asdf >> 13;
    // ans = ans & 0b00111111;
    ans = ans & 0x3f;

    return ans;
}
