#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60
#define LEN(a) (sizeof(a) / sizeof(a[0]))

char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;
int num_lines = 0;

void clear_line(void)
{
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    if (num_words > 0) {
        line[line_len] = ' ';
        line[line_len+1] = '\0';
        line_len++;
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces, spaces_to_insert[num_words-1], i, j;

    extra_spaces = MAX_LINE_LEN - line_len;
    for (i = 0; i < num_words - 1; i++)
        extra_spaces -= spaces_to_insert[i] = extra_spaces / (num_words - 1 - i);

    for (i = 0; i < line_len; i++) {
        if (line[i] != ' ')
            putchar(line[i]);
        else {
            for (j = 1; j <= spaces_to_insert[num_lines % 2 == 0 ? LEN(spaces_to_insert) - num_words + 1 : num_words - 2] + 1; j++)
                putchar(' ');
            num_words--;
        }
    }
    putchar('\n');
    num_lines++;
}

void flush_line(void)
{
    if (line_len > 0)
        puts(line);
}
