#include <stdio.h>

#define N 10

void find_two_largest(const int *a, int n, int *largest,
                      int *second_largest);

int main(void)
{
    int b[N], i, largest, second_largest;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &b[i]);

    find_two_largest(b, N, &largest, &second_largest);

    printf("Largest: %d\n", largest);
    printf("Second largest: %d\n", second_largest);

    return 0;
}

void find_two_largest(const int *a, int n, int *largest,
                      int *second_largest) {
    const int *p;

    if (*a > *(a + 1)) {
        *largest = *a;
        *second_largest = *(a + 1);
    } else {
        *largest = *(a + 1);
        *second_largest = *a;
    }

    for (p = a + 2; p < a + n; p++)
        if (*p > *largest) {
            *second_largest = *largest;
            *largest = *p;
        } else if (*p > *second_largest)
            *second_largest = *p;
}
