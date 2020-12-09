#include <stdio.h>

#define NAME_LEN 40

void reverse_name(char *name);
int read_line(char str[], int n);

int main(void)
{
    char name[NAME_LEN+1];

    printf("Enter your first and last name: ");
    read_line(name, NAME_LEN);
    reverse_name(name);
    printf("%s\n", name);

    return 0;
}

void reverse_name(char *name)
{
    char first_initial, *p = name;

    while ((first_initial = *p++) == ' ')
        ;

    while (*p++ != ' ')
        ;

    while ((*name = *p++) == ' ')
        ;

    while (*p != ' ' && *p != '\0')
        *++name = *p++;

    *++name = ' ';
    *++name = first_initial;
    *++name = '.';
    *++name = '\0';
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
        str[i++] = ch;
    str[i] = '\0';
    return i;
}
