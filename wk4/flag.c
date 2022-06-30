#include <stdio.h>

char flag[6][12] = {
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'}
};

// typedef char[12] row;
// sizeof(row) = 12 * sizeof(char)
// row flag[6]
// &flag[2] = &flag + 2 * sizeof(row)
// &flag[2] = &flag + 2 * 12 * sizeof(char)
// &flag[2][5] = (&flag + 2 * 12) + 5 * sizeof(char)

// char aaaa[12]
// &aaaa[3] = &aaaa + 3 * sizeof(char)
//          = &aaaa + 3 * 1
// int aaaa[12]
// &aaaa[3] = &aaaa + 3 * sizeof(int)
//          = &aaaa + 3 * 4

int main(void) {
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 12; col++)
            printf ("%c", flag[row][col]);
        printf ("\n");
    }

}
