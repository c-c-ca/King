#include <stdio.h>

int main(void)
{
    char ch, first_initial;

    printf("Enter your first and last name: ");
    scanf(" %c", &first_initial);

    while (getchar() != ' ')
        ;

    while ((ch = getchar()) == ' ')
        ;
    
    do {
        putchar(ch);
    } while ((ch = getchar()) != ' ' && ch != '\n');

    printf(", %c.\n", first_initial);

    return 0;
}
