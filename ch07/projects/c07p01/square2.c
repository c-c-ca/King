/** 
 * short int values are usually stored in 16 bits,
 * causing failure at 182. int and long int values
 * are usually stored in 32 bits, with failure
 * occurring at 46341.
*/

#include <stdio.h>

int main(void)
{
    int i, n;
    long l;
    short s;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    i = 1;
    while (i <= n) {
        printf("%10d%10d%10hd%10ld\n", 
            i, i * i, s = i * i, l = i * i);
        i++;
    }

    return 0;
}