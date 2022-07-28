#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZ 1000

int main(int argc, char **argv) {
    char *home = getenv("HOME");
    char *pathname = "/.diary";
    size_t len = strlen(home) + strlen(pathname) + 1;
    char *full_pathname = malloc(len);
    snprintf(full_pathname, len, "%s%s", home, pathname);

    FILE *f = fopen(full_pathname, "r");
    if (f == NULL) {
        perror(full_pathname);
        return EXIT_FAILURE;
    }

    char buf[BUF_SIZ];
    size_t read;
    do {
        read = fread(buf, 1, BUF_SIZ, f);
        write(1, buf, read);
    } while (read == BUF_SIZ);

    return EXIT_SUCCESS;
}

