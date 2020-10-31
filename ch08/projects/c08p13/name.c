#include <stdio.h>

#define MAX_NAME 20

int main(void)
{
    char ch, first_initial, last_name[MAX_NAME];
    int i, len = 0;

    printf("Enter your first and last name: ");
    scanf(" %c", &first_initial);

    while (getchar() != ' ')
        ;

    while ((last_name[len] = getchar()) == ' ')
        ;
    len++;

    while (len < MAX_NAME && (ch = getchar()) != ' ' && ch != '\n')
        last_name[len++] = ch;

    for (i = 0; i < len;)
        putchar(last_name[i++]);
    printf(", %c.\n", first_initial);

    return 0;
}
