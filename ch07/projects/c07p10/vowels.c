#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int n = 0;
    char ch;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n')
        switch (tolower(ch)) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                n++; break;
        }

    printf("Your sentence contains %d vowels.\n", n);

    return 0;
}