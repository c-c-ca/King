#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LINE 80

int read_line(char str[], int n);
int read_line_a(char str[], int n);
int read_line_b(char str[], int n);
int read_line_c(char str[], int n);
int read_line_d(char str[], int n);

int main(int argc, char *argv[])
{
    char ch, line[MAX_LINE];

    if (argc < 2 || (ch = *++argv[1]) < 'a' || ch > 'd') {
        printf("Usage: readline -[a-d]\n");
        exit(EXIT_FAILURE);
    }

    if ('a' <= ch && ch <= 'c') {
        switch (ch) {
            case 'a': read_line_a(line, MAX_LINE); break;
            case 'b': read_line_b(line, MAX_LINE); break;
            case 'c': read_line_c(line, MAX_LINE); break;
        }
        printf("%s\n", line);
    } else {
        printf("After call #1: ");
        read_line_d(line, MAX_LINE);
        printf("%s\n", line);

        printf("After call #2: ");
        read_line_d(line, MAX_LINE);
        printf("%s\n", line);
    }

    exit(EXIT_SUCCESS);
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

int read_line_a(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i == 0 && isspace(ch))
            ; /* ignore */
        else if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

int read_line_b(char str[], int n)
{
    int ch, i = 0;

    while (!isspace(ch = getchar()))
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}


int read_line_c(char str[], int n)
{
    int ch, i = 0;

    do {
        ch = getchar();
        if (i < n)
            str[i++] = ch;
    } while (ch != '\n');
    str[i] = '\0';
    return i;
}

int read_line_d(char str[], int n)
{
    int ch, i;

    for (i = 0; i < n; i++) {
        ch = getchar();
        if (ch == '\n')
            break;
        str[i] = ch;
    }
    str[i] = '\0';
    return i;
}
