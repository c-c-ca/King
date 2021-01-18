#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct word {
    struct word *next;
    char chars[];
};

struct word *line = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
    struct word *temp;

    while (line != NULL) {
        temp = line->next;
        free(line);
        line = temp;
    }

    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    struct word *new_word, *p;
    int word_len = strlen(word);
    
    if ((new_word = malloc(sizeof(struct word) + word_len + 1)) == NULL) {
        printf("Error: malloc failed in add_word\n");
        exit(EXIT_FAILURE);
    }
 
    new_word->next = NULL;
    strcpy(new_word->chars, word);

    if ((p = line) != NULL) {
        while (p->next != NULL)
            p = p->next;
        p->next = new_word;
        line_len++;
    } else
        line = new_word;
    
    line_len += word_len;
    num_words++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    struct word *p;
    int i, extra_spaces, spaces_to_insert;

    extra_spaces = MAX_LINE_LEN - line_len;
    for (p = line; p != NULL; p = p->next) {
        printf(p->chars);
        if (p->next != NULL) {
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (i = 1; i <= spaces_to_insert + 1; i++)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }
    putchar('\n');
}

void flush_line(void)
{
    struct word *p;

    for (p = line; p != NULL; p = p->next)
        printf("%s%c", p->chars, p->next != NULL ? ' ' : '\n');
}
