#include <stdio.h>

int main(void)
{
    float n, largest_num = 0.0f;

    do {
        printf("Enter a number: ");
        scanf("%f", &n);
        if (n > largest_num)
            largest_num = n;
    } while (n > 0.0f);

    if (largest_num > 0.0f)
        printf("The largest number entered was %.2f\n", largest_num);
    else
        printf("No numbers were entered.\n");

    return 0;
}
