#include <stdio.h>

int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);

    /* if (x > 46340) goto main_else; */
    if (x <= 46340) goto main_else;

        printf("square too big for 32 bits\n");
        goto main_end;
    /* } else { */
main_else:
        y = x * x;
        printf("%d\n", y);
    /* } */
main_end:

    return 0;
}
