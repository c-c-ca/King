/* Checks numbers for repeated digits */

#include <stdbool.h>   /* C99 only */
#include <stdio.h>

int main(void)
{
    bool digit_seen[10] = {false}, digit_repeated[10] = {false};
    int digit, i;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    do {
        digit = n % 10;
        if (digit_seen[digit])
            digit_repeated[digit] = true;
        else
            digit_seen[digit] = true;
    } while ((n /= 10) > 0);
    
    printf("Repeated digit(s):");
    for (i = 0; i < 10; i++)
        if (digit_repeated[i])
            printf(" %d", i);
    printf("\n");

    return 0;
}
