/* a pointer to f2 is passed to f1; f2 is invoked inside of f1 until f2 returns 0 */
#include <stdio.h>

int f1(int (*f1)(int));
int f2(int i);

int main(void)
{
    printf("Answer: %d\n", f1(f2)); /* Prints "Answer: 3" */
    return 0;
}

int f1(int (*f)(int))
{
    int n = 0;

    while ((*f)(n)) n++;
    return n;
}

int f2(int i)
{
    return i * i + i - 12;
}
