#include <stdio.h>

#define N 5

int main(void)
{
    int row, col, sum, matrix[N][N];

    for (row = 0; row <= N; row++) {
        printf("Enter row %d: ", row + 1);
        for (col = 0; col < N; col++)
            scanf("%d", &matrix[row][col]);
    }

    printf("Row totals:");
    for (row = 0; row < N; row++) {
        for (col = sum = 0; col < N; col++)
            sum += matrix[row][col];
        printf(" %d", sum);
    }
    printf("\n");

    printf("Column totals:");
    for (col = 0; col < N; col++) {
        for (row = sum = 0; row < N; row++)
            sum += matrix[row][col];
        printf(" %d", sum);
    }
    printf("\n");

    return 0;
}