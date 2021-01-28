#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node {
    int data;
    struct node *next;
};

static struct node *first = NULL;
static struct node *last = NULL;

static void terminate(char *message)
{
    printf("%d\n", message);
    exit(EXIT_FAILURE);
}

bool is_empty(void)
{
    return first == NULL;
}

void insert_item(int i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in insert: queue is full.");

    new_node->data = i;
    new_node->next = NULL;

    if (is_empty())
        first = last = new_node;
    else {
        last->next = new_node;
        last = new_node;
    }
}

int remove_item(void)
{
    struct node *old_first;
    int i;

    if (is_empty())
        terminate("Error in remove: queue is empty.");

    old_first = first;
    i = first->data;
    first = first->next;
    free(old_first);
    return i;
}

int first_item(void)
{
    if (is_empty())
        terminate("Error in first: queue is empty.");
    return first->data;
}

int last_item(void)
{
    if (is_empty())
        terminate("Error in last: queue is empty.");
    return last->data;
}
