#include <stdio.h>

#define MAX_SENTENCE 100

int main(void)
{
    char ch, sentence[MAX_SENTENCE];
    int i, start, end;

    for (end = 0;
         end < MAX_SENTENCE && 
         (ch = getchar()) != '.' && ch != '!' && ch != '?'; 
         end++)
         sentence[end] = ch;

    for (; end > 0; end = start) {
        /* find the end of the word */
        for (; end > 0 && sentence[--end] == ' ' ;)
            putchar(' ');

        /* find the beginning of the word */
        for (start = end; start > 0 && sentence[start - 1] != ' '; start--)
            ;
        
        /* print the word */
        for (i = start; i <= end; i++)
            putchar(sentence[i]);
    }

    printf("%c\n", ch);

    return 0;
}
