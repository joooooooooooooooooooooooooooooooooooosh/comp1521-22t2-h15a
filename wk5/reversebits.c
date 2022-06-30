#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Word;
Word reverseBits(Word w) {
    Word ret = 0;
    int num_bits = sizeof(Word) * 8;
    for (int i = 0; i < num_bits; i++) {
        // i = 0, mask = 1000 0000 0000 0000 ...
        // i = 1, mask = 0100 0000 0000 0000 ...
        Word mask = 1 << ((num_bits - 1) - i);
        if ((w & mask) != 0) {
            mask = 1 << i;
            ret = ret | mask;
        }
    }

    return ret;
}

int main(int argc, char **argv) {
    Word w = 0x01234567;
    printf("%X\n", reverseBits(w));
    return EXIT_SUCCESS;
}

