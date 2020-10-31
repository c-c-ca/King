#include <stdio.h>

#define N 15

int main(void)
{
    char phone_num[N];
    int i;

    printf("Enter phone number: ");
    for (i = 0; i < N && (phone_num[i++] = getchar()) != '\n';)
        ;
    
    printf("In numeric form: ");
    for (i = 0; i < N && phone_num[i] != '\n'; i++)
        if ('A' <= phone_num[i] && phone_num[i] <= 'Z')
            putchar('2' + (phone_num[i] - 'A') / 3);
        else
            putchar(phone_num[i]);
    putchar('\n');

    return 0;
}
