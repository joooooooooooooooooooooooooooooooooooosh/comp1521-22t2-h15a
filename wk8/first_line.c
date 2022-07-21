#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILENAME\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    int c;
    // c = fgetc(f);
    while ((c = fgetc(f)) != EOF) {
        fputc(c, stdout);
        if (c == '\n') break;
        // c = fgetc(f);
    }

    return EXIT_SUCCESS;
}

