#include <stdio.h>

void print_array(int nums[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\n", nums[i]);
    }
}

void print_recursive(int nums[], int i, int len) {
    if (i == len) {
        return;
    }

    printf("%d\n", nums[i]);
    print_recursive(nums, i + 1, len);
}

int main(void)
{
    int nums[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    /* print_array(nums, 10); */
    print_recursive(nums, 0, 10);

    return 0;
}
