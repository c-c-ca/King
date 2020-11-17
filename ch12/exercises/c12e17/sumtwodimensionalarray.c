#include <stdio.h>

#define LEN 5

int sum_two_dimensional_array(const int a[][LEN], int n);

int main(void)
{
    const int a[][LEN] = {{24, 31, 87, 12, 25},
                          {92, 11, 36, 10, 73}};

    printf("Sum: %d\n", sum_two_dimensional_array(a, sizeof(a) / sizeof(a[0])));

    return 0;
}

int sum_two_dimensional_array(const int a[][LEN], int n)
{
    const int *p = a[0];
    int sum = 0;

    while (p < *(a + n))
        sum += *p++;
    return sum;
}
