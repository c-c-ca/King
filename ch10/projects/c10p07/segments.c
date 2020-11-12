#include <stdio.h>

#define MAX_DIGITS 10

/* external variables */
const int segments[10][7] = {{1, 1, 1, 1, 1, 1},
                             {0, 1, 1},
                             {1, 1, 0, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};
char digits[4][MAX_DIGITS * 4]; 

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
    char ch;
    int position = 0;

    clear_digits_array();

    printf("Enter a number: ");
    while (position < MAX_DIGITS && (ch = getchar()) != '\n')
        if ('0' <= ch && ch <= '9')
            process_digit(ch - '0', position++);
    
    print_digits_array();
    
    return 0;
}

void clear_digits_array(void)
{
    int i, j;

    for (i = 0; i < 4; i++)
        for (j = 0; j < MAX_DIGITS * 4; j++)
            digits[i][j] = ' ';
}

void process_digit(int digit, int position)
{
    int segment, row, col;

    for (segment = 0; segment < 7; segment++)
        if (segments[digit][segment]) {
            switch (segment) {
                case 0: row = 0; col = 1; break;
                case 1: row = 1; col = 2; break;
                case 2: row = 2; col = 2; break;
                case 3: row = 2; col = 1; break;
                case 4: row = 2; col = 0; break;
                case 5: row = 1; col = 0; break;
                case 6: row = 1; col = 1; break;
            }
        digits[row][col + position * 4] = segment % 3 ? '|' : '_';
        }
}

void print_digits_array(void)
{
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < MAX_DIGITS * 4; j++)
            putchar(digits[i][j]);
        putchar('\n');
    }
}        
