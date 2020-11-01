#include <stdio.h>

int main(void)
{
    int i, n, row, col;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    int m[n][n];

    for (row = 0; row < n; row++)
        for (col = 0; col < n; col++)
            m[row][col] = 0;

    row = 0;
    col = n / 2;
    for (i = 1; i <= n * n; i++){
        m[row][col] = i;
        row = (row - 1 + n) % n;
        col = (col + 1) % n;
        if (m[row][col] > 0) {
            row = (row + 2) % n;
            col = (col - 1 + n) % n;
        }
    }

    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++)
            printf("%5d", m[row][col]);
        printf("\n");
    }
    
    return 0;
}
