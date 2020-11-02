#include <stdio.h>

int digit(int n, int k);
int main(void)
{
    int n, k;

    printf("Enter a nonnegative integer: ");
    scanf("%d", &n);
    printf("Enter number of digits from the right: ");
    scanf("%d", &k);
    printf("%d is %d digit(s) from the right.\n", digit(n, k), k);

    return 0;
}

int digit(int n, int k)
{
    while (--k > 0)
        n /= 10;
    
    return n % 10;
}