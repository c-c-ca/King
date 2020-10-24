#include <stdio.h>

int main(void)
{
    int i, n, sum;

    n = 0;
    sum = 0;
    while (n < 10) {
        scanf("%d", &i);
        if (i == 0)
            goto loop_end;
        sum += i;
        n++;
        loop_end: ;  /* null statement */
    }

    printf("%d\n", sum);

    return 0;
}
