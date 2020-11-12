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
    /* segment 0 */
    if (segments[digit][0])
        digits[0][position * 4 + 1] = '_';

    /* segment 1 */
    if (segments[digit][1])
        digits[1][position * 4 + 2] = '|';

    /* segment 2 */
    if (segments[digit][2])
        digits[2][position * 4 + 2] = '|';

    /* segment 3 */
    if (segments[digit][3])
        digits[2][position * 4 + 1] = '_';

    /* segment 4 */
    if (segments[digit][4])
        digits[2][position * 4] = '|';

    /* segment 5 */
    if (segments[digit][5])
        digits[1][position * 4] = '|';

    /* segment 6 */
    if (segments[digit][6])
        digits[1][position * 4 + 1] = '_';
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
