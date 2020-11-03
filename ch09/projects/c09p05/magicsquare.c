#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);
int main(void)
{
    int n, row, col;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    char magic_square[n][n];

    create_magic_square(n, magic_square);
    print_magic_square(n, magic_square);
    
    return 0;
}

void create_magic_square(int n, char magic_square[n][n])
{
	int i, row, col;

	for (row = 0; row < n; row++)
		for (col = 0; col < n; col++)
			magic_square[row][col] = 0;

	row = 0;
	col = n / 2;
	for (i = 1; i <= n * n; i++) {
		magic_square[row][col] = i;
		row = (row - 1 + n) % n;
		col = (col + 1) % n;
		if (magic_square[row][col] > 0) {
			row = (row + 2) % n;
			col = (col - 1 + n) % n;
		}
	}
}

void print_magic_square(int n, char magic_square[n][n])
{
	int row, col;

	for (row = 0; row < n; row++) {
		for (col = 0; col < n; col++)
			printf("%5d", magic_square[row][col]);
		printf("\n");
	}
}

