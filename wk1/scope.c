#include <stdio.h>

void f();

char* s1 = "abc";

int main(void) {
    char* s2 = "def";
    f();
    printf("%s\n", s2);
    printf("&s2 = %p\n", &s2);
    printf("&\"def\" = %p\n", s2);
    printf("%c\n", *s2);
}

void f() {
    int a, b; // only accessible within f
    printf("%s", s1);
}
