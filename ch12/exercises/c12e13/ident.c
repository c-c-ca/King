#include <stdio.h>

#define N 10

int main(void)
{
    double *p, ident[N][N];
    int num_zeros = N;

    for (p = ident[0]; p < ident[N]; p++)
        if (num_zeros == N) {
            *p = 1.0;
            num_zeros = 0;
        } else {
            *p = 0.0;
            num_zeros++;
        }

    return 0;
}
