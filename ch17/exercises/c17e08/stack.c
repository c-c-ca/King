#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node {
    int value;
    struct node *next;
};

/* external variables */
struct node *top = NULL;

void stack_underflow(void);
void stack_overflow(void);

void make_empty(void)
{
    struct node *temp;

    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

bool is_empty(void)
{
    return top == NULL;
}

bool push(int i)
{
    struct node *new_node;
   
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        return false;

    new_node->value = i;
    new_node->next = top;
    top = new_node;

    return true;
}

int pop(void)
{
    struct node *temp;
    int i;

    if (is_empty())
        stack_underflow();

    i = top->value;
    temp = top;
    top = top->next;
    free(temp);

    return i;
}

void stack_underflow(void)
{
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
}

void stack_overflow(void)
{
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}
