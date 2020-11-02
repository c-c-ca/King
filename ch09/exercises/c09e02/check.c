#include <stdio.h>

int check(int x, int y, int n);
int main(void)
{
    printf("%d\n", check(3, 7, 7));
    return 0;
}

int check(int x, int y, int n)
{
    return (0 <= x && x < n) && (0 <= y && y < n);
}
