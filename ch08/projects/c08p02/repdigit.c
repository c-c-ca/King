/* Checks numbers for repeated digits */

#include <stdbool.h>   /* C99 only */
#include <stdio.h>

int main(void)
{
    int i, digit_count[10] = {0};
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    do {
        digit_count[n % 10]++;
    } while ((n /= 10) > 0);
    
    printf("Digit:      ");
    for (i = 0; i < 10; i++)
        printf("%3d", i);
    printf("\n");

    printf("Occurrences:");
    for (i = 0; i < 10; i++)
        printf("%3d", digit_count[i]);
    printf("\n");

    return 0;
}
