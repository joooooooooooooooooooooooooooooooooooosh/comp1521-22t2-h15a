#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 2) return EXIT_FAILURE;

    char *ls = "ls";
    size_t len = strlen(ls) + strlen(argv[1]) + 2;
    char *command = malloc(len);
    snprintf(command, len, "%s %s", ls, argv[1]);
    system(command);
    return EXIT_SUCCESS;
}

