#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv) {
    char *filename = "my_file";
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

