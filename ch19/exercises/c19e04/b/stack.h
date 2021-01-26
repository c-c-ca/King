#ifndef STACK_H
#define STACK_H

#include <stdbool.h>   /* C99 only */

struct node {
    int data;
    struct node *next;
};

typedef struct node *Stack;

void make_empty(Stack *s);
bool is_empty(const Stack *s);
bool is_full(const Stack *s);
void push(Stack *s, int i);
int pop(Stack *s);

#endif
